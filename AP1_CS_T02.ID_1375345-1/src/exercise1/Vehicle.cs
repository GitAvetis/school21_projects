namespace exercise1
{
	abstract class Vehicle
	{
		private string type;
		private double speed;

		protected Vehicle(string type, double speed)
		{
			Type = type;
			Speed = speed; 
		}
		public string Type
		{
			get { return type; }
			set { 
				type = value; }
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