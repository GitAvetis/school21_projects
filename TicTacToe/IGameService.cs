using TicTacToe.Domain.Models;

namespace TicTacToe
{
    public interface IGameService
    {
        GameSessionModel CreateGame(int size);
        GameSessionModel GetGame(Guid id);
        MoveStatus MakeMove(Guid id, int x, int y, bool vsAi);
    }
}
