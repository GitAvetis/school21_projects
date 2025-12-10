namespace ProjectTeam01.domain.Characters
{
    internal class Ogre : Enemy
    {
        public Ogre(int posX, int posY) : base(EnemyTypeEnum.Ogre, posX, posY)
        {
            ActualHp = 175;
            BaseAgility = 1;
            BaseStrength = 4;
            HostilityLevel = 2;
        }
    }
}
