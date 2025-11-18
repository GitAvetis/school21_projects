namespace exercise4
{
    class Airship : Vehicle
    {
        public Airship(string type, double speed, int year) : base(type, speed, year) { }

        public override string Intelligence()
        {
            return $"Type airship = {Type}, speed = {Speed}, year = {Year}";
        }
    }
}