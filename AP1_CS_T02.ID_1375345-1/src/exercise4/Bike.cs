namespace exercise4
{
    class Bike : Vehicle
    {
        public Bike(string type, double speed, int year) : base(type, speed, year) { }

        public override string Intelligence()
        {
            return $"Type bike = {Type}, speed = {Speed}, year = {Year}";
        }
    }
}