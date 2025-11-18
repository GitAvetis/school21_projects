namespace exercise1
{
    class Car : Vehicle
    {
        public Car(string type, double speed) : base(type, speed) { }
        public override string Intelligence()
        {
            return $"Type car = {Type}, speed = {Speed}";
        }
    }
}