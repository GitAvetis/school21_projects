using exercise3.Interfaces;

namespace exercise3
{
    class Plane : Vehicle, IAir
    {
        public float MaxFlightAltitude { get; set; }

        public Plane(string type, string vehicleType, double speed, float maxFlightAltitude) : base(type, vehicleType, speed)
        {
            MaxFlightAltitude = maxFlightAltitude;
        }

        public override string Intelligence()
        {
            return $"Type plane = {Type}, speed = {Speed}, maxFlightAltitude = {MaxFlightAltitude}";
        }
    }
}