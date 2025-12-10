namespace ProjectTeam01.domain.Characters
{
    internal class Enemy : Character
    {
        public Enemy(EnemyTypeEnum enemyType, int posX, int posY) : base(posX, posY)
        {
            EnemyType = enemyType;
            IsTriggered = false;
        }

        private int _actualHp;

        public override int ActualHp
        {
            get
            {
                return _actualHp;
            }
            protected set
            {
                if (value <= 0)
                {
                    _actualHp = 0;
                }
                else
                {
                    _actualHp = value;
                }
            }
        }

        public enum EnemyTypeEnum
        {
            Zombie,
            Vampire,
            Ghost,
            Ogre,
            Snake
        }

        public EnemyTypeEnum EnemyType { get; }
        public bool IsTriggered { get; set; }
        public int HostilityLevel { get; set; }//враждебность 
    }
}
