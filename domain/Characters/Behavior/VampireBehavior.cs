namespace ProjectTeam01.domain.Characters.Behavior
{
    internal class VampireBehavior(Enemy enemy, IMapQuery map) : EnemyBehavior(enemy, map)
    {
        private int _hpDebuffTicksCounter = 3;
        private int _hpDebuffValue = 0;
        private bool EvadedFirstAttack { get; set; } = false;
        private bool DebuffIsAtive { get; set; } = false;

        public override void Tick(Hero hero)
        {
            _hpDebuffTicksCounter--;

            if (_hpDebuffTicksCounter <= 0)
            {
                if (DebuffIsAtive)
                    RemoveHpDebuff(hero);
            }

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
            {
                if (Attack(hero))
                    SpecialEffectOnAttack(hero);
            }

            if (Enemy.IsDead)
            {
                DebuffIsAtive = false;
                hero.MaxHpDecrease(_hpDebuffValue, DebuffIsAtive);
            }
            DropLoot();

        }

        public override void TakeDamage(int damageValue)
        {
            if (!EvadedFirstAttack)
                EvadedFirstAttack = true;
            else Enemy.TakeDamage(damageValue);
        }

        private void RemoveHpDebuff(Hero hero)
        {
            DebuffIsAtive = false;
            hero.MaxHpDecrease(_hpDebuffValue, DebuffIsAtive);
        }

        private void HpDebuff(Hero hero)
        {
            if (!DebuffIsAtive)
            {
                _hpDebuffValue = Enemy.BaseStrength / 2;
                DebuffIsAtive = true;
                hero.MaxHpDecrease(_hpDebuffValue, DebuffIsAtive);
            }
            _hpDebuffTicksCounter = 3;
        }

        protected override void SpecialEffectOnAttack(Hero hero)
        {
            if (Chance(30))
                HpDebuff(hero);
        }
    }
}
