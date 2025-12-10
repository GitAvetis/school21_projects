namespace ProjectTeam01.domain.Items
{
    internal class Treasure : Item
    {
        public Treasure(int posX, int posY, int lvl) : base(Item.ItemType.Treasure, posX, posY)
        {
            Price = 100 + 5*lvl;
        }
        public int Price { get; set; }
    }
}
