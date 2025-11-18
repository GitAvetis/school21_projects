namespace exercise1
{
    class Plane : Vehicle
    {
        public Plane(string type, double speed) : base(type, speed) { }
        public override string Intelligence()
        {
            return $"Type plane = {Type}, speed = {Speed}";
        }
    }
}