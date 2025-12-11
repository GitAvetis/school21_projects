using System;
using System.Linq;

namespace ProjectTeam01.domain.generation;

/// Класс для отрисовки уровня в консоль
public static class LevelRenderer
{
    /// Отрисовывает уровень в консоль
    public static void Render(Level level)
    {
        // Создаем карту
        char[,] map = new char[GenerationConstants.MapHeight, GenerationConstants.MapWidth];
        
        // Инициализируем карту пробелами
        for (int y = 0; y < GenerationConstants.MapHeight; y++)
        {
            for (int x = 0; x < GenerationConstants.MapWidth; x++)
            {
                map[y, x] = ' ';
            }
        }
        
        // Отрисовываем коридоры (сначала, чтобы они были под комнатами)
        foreach (var corridor in level.Corridors)
        {
            RenderCorridor(map, corridor);
        }
        
        // Отрисовываем комнаты
        foreach (var room in level.Rooms)
        {
            RenderRoom(map, room);
        }
        
        // Отрисовываем двери
        foreach (var room in level.Rooms)
        {
            RenderDoors(map, room);
        }
        
        // Отрисовываем стартовую позицию
        if (level.StartPosition.X > 0 && level.StartPosition.Y > 0)
        {
            map[level.StartPosition.Y, level.StartPosition.X] = 'S';
        }
        
        // Отрисовываем конечную позицию
        if (level.ExitPosition.X > 0 && level.ExitPosition.Y > 0)
        {
            map[level.ExitPosition.Y, level.ExitPosition.X] = 'E';
        }
        
        // Выводим карту в консоль
        PrintMap(map);
    }
    
    /// Отрисовывает комнату на карте
    private static void RenderRoom(char[,] map, Room room)
    {
        int top = room.TopLeft.Y;
        int left = room.TopLeft.X;
        int bottom = room.BottomRight.Y;
        int right = room.BottomRight.X;
        
        // Отрисовываем стены и пол
        for (int y = top; y <= bottom; y++)
        {
            for (int x = left; x <= right; x++)
            {
                // Проверяем границы
                if (y < 0 || y >= GenerationConstants.MapHeight || 
                    x < 0 || x >= GenerationConstants.MapWidth)
                    continue;
                
                // Стены
                if (y == top || y == bottom || x == left || x == right)
                {
                    map[y, x] = '#';
                }
                // Пол
                else
                {
                    // Если это не коридор, рисуем пол
                    if (map[y, x] == ' ' || map[y, x] == '.')
                    {
                        map[y, x] = '.';
                    }
                }
            }
        }
    }
    
    /// Отрисовывает коридор на карте
    private static void RenderCorridor(char[,] map, Corridor corridor)
    {
        if (corridor.Cells == null || corridor.Cells.Count == 0)
            return;
        
        // Отрисовываем все клетки коридора
        foreach (var cell in corridor.Cells)
        {
            // Проверяем границы
            if (cell.Y >= 0 && cell.Y < GenerationConstants.MapHeight && 
                cell.X >= 0 && cell.X < GenerationConstants.MapWidth)
            {
                // Рисуем коридор ('.' для пола коридора)
                if (map[cell.Y, cell.X] == ' ')
                {
                    map[cell.Y, cell.X] = '.';
                }
            }
        }
    }
    
    /// Отрисовывает двери комнаты
    private static void RenderDoors(char[,] map, Room room)
    {
        if (room.Doors == null)
            return;
        
        foreach (var door in room.Doors)
        {
            // Проверяем, что дверь инициализирована (X и Y не равны 0 по умолчанию)
            // или используем более надежную проверку через сравнение с дефолтным Position
            if (door.X > 0 && door.Y > 0)
            {
                // Проверяем границы
                if (door.Y >= 0 && door.Y < GenerationConstants.MapHeight && 
                    door.X >= 0 && door.X < GenerationConstants.MapWidth)
                {
                    // Дверь обозначаем символом '+'
                    // Но только если это не стартовая или конечная позиция
                    if (map[door.Y, door.X] != 'S' && map[door.Y, door.X] != 'E')
                    {
                        map[door.Y, door.X] = '+';
                    }
                }
            }
        }
    }
    
    /// Выводит карту в консоль
    private static void PrintMap(char[,] map)
    {
        Console.Clear();
        Console.WriteLine("=== DUNGEON LEVEL ===");
        Console.WriteLine();
        
        for (int y = 0; y < GenerationConstants.MapHeight; y++)
        {
            for (int x = 0; x < GenerationConstants.MapWidth; x++)
            {
                Console.Write(map[y, x]);
            }
            Console.WriteLine();
        }
        
        Console.WriteLine();
        Console.WriteLine("Legend:");
        Console.WriteLine("  # = Wall");
        Console.WriteLine("  . = Floor");
        Console.WriteLine("  + = Door");
        Console.WriteLine("  S = Start");
        Console.WriteLine("  E = Exit");
    }
}

