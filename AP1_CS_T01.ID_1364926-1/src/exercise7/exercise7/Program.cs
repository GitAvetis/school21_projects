using System.Globalization;

namespace exercise7
{
    internal class Program
    {
        static void Main()
        {
            Dictionary<string, double> products = null;
            while (!MainCycle(ref products))
            { }

            Console.ReadKey();
        }

        static bool MainCycle(ref Dictionary<string, double> products)
        {
            products?.Clear();
            int err_code = GetUserInput(ref products);
            bool result = true;

            if (err_code == 1)
            {
                Console.WriteLine("Couldn't parse a words. Please, try again");
                result = false;
            }
            else if (err_code == 2)
            {
                Console.WriteLine("Incorrect input. price <= 0");
            }

            if (products != null && products.Count > 0)
                Console.WriteLine(AveragePrice(products).ToString("F3", CultureInfo.InvariantCulture));
            return result;
        }

        static int GetUserInput(ref Dictionary<string, double> products)
        {
            Console.WriteLine("Enter your data:");
            int error_code = 0;
            try
            {
                string? input = (Console.ReadLine());
                if (input == null)
                    return 1;
                if (!int.TryParse(input, out int num_of_lines) || num_of_lines <= 0)//перове значение - количество строк
                    return 1;
                products = new Dictionary<string, double>();
                for (int i = 0; i < num_of_lines; i++)
                {
                    string? tmp_line = Console.ReadLine();
                    if (string.IsNullOrWhiteSpace(tmp_line))
                        return 1;
                    string[] tmp_line_split = tmp_line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                    if (tmp_line_split.Length != 2)
                        return 1;

                    string product_name = tmp_line_split[0];

                    if (!double.TryParse(tmp_line_split[1], NumberStyles.Float, CultureInfo.InvariantCulture, out double product_price))
                        return 1;
                    if (product_price <= 0)
                    {
                        error_code = 2;
                        continue; // пропускаем этот ввод, не добавляем, не выходим из цикла
                    }

                    products[product_name] = product_price;

                }

            }
            catch
            {
                return 1;
            }

            return error_code;

        }

        static double AveragePrice(Dictionary<string, double> products)
        {
            double sum = 0.0;
            foreach (var item in products)
            {
                sum += item.Value;
            }
            return sum / products.Count;
        }
    }
}
