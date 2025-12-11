using System.Collections.Generic;

namespace ProjectTeam01.domain.generation;

/// Интерфейс для запросов к карте уровня
/// Используется для движения персонажей и размещения сущностей
public interface IMapQuery
{
    /// Проверяет, можно ли пройти по данной позиции (в комнате или коридоре)
    bool IsWalkable(int x, int y);
    
    /// Проверяет, занята ли позиция другой сущностью
    /// Использует внутреннее состояние для быстрой проверки
    bool IsOccupied(int x, int y);
    
    /// Вычисляет расстояние между двумя точками
    int GetDistance(int x1, int y1, int x2, int y2);
    
    /// Обновляет все занятые позиции (используется при загрузке уровня)
    void UpdateOccupiedPositions(IEnumerable<Position> entities);
    
    /// Добавляет занятую позицию (используется при размещении/движении сущности)
    void AddOccupiedPosition(Position pos);
    
    /// Удаляет занятую позицию (используется при удалении/движении сущности)
    void RemoveOccupiedPosition(Position pos);
}

