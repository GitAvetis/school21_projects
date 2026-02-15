using TicTacToe.Datasource;
using TicTacToe.Domain.Ai;
using TicTacToe.Domain.Models;

namespace TicTacToe
{
    public class GameService : IGameService
    {
        private readonly IGameRepository _repository;
        private readonly MiniMax _miniMax;

        public GameService(IGameRepository repository)
        {
            _repository = repository;
            _miniMax = new MiniMax();
        }

        public GameSessionModel CreateGame(int size)
        {
            return _repository.Create(size);
        }

        public GameSessionModel GetGame(Guid id)
        {
            return _repository.Get(id);
        }

        public MoveStatus MakeMove(Guid id, int x, int y, bool vsAi)
        {
            GameSessionModel session = _repository.Get(id);
            if (session == null)
                return MoveStatus.StateError;

            MoveStatus moveStatus = session.TryMakeMove(x, y);

            if (moveStatus == MoveStatus.Sucsess && vsAi && session.Result == GameResult.InProgress)
            {
                (int aiX, int aiY) = _miniMax.GetBestMove(session.CurrentPlayer, session.Field.GetFieldCopy());
                session.TryMakeMove(aiX, aiY);
            }

            _repository.Update(session);
            return moveStatus;
        }
    }
}
