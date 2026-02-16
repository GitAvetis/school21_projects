using System.Text.Json.Serialization;
using TicTacToe.Datasource;
using TicTacToe.Domain;

namespace TicTacToe.Di
{
    public class Configuration
    {
        public static void ConfigureServices(WebApplicationBuilder builder)
        {
            builder.Services.AddSingleton<IGameRepository, InMemoryGameRepository>();
            builder.Services.AddScoped<IGameService, GameService>();
            builder.Services.AddScoped<IServiceDomain, GameDomainService>();
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
