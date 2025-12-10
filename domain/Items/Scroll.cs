using ProjectTeam01.domain.Characters;
using ProjectTeam01.domain.Items.Interfaces;
namespace ProjectTeam01.domain.Items
{
    internal class Scroll : Item, IUsableItem
    {
        public Scroll(ScrollTypeEnum scrollType, int posX, int posY) : base(Item.ItemType.Scroll, posX, posY)
        {
            ScrollType = scrollType;
        }

        public ScrollTypeEnum ScrollType { get; }

        public enum ScrollTypeEnum
        {
            Agility,
            Strength,
            MaxHp
        }

        void IUsableItem.Use(Hero hero)
        {
            switch (ScrollType)
            {
                case ScrollTypeEnum.Agility:
                    hero.ChangeBaseAgility(5);
                    break;
                case ScrollTypeEnum.Strength:
                    hero.ChangeBaseStrength(5);
                    break;
                case ScrollTypeEnum.MaxHp:
                    hero.ChangeBaseMaxHp(10);
                    hero.Heal(10);
                    break;
                default:
                    break;
            }
        }


    }

}
