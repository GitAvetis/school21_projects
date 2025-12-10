using ProjectTeam01.domain.Effects;

namespace ProjectTeam01.domain.Characters.Behavior
{
    internal class SnakeBehavior(Enemy enemy, IMapQuery map) : EnemyBehavior(enemy, map)
    {
        private int dx = 1;
        private int dy = 1;

        public override void Tick(Hero hero)
        {
            ChangeDirection();
            int distanceToHero = DistanceToHero(hero);
            if (distanceToHero <= Enemy.HostilityLevel)// можно убрать, если не будем применять логику агрессии
                Enemy.IsTriggered = true;
            if (distanceToHero == 1)
            {
                if (Attack(hero)) SpecialEffectOnAttack(hero);
            }
            DropLoot();

        }

        private void ChangeDirection()//можно придумать что-то поинтереснее
        {
            int attempts = 8;
            while (attempts-- > 0)
            {
                if (Chance(50)) dx *= -1;
                if (Chance(50)) dy *= -1;

                if (TryMoveTo(Enemy.PosX + dx, Enemy.PosY + dy))
                    break;
            }
        }

        protected static void FallHeroToSleep(Hero hero)
        {
            if (hero.IsHeroSleep) return;
            ActiveEffect sleep = new(ActiveEffect.EffectTypeEnum.Sleep);
            hero.ActiveEffectManager.AddActiveEffect(sleep);
        }

        protected override void SpecialEffectOnAttack(Hero hero)
        {
            if (Chance(30))
                FallHeroToSleep(hero);
        }
    }
}
