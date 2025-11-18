namespace exercise2
{

    class Car : Vehicle
    {
        public Car(string type, double speed, int tankVolume, float pathDistance) : base(type, speed, tankVolume, pathDistance) { }

        public override float getFuelConsumL()
        {
            return (TankVolume / PathDistance) * 100f;
        }
        public override string Intelligence()
        {
            return $"Type car = {Type}, speed = {Speed}, tankVolume = {TankVolume}, fuelConsum = {getFuelConsumL():0.###}";
        }
    }

}
