namespace exercise5
{
    class Car : Vehicle
    {
        public Car(string type, double speed, string vehicleType) : base(type, speed, vehicleType) { }

        public override double TimeRace(int traceLength)
        {
            RaceTime = Math.Round((traceLength / Speed) * 1.07, 3);
            return RaceTime;
        }

        public override string Intelligence()
        {
            return $"Type car = {Type}, speed = {Speed}, timeRace = {RaceTime}";
        }
    }
}