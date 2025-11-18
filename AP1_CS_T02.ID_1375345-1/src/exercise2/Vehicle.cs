namespace exercise2
{
    abstract class Vehicle
    {
        private string type;
        private double speed;
        private int tankVolume;
        private float pathDistance;

        protected Vehicle(string type, double speed, int tankVolume, float pathDistance)
        {
            Type = type;
            Speed = speed;
            TankVolume = tankVolume;
            PathDistance = pathDistance;
        }

        abstract public float getFuelConsumL();

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

        public float PathDistance
        {
            get { return pathDistance; }
            set
            {
                if (value < 0)
                    throw new ArgumentException("Distance cannot be negative");
                pathDistance = value;
            }
        }

        public int TankVolume
        {
            get { return tankVolume; }
            set
            {
                if (value < 0)
                    throw new ArgumentException("Tank volume cannot be negative");
                tankVolume = value;
            }
        }

        abstract public string Intelligence();
    }
}
