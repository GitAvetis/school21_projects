namespace TicTacToe.Domain
{
    public interface IService
    {
        public void NextGame();
        public bool GameFieldValidation();
        public bool IsGameOver();
    }
}
