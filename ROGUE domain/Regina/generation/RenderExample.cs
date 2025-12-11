using System;

namespace ProjectTeam01.domain.generation;

/// Пример использования LevelRenderer для отрисовки уровня
/// Этот класс можно использовать для тестирования отрисовки
public static class RenderExample
{
    /// Генерирует и отрисовывает уровень
    public static void GenerateAndRender(int? seed = null)
    {
        var generator = new LevelGenerator(seed);
        var level = generator.GenerateLevel();
        
        LevelRenderer.Render(level);
        
        Console.WriteLine();
        Console.WriteLine($"Level Number: {level.LevelNumber}");
        Console.WriteLine($"Rooms Count: {level.Rooms.Count}");
        Console.WriteLine($"Corridors Count: {level.Corridors.Count}");
        Console.WriteLine($"Start Position: ({level.StartPosition.X}, {level.StartPosition.Y})");
        Console.WriteLine($"Exit Position: ({level.ExitPosition.X}, {level.ExitPosition.Y})");
        Console.WriteLine();
        Console.WriteLine("Press any key to exit...");
        Console.ReadKey();
    }
}

