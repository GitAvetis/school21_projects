
namespace exercise2
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
            public bool distance_err;
            public bool tankVolume_err;


            public Errors()
            {
                vehicle_type_err = false;
                speed_err = false;
                incorrect_input_err = false;
                distance_err = false;
                tankVolume_err = false;
            }
        }

        static bool MainCycle()
        {
            Errors errors = new();

            List<Vehicle> input_mass = GetUserInput(ref errors);
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
            if (errors.distance_err)
            {
                Console.WriteLine("Incorrect input. Distance <= 0");
            }
            if (errors.tankVolume_err)
            {
                Console.WriteLine("Incorrect input. tankVolume < 0");
            }
        }

        static List<Vehicle> GetUserInput(ref Errors errors)
        {
            List<Vehicle> input_mass = new();
            Console.WriteLine("Enter your data:");
            try
            {
                string? input = Console.ReadLine();

                if (!int.TryParse(input, out int num_of_lines) || num_of_lines <= 0)
                {
                    errors.incorrect_input_err = true;
                    return input_mass;
                }

                for (int i = 0; i < num_of_lines; i++)
                {
                    string? vehicle = (Console.ReadLine());
                    if (vehicle != "car" && vehicle != "plane")
                    {
                        errors.vehicle_type_err = true;
                        continue;
                    }

                    string? type = (Console.ReadLine());
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

                    if (!int.TryParse(Console.ReadLine(), out int tank_volume) || tank_volume < 0)
                    {
                        errors.tankVolume_err = true;
                        continue;
                    }

                    if (!float.TryParse(Console.ReadLine(), out float distance) || distance <= 0)
                    {
                        errors.distance_err = true;
                        continue;
                    }

                    if (vehicle == "car")
                        input_mass.Add(new Car(type, speed, tank_volume, distance));
                    else
                        input_mass.Add(new Plane(type, speed, tank_volume, distance));

                }

            }
            catch
            {
                errors.incorrect_input_err = true;
                return input_mass;
            }

            return input_mass;

        }

        static void PrintInfo(List<Vehicle> input_mass)
        {
            foreach (var vehicle in input_mass)
            {
                Console.WriteLine(vehicle.Intelligence());
            }
        }
    }
}
