using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectTeam01.domain.generation;

/// Реализация IMapQuery на основе данных Level
/// Предоставляет быстрый доступ к информации о карте для движения и размещения сущностей
public class LevelMapQuery : IMapQuery
{
    private readonly Level _level;
    private readonly HashSet<Position> _occupiedPositions;
    
    public LevelMapQuery(Level level)
    {
        _level = level ?? throw new ArgumentNullException(nameof(level));
        _occupiedPositions = new HashSet<Position>();
    }
    
    /// Проверяет, можно ли пройти по данной позиции
    public bool IsWalkable(int x, int y)
    {
        var pos = new Position(x, y);
        
        foreach (var room in _level.Rooms)
        {
            if (IsPositionInRoom(pos, room))
                return true;
        }
        
        foreach (var corridor in _level.Corridors)
        {
            if (corridor.Cells != null && corridor.Cells.Contains(pos))
                return true;
        }
        
        return false;
    }
    
    /// Проверяет, занята ли позиция другой сущностью
    public bool IsOccupied(int x, int y)
    {
        return _occupiedPositions.Contains(new Position(x, y));
    }
    
    /// Вычисляет расстояние между двумя точками
    public int GetDistance(int x1, int y1, int x2, int y2)
    {
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
    }
    
    /// Обновляет все занятые позиции
    /// Используется при загрузке уровня или полном обновлении состояния
    public void UpdateOccupiedPositions(IEnumerable<Position> entities)
    {
        _occupiedPositions.Clear();
        if (entities != null)
        {
            foreach (var pos in entities)
            {
                _occupiedPositions.Add(pos);
            }
        }
    }
    
    /// Добавляет занятую позицию
    /// Используется при размещении новой сущности или движении существующей
    public void AddOccupiedPosition(Position pos)
    {
        _occupiedPositions.Add(pos);
    }
    
    /// Удаляет занятую позицию
    /// Используется при удалении сущности или движении существующей
    public void RemoveOccupiedPosition(Position pos)
    {
        _occupiedPositions.Remove(pos);
    }
    
    /// Проверяет, находится ли позиция в комнате
    private bool IsPositionInRoom(Position pos, Room room)
    {
        return pos.X >= room.TopLeft.X && pos.X <= room.BottomRight.X &&
               pos.Y >= room.TopLeft.Y && pos.Y <= room.BottomRight.Y;
    }
}

