using TicTacToe.Datasource;
using TicTacToe.Domain;
using TicTacToe.Domain.Models;

namespace TicTacToe
{
    public class GameService : IGameService
    {
        private readonly IGameRepository _repository;
        private readonly IServiceDomain _domainService;

        public GameService(IGameRepository repository, IServiceDomain serviceDomain)
        {
            _repository = repository;
            _domainService = serviceDomain;
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
                (int aiX, int aiY) = _domainService.GetNextMove(session);
                session.TryMakeMove(aiX, aiY);
            }

            if(!_domainService.ValidateField(session))
                return MoveStatus.StateError;

            if (_domainService.IsGameOver(session))
                return MoveStatus.GameIsOver;

            _repository.Update(session);
            return moveStatus;
        }
    }
}
