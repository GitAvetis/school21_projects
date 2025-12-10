namespace ProjectTeam01.domain
{
    internal interface IGameObject
    {
        int PosX { get; set; }
        int PosY { get; set; }
        void MoveTo(int x, int y);
    }
}
