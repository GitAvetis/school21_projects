namespace exercise3
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
            public bool wheels_number_err;
            public bool maxFlightAltitude_err;


            public Errors()
            {
                vehicle_type_err = false;
                speed_err = false;
                incorrect_input_err = false;
                wheels_number_err = false;
                maxFlightAltitude_err = false;
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
            if (errors.wheels_number_err)
            {
                Console.WriteLine("Incorrect input. numberOfWheels <= 0");
            }
            if (errors.maxFlightAltitude_err)
            {
                Console.WriteLine("Incorrect input. maxFlightAltitude < 0");
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

                if (!int.TryParse(Console.ReadLine(), out int wheelsOrMaxFlightAltitude) || wheelsOrMaxFlightAltitude < 0)
                {
                    if ((vehicle == "car" || vehicle == "bike") && wheelsOrMaxFlightAltitude <= 0)
                        errors.wheels_number_err = true;
                    if ((vehicle == "plane" || vehicle == "airship") && wheelsOrMaxFlightAltitude < 0)
                        errors.maxFlightAltitude_err = true;
                    continue;
                }
                AddVehicleByVehicleType(transports, type, speed, wheelsOrMaxFlightAltitude, vehicle);
            }
            return transports;
        }

        static void AddVehicleByVehicleType(List<Vehicle> transports, string type, double speed, int wheelsOrMaxFlightAltitude, string vehicle)
        {
            switch (vehicle)
            {
                case "car":
                    transports.Add(new Car(type, vehicle, speed, wheelsOrMaxFlightAltitude));
                    break;
                case "plane":
                    transports.Add(new Plane(type, vehicle, speed, wheelsOrMaxFlightAltitude));
                    break;
                case "airship":
                    transports.Add(new Airship(type, vehicle, speed, wheelsOrMaxFlightAltitude));
                    break;
                case "bike":
                    transports.Add(new Bike(type, vehicle, speed, wheelsOrMaxFlightAltitude));
                    break;
                default:
                    break;
            }
        }

        static void PrintInfo(List<Vehicle> transports)
        {
            List<Vehicle> transportsCpy = transports;
            for (int i = 0; i < transports.Count; i++)
            {
                Vehicle vehicle = transports[i];
                if (vehicle.VehicleType == "plane" || vehicle.VehicleType == "airship")
                {
                    Console.WriteLine(vehicle.Intelligence());
                    transportsCpy.Remove(vehicle);
                }

            }
            foreach (var vehicle in transportsCpy)//without flying vehicles
            {
                Console.WriteLine(vehicle.Intelligence());
            }

        }
    }
}

