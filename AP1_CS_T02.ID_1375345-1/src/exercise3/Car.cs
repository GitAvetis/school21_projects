using exercise3.Interfaces;

namespace exercise3
{
    class Car : Vehicle, ILand
    {
        public int NumberOfWheels { get; set; }

        public Car(string type, string vehicleType, double speed, int numberOfWheels) : base(type, vehicleType, speed)
        {
            NumberOfWheels = numberOfWheels;
        }
        public override string Intelligence()
        {
            return $"Type car = {Type}, speed = {Speed}, numberOfWheels = {NumberOfWheels}";
        }
    }
}