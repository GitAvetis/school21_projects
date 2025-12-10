namespace ProjectTeam01.domain.Characters.Behavior
{
    internal class ZombieBehavior(Enemy enemy, IMapQuery map) : EnemyBehavior(enemy, map)
    {
        public override void Tick(Hero hero)
        {
            int distanceToHero = DistanceToHero(hero);
            if (distanceToHero <= Enemy.HostilityLevel)
            {
                MoveTowards(hero);
                Enemy.IsTriggered = true;
            }
            else
            {
                MoveRandom();
            }

            if (distanceToHero == 1) 
                Attack(hero);
            DropLoot();

        }

    }
}
