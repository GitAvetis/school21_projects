namespace ProjectTeam01.domain.Characters
{
    internal class Snake : Enemy
    {
        public Snake(int posX, int posY) : base(EnemyTypeEnum.Snake, posX, posY)
        {
            ActualHp = 100;
            BaseAgility = 4;
            BaseStrength = 1;
            HostilityLevel = 3;
        }

    }
}
