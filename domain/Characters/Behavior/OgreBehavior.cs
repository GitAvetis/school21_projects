namespace ProjectTeam01.domain.Characters.Behavior
{
    internal class OgreBehavior(Enemy enemy, IMapQuery map) : EnemyBehavior(enemy, map)
    {
        private int _restTicksCounter = 0;
        private bool _isResting = false;
        private bool _isCounterattackReady = false;

        public override void Tick(Hero hero)
        {
            int distanceToHero = DistanceToHero(hero);

            if (_isResting)
            {
                if (distanceToHero == 1 && _isCounterattackReady)
                {
                    Attack(hero);
                    _isCounterattackReady = false;
                }

                _restTicksCounter--;
                if (_restTicksCounter <= 0) _isResting = false;

                return;
            }

            if (distanceToHero <= Enemy.HostilityLevel)
            {
                if (MoveTwice(hero))
                    Enemy.IsTriggered = true;
                else if (MoveTowards(hero))
                    Enemy.IsTriggered = true;
                else MoveRandom();
            }
            else
            {
                MoveRandom();
            }

            if (distanceToHero == 1)
            {
                _isResting = true;
                _restTicksCounter = 2;
                Attack(hero);
            }
            DropLoot();
        }

        protected bool MoveTwice(Hero hero)
        {
            int dx = hero.PosX > Enemy.PosX ? 2 :
                     hero.PosX < Enemy.PosX ? -2 : 0;

            int dy = hero.PosY > Enemy.PosY ? 2 :
                     hero.PosY < Enemy.PosY ? -2 : 0;

            return TryMoveTo(Enemy.PosX + dx, Enemy.PosY + dy);
        }

        public override void TakeDamage(int damageValue)
        {
            Enemy.TakeDamage(damageValue);
            _isCounterattackReady = true;
        }

    }
}
