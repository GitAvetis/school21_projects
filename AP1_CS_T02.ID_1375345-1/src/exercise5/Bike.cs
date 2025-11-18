namespace exercise5
{
    class Bike : Vehicle
    {
        public Bike(string type, double speed, string vehicleType) : base(type, speed, vehicleType) { }

        public override double TimeRace(int traceLength)
        {
            RaceTime = Math.Round(traceLength / Speed, 3);
            return RaceTime;
        }
        
        public override string Intelligence()
        {
            return $"Type bike = {Type}, speed = {Speed}, timeRace = {RaceTime}";
        }
    }
}