namespace ProjectTeam01.domain.Items
{
    internal abstract class Item: GameObject
    {
        public enum ItemType
        {
            Treasure,
            Food,
            Elixir,
            Scroll,
            Weapon
        }

        public ItemType Type { get; }

        protected Item(ItemType type, int posX, int posY) : base(posX, posY)
        {
            Type = type;
        }
    }
}
