namespace exercise4
{
    internal class Program
    {
        static void Main()
        {
            while (MainCycle())
            {
                Console.Clear();
            }

            Console.ReadKey();
        }

        public struct Errors
        {

            public bool vehicle_type_err;
            public bool speed_err;
            public bool incorrect_input_err;
            public bool year_less_then_0_err;
            public bool year_more_then_2023_err;


            public Errors()
            {
                vehicle_type_err = false;
                speed_err = false;
                incorrect_input_err = false;
                year_less_then_0_err = false;
                year_more_then_2023_err = false;
            }
        }

        static bool MainCycle()
        {
            Console.WriteLine(" Enter your data:");

            Errors errors = new();
            List<string> allowedVehicleTypes = new() { "car", "plane", "airship", "bike" };

            List<Vehicle> input_mass = GetUserInput(ref errors, allowedVehicleTypes);
            Console.WriteLine();

            bool needRepeat = errors.incorrect_input_err;

            PrintErrors(errors);
            PrintInfo(input_mass);
            if (needRepeat)
            {
                Console.WriteLine("\n Press any key to try again...\n");
                Console.ReadKey();
            }

            else
                Console.WriteLine("\n Press any key to ecape...");

            return needRepeat;
        }

        static public void PrintErrors(Errors errors)
        {
            if (errors.incorrect_input_err)
            {
                Console.WriteLine("Could not parse a number. Please, try again");
            }

            if (errors.vehicle_type_err)
            {
                Console.WriteLine("Incorrect input. Unsupported vehicle type");
            }

            if (errors.speed_err)
            {
                Console.WriteLine("Incorrect input. Speed < 0");
            }

            if (errors.year_more_then_2023_err)
            {
                Console.WriteLine("Incorrect input. year > 2023");
            }

            if (errors.year_less_then_0_err)
            {
                Console.WriteLine("Incorrect input. year < 0");
            }
        }

        static List<Vehicle> GetUserInput(ref Errors errors, List<string> allowedVehicleTypes)
        {
            List<Vehicle> transports = new();

            string? input = Console.ReadLine();

            if (!int.TryParse(input, out int num_of_lines) || num_of_lines <= 0)
            {
                errors.incorrect_input_err = true;
                return transports;
            }

            for (int i = 0; i < num_of_lines; i++)
            {
                string? vehicle = Console.ReadLine();

                if (string.IsNullOrEmpty(vehicle) || !allowedVehicleTypes.Contains(vehicle))
                {
                    errors.vehicle_type_err = true;
                    continue;
                }

                string? type = Console.ReadLine();

                if (string.IsNullOrEmpty(type))
                {
                    errors.vehicle_type_err = true;
                    continue;
                }

                if (!double.TryParse(Console.ReadLine(), out double speed) || speed < 0)
                {
                    errors.speed_err = true;
                    continue;
                }

                if (!int.TryParse(Console.ReadLine(), out int year))
                {
                    errors.incorrect_input_err = true;
                    continue;

                }

                if (year < 0 || year > 2023)
                {
                    errors.year_more_then_2023_err = year > 2023;
                    errors.year_less_then_0_err = year < 0;
                    continue;
                }

                AddVehicleByVehicleType(transports, type, speed, year, vehicle);
            }
            return transports;
        }

        static void AddVehicleByVehicleType(List<Vehicle> transports, string type, double speed, int year, string vehicle)
        {
            switch (vehicle)
            {
                case "car":
                    transports.Add(new Car(type, speed, year));
                    break;
                case "plane":
                    transports.Add(new Plane(type, speed, year));
                    break;
                case "airship":
                    transports.Add(new Airship(type, speed, year));
                    break;
                case "bike":
                    transports.Add(new Bike(type, speed, year));
                    break;
                default:
                    break;
            }
        }

        static List<Vehicle> ModifiedTransportList(List<Vehicle> transports)
        {
            return transports
                .Select(t =>
                {
                    t.Speed = t.Speed > 100 ? Math.Round(t.Speed * 1.07, 3) : t.Speed;
                    return t;
                })
                .OrderByDescending(t => t.Year)
                .ToList();
        }

        static void PrintInfo(List<Vehicle> transports)
        {
            List<Vehicle> modifiedTransportList = ModifiedTransportList(transports);

            foreach (var vehicle in modifiedTransportList)
            {
                Console.WriteLine(vehicle.Intelligence());
            }

        }
    }
}
