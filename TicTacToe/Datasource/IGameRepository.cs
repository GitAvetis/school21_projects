using TicTacToe.Domain.Models;

namespace TicTacToe.Datasource
{
    public interface IGameRepository
    {
        GameSessionModel Create(int size);
        GameSessionModel? Get(Guid id);
        void Update(GameSessionModel session);
    }
}
