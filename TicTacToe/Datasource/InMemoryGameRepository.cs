using System.Collections.Concurrent;
using TicTacToe.Domain.Models;

namespace TicTacToe.Datasource
{
    public class InMemoryGameRepository : IGameRepository
    {
        private readonly ConcurrentDictionary<Guid, GameSessionModel> _sessions = new();

        public GameSessionModel Create(int size)
        {
            GameSessionModel session = new(size, Guid.NewGuid());
            _sessions.TryAdd(session.Id, session);
            return session;
        }

        public GameSessionModel? Get(Guid id)
        {
            _sessions.TryGetValue(id, out GameSessionModel? session);
            return session;
        }

        public void Update(GameSessionModel session)
        {
            if (!_sessions.ContainsKey(session.Id))
                throw new KeyNotFoundException($"Game session with id {session.Id} not found.");
            _sessions[session.Id] = session;
        }
    }
}
