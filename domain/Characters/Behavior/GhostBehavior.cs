namespace ProjectTeam01.domain.Characters.Behavior
{
    internal class GhostBehavior(Enemy enemy, IMapQuery map) : EnemyBehavior(enemy, map)
    {
        public override void Tick(Hero hero)
        {
            int distanceToHero = DistanceToHero(hero);
            if (distanceToHero <= Enemy.HostilityLevel)
            {
                MoveTowards(hero);
                Enemy.IsTriggered = true;
                if (Enemy is Ghost ghost)
                {
                    ghost.IsInvisible = false;
                }
            }
            else
            {
                Teleport();
            }
            if (distanceToHero == 1)
                Attack(hero);
            DropLoot();
        }

        private bool Teleport()
        {
            if (!Enemy.IsTriggered)
            {
                for (int attempts = 0; attempts < 10; attempts++)
                {
                    int dx = random.Next(-3, 4);//может быть передавать размеры комнаты, а не хардкодить 
                    int dy = random.Next(-3, 4);//значения диапазона прыжков
                    if (TryMoveTo(Enemy.PosX + dx, Enemy.PosY + dy)) return true;
                }
            }
            return false;
        }
    }
}
