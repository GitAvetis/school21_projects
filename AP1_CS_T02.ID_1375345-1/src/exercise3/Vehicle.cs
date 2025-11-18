namespace exercise3
{
	abstract class Vehicle 
    {
		private string type;
		private string vehicleType;
        private double speed;


        protected Vehicle(string type, string vehicleType, double speed)
        {
			Type = type;
			Speed = speed;
			VehicleType = vehicleType;

        }
		public string Type
		{
			get { return type; }
			set { 
				type = value; }
		}
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
			set {
				if (value < 0)
					throw new ArgumentException("Speed cannot be negative");
				speed = value; }
		}

		abstract public string Intelligence();
	}
}