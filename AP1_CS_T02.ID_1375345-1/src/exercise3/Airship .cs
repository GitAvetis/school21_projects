using exercise3.Interfaces;

namespace exercise3
{
    class Airship : Vehicle, IAir
    {
        public float MaxFlightAltitude { get; set; }

        public Airship(string type, string vehicleType, double speed, float maxFlightAltitude) : base(type, vehicleType, speed)
        {
            MaxFlightAltitude = maxFlightAltitude;
        }

        public override string Intelligence()
        {
            return $"Type airship = {Type}, speed = {Speed}, maxFlightAltitude = {MaxFlightAltitude}";
        }
    }
}