namespace ProjectTeam01.domain.Characters.Behavior
{
    internal interface IMapQuery
    {
        bool IsOccupied(int x, int y);
        int GetDistance(int x1, int y1, int x2, int y2);
        int GetMapLevel();
    }
}
