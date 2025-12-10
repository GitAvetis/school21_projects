namespace ProjectTeam01.domain.Characters.Behavior
{
    internal interface ICharacterBehavior
    {
        public bool Attack(Character сharacter);
        public void TakeDamage(int damageValue);
    }
}
