namespace exercise2
{

    class Plane : Vehicle
    {
        public Plane(string type, double speed, int tankVolume, float pathDistance) : base(type, speed, tankVolume, pathDistance) { }

        public override float getFuelConsumL()
        {
            return (TankVolume / PathDistance) * 100f * 3f;
        }
        public override string Intelligence()
        {
            return $"Type plane = {Type}, speed = {Speed}, tankVolume = {TankVolume}, fuelConsum = {getFuelConsumL():0.###}";
        }
    }
}
