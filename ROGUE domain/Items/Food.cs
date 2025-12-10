using ProjectTeam01.domain.Characters;
using ProjectTeam01.domain.Items.Interfaces;

namespace ProjectTeam01.domain.Items
{
    internal class Food : Item, IUsableItem
    {
        public Food(int posX, int posY) : base (Item.ItemType.Food, posX, posY)
        {
            
        }

        private static int _HealValue(int MaxHp, int ActualHp)
        {
            if (MaxHp - ActualHp < 10)
                return MaxHp - ActualHp;
            else return 10;
        }

        void IUsableItem.Use(Hero hero)
        {
           hero.Heal(_HealValue(hero.MaxHp, hero.ActualHp));
        }
        //public FoodTypeEnum FoodType { get;}
        //public enum FoodTypeEnum
        //{
        //    Apple,
        //    Bread,
        //    Cheese
        //} 
        //могу внести разнообразия, но хз, насколько это нужно
    }
}
