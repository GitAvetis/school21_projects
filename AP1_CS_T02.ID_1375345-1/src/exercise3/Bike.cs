using exercise3.Interfaces;

namespace exercise3
{
    class Bike : Vehicle, ILand
    {
        public int NumberOfWheels { get; set; }

        public Bike(string type, string vehicleType, double speed, int numberOfWheels) : base(type, vehicleType, speed)
        {
            NumberOfWheels = numberOfWheels;
        }

        public override string Intelligence()
        {
            return $"Type bike = {Type}, speed = {Speed}, numberOfWheels = {NumberOfWheels}";
        }
    }
}