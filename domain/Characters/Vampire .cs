namespace ProjectTeam01.domain.Characters
{
    internal class Vampire : Enemy
    {
        public Vampire(int posX, int posY) : base(EnemyTypeEnum.Vampire, posX, posY)
        {
            ActualHp = 150;
            BaseAgility = 3;
            BaseStrength = 2;
            HostilityLevel = 3;
        }
    }
}
