namespace TicTacToe.Web.DTO
{
    public class ErrorResponseDto
    {
        public required string Error { get; set; }
        public required GameDto Game { get; set; }
    }
}
