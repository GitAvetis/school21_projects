using System.Text.Json.Serialization;
using TicTacToe.Datasource;

namespace TicTacToe.Di
{
    public class Configuration
    {
        public static void ConfigureServices(WebApplicationBuilder builder)
        {
            builder.Services.AddSingleton<IGameRepository, InMemoryGameRepository>();
            builder.Services.AddScoped<IGameService, GameService>();
            builder.Services
                .AddControllers()
                .AddJsonOptions(options =>
                {
                    options.JsonSerializerOptions.Converters
                    .Add(new JsonStringEnumConverter());
                });
        }
    }
}
