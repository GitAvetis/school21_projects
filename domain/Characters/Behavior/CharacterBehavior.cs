namespace ProjectTeam01.domain.Characters.Behavior
{
    internal abstract class CharacterBehavior : ICharacterBehavior
    {
        protected readonly Character Сharacter;

        public CharacterBehavior(Character сharacter)
        {
            Сharacter = сharacter;
        }

        public virtual void TakeDamage(int damageValue)
        {
            Сharacter.TakeDamage(damageValue);
        }

        public bool Attack(Character target)
        {
            if (BattleService.HitSuccess(Сharacter.BaseAgility, target.BaseAgility))
            {
                target.TakeDamage(Сharacter.BaseStrength);
                return true;
            }
            else return false;
        }
    }
}
