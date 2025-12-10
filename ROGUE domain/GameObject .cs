namespace ProjectTeam01.domain
{

    internal abstract class GameObject : IGameObject
    {
        public int PosX { get; set; }
        public int PosY { get; set; }

        protected GameObject(int x, int y)
        {
            PosX = x;
            PosY = y;
        }

        public virtual void MoveTo(int x, int y)
        {
            PosX = x;
            PosY = y;
        }
    }
}
