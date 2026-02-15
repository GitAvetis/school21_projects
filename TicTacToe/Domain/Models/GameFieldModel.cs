namespace TicTacToe.Domain.Models
{
    public enum CellState
    {
        Empty = 0,
        X = 1,
        O = 2
    }

    public enum MoveStatus
    {
        Sucsess,
        CellIsNotEmpty,
        IncorrectCoordinates,
        StateError,
        GameIsOver
    }

    public class GameFieldModel
    {
        private int[,] _field;
        private readonly int _size;

        public GameFieldModel(int size)
        {
            _size = size;
            SetField();
        }

        private void SetField()
        {
            if (_size <= 0)
                throw new ArgumentException("Incorrect size of Matrix", nameof(_size));

            _field = new int[_size, _size];
        }

        public MoveStatus MakeMove(int x, int y, CellState state)
        {
            if (state == CellState.Empty)
                return MoveStatus.StateError;

            if (x < 0 || y < 0 || x >= _size || y >= _size)
                return MoveStatus.IncorrectCoordinates;

            if (_field[x, y] != (int)CellState.Empty)
                return MoveStatus.CellIsNotEmpty;
            else
            {
                _field[x, y] = (int)state;
                return MoveStatus.Sucsess;
            }
        }

        public CellState GetCell(int x, int y)
        {
            if (x < 0 || y < 0 || x >= _size || y >= _size)
                throw new ArgumentException("Incorrect Coordinates of cell");
            else
                return (CellState)_field[x, y];
        }

        public bool IsCellEmpty(int x, int y)
        {
            if (x < 0 || y < 0 || x >= _size || y >= _size)
                throw new ArgumentException("Incorrect Coordinates of cell");

            return (_field[x, y] == (int)CellState.Empty);
        }

        public bool IsFieldFull()
        {
            for (int i = 0; i < _size; i++)
            {
                for (int j = 0; j < _size; j++)
                {
                    if (_field[i, j] == (int)CellState.Empty)
                        return false;
                }
            }
            return true;
        }

        public CellState[,] GetFieldCopy()
        {
            CellState[,] fieldCopy = new CellState[_size, _size];

            for (int i = 0; i < _size; i++)
            {
                for (int j = 0; j < _size; j++)
                {
                    fieldCopy[i, j] = (CellState)_field[i, j];
                }
            }

            return fieldCopy;
        }

        public CellState CheckWin()
        {
            CellState playerState;
            bool isXWin = HasWinningLine(CellState.X);

            if (isXWin)
                playerState = CellState.X;
            else
                playerState = HasWinningLine(CellState.O) ? CellState.O : CellState.Empty;

            return playerState;
        }

        private bool HasWinningLine(CellState playerState)
        {
            bool winByDiag1 = true;
            bool winByDiag2 = true;

            for (int i = 0; i < _size; i++)
            {
                bool winByRow = true;
                bool winByCol = true;

                for (int j = 0; j < _size; j++)
                {
                    if (_field[i, j] != (int)playerState)
                    {
                        winByRow = false;
                    }

                    if (_field[j, i] != (int)playerState)
                    {
                        winByCol = false;
                    }
                }

                if (winByCol || winByRow)
                    return true;

                if (_field[i, i] != (int)playerState)
                {
                    winByDiag1 = false;
                }

                if (_field[i, _size - 1 - i] != (int)playerState)
                {
                    winByDiag2 = false;
                }
            }

            if (winByDiag1 || winByDiag2)
                return true;
            else
                return false;
        }
    }
}
