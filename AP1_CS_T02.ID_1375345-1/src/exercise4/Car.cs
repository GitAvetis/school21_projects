namespace exercise4
{
    class Car : Vehicle
    {
        public Car(string type, double speed, int year) : base(type, speed, year) { }
        
        public override string Intelligence()
        {
            return $"Type car = {Type}, speed = {Speed}, year = {Year}";
        }
    }
}