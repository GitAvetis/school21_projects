using ProjectTeam01.domain.Items;

namespace ProjectTeam01.domain.Characters.Behavior
{
    internal class HeroBehavior(Hero hero, IMapQuery map) : CharacterBehavior(hero)
    {
        protected readonly Hero _hero = hero;
        protected readonly IMapQuery Map = map;
        protected readonly Random random = new();


        public bool TryPickupItem(Item item)
        {
            if (item.PosX == _hero.PosX && item.PosY == _hero.PosY)
            {
                return _hero.HeroBackpack.Add(item);
            }
            else
                return false;
        }

        public bool DropItem(Item item)
        {
            if (!_hero.HeroBackpack.AllItems.Contains(item))
                return false;
            List<(int x, int y)> neighbors = new();//список соседних пустых ячеек
            for (int dx = -1; dx <= 1; dx++)
                for (int dy = -1; dy <= 1; dy++)
                    if ((dx != 0 || dy != 0) && !Map.IsOccupied(_hero.PosX + dx, _hero.PosY + dy))
                        neighbors.Add((_hero.PosX + dx, _hero.PosY + dy));

            if (neighbors.Count == 0)
                return false;

            (int newX, int newY) = neighbors[random.Next(neighbors.Count)];//выбираем случайный кортеж из списка соседних пустых ячеек
            _hero.HeroBackpack.DropItem(item);
            item.MoveTo(newX, newY);
            return true;
        }

        protected void Attackenemies(List<Enemy> enemies)
        {
            int dx, dy;
            foreach (var enemy in enemies)
            {
                dx = Math.Abs(enemy.PosX - _hero.PosX);
                dy = Math.Abs(enemy.PosY - _hero.PosY);
                if (dx <= 1 && dy <= 1)
                {
                    Attack(enemy);
                }
            }
        }

        public void Tick(List<Enemy> enemies, List<Item> items)//основной игровой цикл для героя
        {
            Attackenemies(enemies);
            foreach (var item in items)
            {
                TryPickupItem(item);
            }
        }
    }
}
