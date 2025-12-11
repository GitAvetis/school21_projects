using System.Collections.Generic;

namespace ProjectTeam01.domain.generation;

/// Представляет уровень подземелья с комнатами и коридорами
public class Level
{
    public List<Room> Rooms { get; set; }
    public List<Corridor> Corridors { get; set; }
    public int LevelNumber { get; set; }
    public Position ExitPosition { get; set; }
    public Position StartPosition { get; set; }
    public Level()
    {
        Rooms = new List<Room>();
        Corridors = new List<Corridor>();
        ExitPosition = new Position();
        StartPosition = new Position();
    }
}

