namespace exercise4
{
    class Plane : Vehicle
    {
        public Plane(string type, double speed, int year) : base(type, speed, year) { }

        public override string Intelligence()
        {
            return $"Type plane = {Type}, speed = {Speed}, year = {Year}";
        }
    }
}