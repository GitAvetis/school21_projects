namespace exercise5
{
    abstract class Vehicle
    {
        private string vehicleType;
        private string type;
        private double speed;


        protected Vehicle(string type, double speed, string vehicleType)
        {
            Type = type;
            Speed = speed;
            VehicleType = vehicleType;
        }

        public string Type
        {
            get { return type; }
            set
            {
                type = value;
            }
        }

        public double RaceTime { get; protected set; }

        public string VehicleType
        {
            get { return vehicleType; }
            set
            {
                vehicleType = value;
            }
        }

        public double Speed
        {
            get { return speed; }
            set
            {
                if (value < 0)
                    throw new ArgumentException("Speed cannot be negative");
                speed = value;
            }
        }

        abstract public double TimeRace(int traceLength);
        abstract public string Intelligence();
    }
}