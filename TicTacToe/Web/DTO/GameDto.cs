using TicTacToe.Domain.Models;

namespace TicTacToe.Web.DTO
{
    public class GameDto
    {
        public Guid Id { get; set; }
        public CellState CurrentPlayer { get; set; }
        public GameResult Result { get; set; }
        //public string[][] Field { get; set; } = default!;
        public string[] PrettyField { get; set; } = default!;
    }
}
