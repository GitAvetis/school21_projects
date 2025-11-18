using System;
using System.Globalization;

namespace exercise1
{
    internal class Program
    {
        static void Main(string[] args)
        {

            double[,] quadrilateral = new double[4, 2];//координаты вершин ABCD
            double[] vertices = new double[5];//для длин сторон AB,BC,CD,AD,AC

            InputCoordinates(quadrilateral);

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (i > 0 && j > 0)
                    {
                        vertices[i - 1] = Length_by_coordinates(quadrilateral, i, j);
                    }
                    if (i == 3 && j > 0)
                    {
                        vertices[i] = Length_by_coordinates(quadrilateral, 4, j);

                    }
                }

            }

            double A1 = quadrilateral[0, 0];
            double A2 = quadrilateral[0, 1];
            vertices[4] = Math.Sqrt(Math.Pow((A1 - quadrilateral[2, 0]), 2) + (Math.Pow((A2 - quadrilateral[2, 1]), 2)));//Диагональ

            double first_triangle_square = HeronFormula(vertices[0], vertices[1], vertices[4]);//ABC
            double second_triangle_square = HeronFormula(vertices[2], vertices[3], vertices[4]);//ACD
            Console.WriteLine("Result: " + (first_triangle_square + second_triangle_square));

        }

        static void InputCoordinates(double[,] quadrilateral)
        {
            for (int i = 0; i < 4; i++)
            {
                try
                {
                    for (int j = 0; j < 2; j++)
                    {
                        string? input = Console.ReadLine();//? - означает, что переменная может содержать налл
                        if (input != null)
                            quadrilateral[i, j] = double.Parse(input, CultureInfo.InvariantCulture);
                    }
                }
                catch
                {
                    Console.WriteLine("Couldn't parse a number. Please, try again");
                    i--;
                }
            }
        }

        static double Length_by_coordinates(double[,] quadrilateral, int i, int j)
        {
            double x1 = 0;
            double x2 = 0;
            double y1 = 0;
            double y2 = 0;
            if (i != 4)
            {
                x1 = quadrilateral[i - 1, j - 1];
                x2 = quadrilateral[i, j - 1];
                y1 = quadrilateral[i - 1, j];
                y2 = quadrilateral[i, j];
            }
            else
            {
                x1 = quadrilateral[0, 0];
                x2 = quadrilateral[i - 1, j - 1];
                y1 = quadrilateral[0, 1];
                y2 = quadrilateral[i - 1, j];

            }
            //Console.WriteLine("x[" + x1 + "," + y1 + "]; y[" + x2 + "," + y2 + "]");
            return (Math.Sqrt(Math.Pow((x2 - x1), 2) + (Math.Pow((y2 - y1), 2))));
        }

        static double HeronFormula(double A, double B, double C)
        {
            double p = (A + B + C) / 2;
            return Math.Sqrt(p * (p - A) * (p - B) * (p - C));
        }
    }
}
