namespace ProjectTeam01.domain.Characters
{
    internal class Zombie : Enemy
    {
        public Zombie(int posX, int posY) : base(EnemyTypeEnum.Zombie, posX, posY)
        {
            ActualHp = 150;
            BaseAgility = 1;
            BaseStrength = 2;
            HostilityLevel = 2;
        }
    }
}
