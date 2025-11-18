namespace exercise4
{
    abstract class Vehicle
    {
        private string type;
        private double speed;
        private int year;


        protected Vehicle(string type, double speed, int year)
        {
            Type = type;
            Speed = speed;
            Year = year;

        }

        public int Year
        {
            get { return year; }
            set
            {
                year = value;
            }
        }

        public string Type
        {
            get { return type; }
            set
            {
                type = value;
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

        abstract public string Intelligence();
    }
}