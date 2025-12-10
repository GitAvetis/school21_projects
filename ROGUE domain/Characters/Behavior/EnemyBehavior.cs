using ProjectTeam01.domain.Items;

namespace ProjectTeam01.domain.Characters.Behavior
{
    internal abstract class EnemyBehavior(Enemy enemy, IMapQuery map) : CharacterBehavior(enemy)
    {
        protected readonly Enemy Enemy = enemy;
        protected readonly IMapQuery Map = map;
        protected static readonly Random random = new();

        public abstract void Tick(Hero hero);

        protected virtual void SpecialEffectOnAttack(Hero hero) { }

        protected bool MoveRandom()
        {
            for (int attempts = 0; attempts < 10; attempts++)
            {
                int dx = random.Next(-1, 2);
                int dy = random.Next(-1, 2);
                if (TryMoveTo(Enemy.PosX + dx, Enemy.PosY + dy)) return true;
            }
            return false;
        }

        protected bool MoveTowards(Hero hero)
        {
            int dx = hero.PosX > Enemy.PosX ? 1 :
                     hero.PosX < Enemy.PosX ? -1 : 0;

            int dy = hero.PosY > Enemy.PosY ? 1 :
                     hero.PosY < Enemy.PosY ? -1 : 0;

            return TryMoveTo(Enemy.PosX + dx, Enemy.PosY + dy);
        }

        protected int DistanceToHero(Hero hero)
        {
            return Map.GetDistance(Enemy.PosX, Enemy.PosY, hero.PosX, hero.PosY);
        }

        protected bool TryMoveTo(int x, int y)
        {
            if (!Map.IsOccupied(x, y))
            {
                Enemy.MoveTo(x, y);
                return true;
            }
            else
                return false;
        }

        static protected bool Chance(int percent)
        {
            return random.Next(0, 100) < percent;
        }

        public Treasure? DropLoot()
        {
            if (!Enemy.IsDead) return null;

            return new Treasure(Enemy.PosX, Enemy.PosY, Map.GetMapLevel());
        }

    }
}
