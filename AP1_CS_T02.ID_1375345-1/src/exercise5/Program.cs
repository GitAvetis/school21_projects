namespace exercise5
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
            public bool racers_num_err;
            public bool distance_err;

            public Errors()
            {
                vehicle_type_err = false;
                speed_err = false;
                incorrect_input_err = false;
                racers_num_err = false;
                distance_err = false;
            }
        }

        static bool MainCycle()
        {
            Console.WriteLine(" Enter your data:");

            Errors errors = new();
            int distance = 0;
            List<string> allowedVehicleTypes = new() { "car", "bike" };
            List<Vehicle> transports = GetUserInput(ref errors, allowedVehicleTypes, ref distance);
            Console.WriteLine();

            bool needRepeat = false;

            if (transports.Count < 2)
                errors.racers_num_err = true;

            if (errors.incorrect_input_err || errors.racers_num_err)
                needRepeat = true;

            PrintErrors(errors);

            if (needRepeat)
            {
                Console.WriteLine("\n Press any key to try again...\n");
                Console.ReadKey();
            }
            else
            {
                string winner = RaceWinner(transports, distance);
                PrintInfo(transports.OrderBy(v => v.RaceTime).ToList());
                Console.WriteLine(winner);
                Console.WriteLine("\n Press any key to ecape...");
            }

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

            if (errors.racers_num_err)
            {
                Console.WriteLine("No one to compete with");
            }

            if (errors.distance_err)
            {
                Console.WriteLine("Incorrect input. Distance < 0");
            }
        }

        static List<Vehicle> GetUserInput(ref Errors errors, List<string> allowedVehicleTypes, ref int distance)
        {
            List<Vehicle> transports = new();

            string? input = Console.ReadLine();

            if (!int.TryParse(input, out int num_of_racers))
            {
                errors.incorrect_input_err = true;
                return transports;
            }

            if (int.TryParse(Console.ReadLine(), out distance))
            {
                if (distance <= 0)
                {
                    errors.distance_err = true;
                    return transports;
                }
            }
            else
            {
                errors.incorrect_input_err = true;
                return transports;
            }

            for (int i = 0; i < num_of_racers; i++)
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

                AddVehicleByVehicleType(transports, type, speed, vehicle);
            }

            return transports;
        }

        static void AddVehicleByVehicleType(List<Vehicle> transports, string type, double speed, string vehicle)
        {
            switch (vehicle)
            {
                case "car":
                    transports.Add(new Car(type, speed, vehicle));
                    break;
                case "bike":
                    transports.Add(new Bike(type, speed, vehicle));
                    break;
                default:
                    break;
            }
        }

        static string RaceWinner(List<Vehicle> transports, int distance)
        {
            //создал список кортежей из типов Vehicle и Task.
            List<(Vehicle Vehicle, Task<double> Task)> tasks = transports
                .Select(v =>//здесь мы и формируем кортеж 
                (
                    Vehicle: v,// добавляем объект класса Vehicle
                    Task: Task.Run(() => v.TimeRace(distance))//запускаем задачу по подсчёту TimeRace в пуле потоков 
                    //метод возвращает double поэтому Task<double>, 
                ))
                .ToList();

            Task.WaitAll(tasks.Select(t => t.Task).ToArray());
            Vehicle winner = tasks.MinBy(t => t.Vehicle.RaceTime).Vehicle;
            Console.WriteLine();
            return $"Winner = {winner.Type} {winner.VehicleType} with speed = {winner.Speed} m/s";

        }

        static void PrintInfo(List<Vehicle> transports)
        {
            foreach (var vehicle in transports)
            {
                Console.WriteLine(vehicle.Intelligence());
            }

        }
    }
}

