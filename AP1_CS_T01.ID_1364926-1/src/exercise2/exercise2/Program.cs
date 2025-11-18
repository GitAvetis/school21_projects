namespace exercise2
{

    internal class Program
    {
        static void Main(string[] args)
        {

            double[,] matrix = new double[3, 4];
            string path = "";
            MainCiqle(path, matrix);
            Console.WriteLine("\nEnter any key to ecape...");
            Console.ReadKey();

        }

        static string FindTestsFolder()
        {
            string currentPath = Directory.GetCurrentDirectory();

            for (int i = 0; i < 10; i++)
            {
                string testsPath = Path.Combine(currentPath, "tests");
                if (Directory.Exists(testsPath))
                    return testsPath;

                string parentPath = Path.GetDirectoryName(currentPath);
                if (string.IsNullOrEmpty(parentPath) || parentPath == currentPath)
                    break;

                currentPath = parentPath;
            }

            return "tests";
        }

        static bool TestMode(ref string path)
        {
            string testsFolder = FindTestsFolder();

            Console.WriteLine("Choose a file for testing:\n 1 - incorrect_matrix \n 2 - infinite_solutions \n 3 - no_solution \n 4 - one_solution " +
                "\nIf you wish to manually enter your file's path, please press another key.");

            ConsoleKeyInfo key = Console.ReadKey(intercept: true);
            Console.WriteLine();
            Console.WriteLine();

            bool test_mode_activated = true;

            switch (key.KeyChar)
            {
                case '1':
                    path = Path.Combine(testsFolder, "incorrect_matrix.txt");
                    break;
                case '2':
                    path = Path.Combine(testsFolder, "infinite_solutions.txt");
                    break;
                case '3':
                    path = Path.Combine(testsFolder, "no_solution.txt");
                    break;
                case '4':
                    path = Path.Combine(testsFolder, "one_solution.txt"); ;
                    break;
                default:
                    Console.WriteLine("\n Manual mode:");
                    test_mode_activated = false;

                    break;
            }

            return test_mode_activated;
        }

        static void MainCiqle(string path, double[,] matrix)
        {
            Console.WriteLine("\nIf u want enter Test mode, press 'T'.\n");
            Console.WriteLine("Press any key to manually enter a file's path ");
            Console.WriteLine();

            ConsoleKeyInfo key = Console.ReadKey(intercept: true);
            bool test_mode_activated = false;
            if (key.KeyChar == 't' || key.KeyChar == 'T')
            {
                Console.WriteLine("\n TETS MODE\n");
                test_mode_activated = TestMode(ref path);
            }

            if (!test_mode_activated)
            {
                Console.WriteLine("Enter full file's path:");
                path = Console.ReadLine();
            }

            if (File.Exists(path))
            {

                if (ReadMartixFromFile(matrix, path))
                {
                    int n = matrix.GetLength(0); //Размерность начальной матрицы (строки)
                    int num_of_solutions = 1;
                    bool fail = !Gauss(matrix, n, CloneMatix(matrix, n), ref num_of_solutions);
                    if (fail && num_of_solutions == 0)
                        Console.WriteLine("The system of linear algebraic equations has no solutions");
                    else if (fail && num_of_solutions == 8)
                        Console.WriteLine("The system of linear algebraic equations has infinite solutions");

                }
                else
                {
                    Console.WriteLine("Couldn't parse a number. Please, try again");
                    Console.WriteLine("The system of linear algebraic equations has no solutions");
                    MainCiqle(path, matrix);
                }
            }
            else
            {
                Console.WriteLine("Input error. File isn't exist");
                MainCiqle(path, matrix);
            }
        }

        static bool ReadMartixFromFile(double[,] matrix, string path)
        {
            bool result = true;

            string[] all_lines = File.ReadAllLines(path);
            for (int i = 0; i < all_lines.Length; i++)
            {
                string[] nums = all_lines[i].Split(' ');
                for (int j = 0; j < nums.Length; j++)
                {
                    try
                    {
                        matrix[i, j] = double.Parse(nums[j]);
                    }
                    catch
                    {
                        result = false;
                        break;
                    }
                }
            }

            return result;
        }

        static double[,] CloneMatix(double[,] Matrix, int n)
        {
            double[,] Matrix_Clone = new double[n, n + 1];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n + 1; j++)
                    Matrix_Clone[i, j] = Matrix[i, j];
            return Matrix_Clone;
        }

        static void MatixHaveNoSolutions(double[,] Matrix_Clone, int k, int n, ref int num_of_solutions)
        {
            num_of_solutions = 1;
            if (Math.Abs(Matrix_Clone[k, k]) < 1e-15)// Если диагональный элемент почти 0
            {
                if (Math.Abs(Matrix_Clone[k, n]) > 1e-15)// И свободный член НЕ 0
                {
                    num_of_solutions = 0; // Нет решений
                }
                else //Иначе их бесконечно много
                {
                    num_of_solutions = 8;
                }
            }

        }

        static bool directGauss(double[,] Matrix, int n, double[,] Matrix_Clone, ref int num_of_solutions)
        {
            for (int k = 0; k < n; k++) //k-номер строки
            {
                MatixHaveNoSolutions(Matrix_Clone, k, n, ref num_of_solutions);
                if (num_of_solutions == 1)
                {
                    for (int i = 0; i < n + 1; i++) //i-номер столбца
                        Matrix_Clone[k, i] = Matrix_Clone[k, i] / Matrix[k, k]; //Деление k-строки на первый член !=0 для преобразования его в единицу
                    for (int i = k + 1; i < n; i++) //i-номер следующей строки после k
                    {
                        double K = Matrix_Clone[i, k] / Matrix_Clone[k, k]; //Коэффициент
                        for (int j = 0; j < n + 1; j++) //j-номер столбца следующей строки после k
                            Matrix_Clone[i, j] = Matrix_Clone[i, j] - Matrix_Clone[k, j] * K; //Зануление элементов матрицы ниже первого члена, преобразованного в единицу
                    }
                    for (int i = 0; i < n; i++) //Обновление, внесение изменений в начальную матрицу
                        for (int j = 0; j < n + 1; j++)
                            Matrix[i, j] = Matrix_Clone[i, j];
                }
                else
                {
                    return false;
                }
            }
            return true;

        }

        static void reverseGauss(double[,] Matrix, int n, double[,] Matrix_Clone)
        {
            for (int k = n - 1; k > -1; k--) //k-номер строки
            {
                for (int i = n; i > -1; i--) //i-номер столбца
                    Matrix_Clone[k, i] = Matrix_Clone[k, i] / Matrix[k, k];
                for (int i = k - 1; i > -1; i--) //i-номер следующей строки после k
                {
                    double K = Matrix_Clone[i, k] / Matrix_Clone[k, k];
                    for (int j = n; j > -1; j--) //j-номер столбца следующей строки после k
                        Matrix_Clone[i, j] = Matrix_Clone[i, j] - Matrix_Clone[k, j] * K;
                }
            }
        }

        static bool Gauss(double[,] Matrix, int n, double[,] Matrix_Clone, ref int num_of_solutions)
        {
            double[] Answer = new double[n];

            // Прямой ход (Зануление нижнего левого угла)

            if (directGauss(Matrix, n, Matrix_Clone, ref num_of_solutions))
            {
                // Обратный ход (Зануление верхнего правого угла)
                reverseGauss(Matrix, n, Matrix_Clone);

                // Отделяем от общей матрицы ответы
                for (int i = 0; i < n; i++)
                    Answer[i] = Matrix_Clone[i, n];
                PrintGaussAnswers(Answer);
                return true;

            }
            else
            {
                return false;
            }
        }

        static void PrintGaussAnswers(double[] Answer)
        {
            int i = 1;
            foreach (int x in Answer)
            {
                Console.WriteLine("x" + i + " = " + x);
                i++;
            }
        }
    }
}

