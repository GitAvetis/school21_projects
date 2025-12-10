using ProjectTeam01.domain.Characters;
using ProjectTeam01.domain.Items;
using ProjectTeam01.domain.Items.Interfaces;

namespace ProjectTeam01.domain
{
    internal class Backpack
    {
        private readonly Dictionary<Item.ItemType, List<Item>> _items;
        private const int MaxElementsOfOneType = 9;

        public Backpack()
        {
            _items = new Dictionary<Item.ItemType, List<Item>>();
            foreach (Item.ItemType type in Enum.GetValues(typeof(Item.ItemType)))
                _items[type] = new List<Item>();//создаём пустой список для каждого типа предметов
        }

        //чтобы итерироваться по всем предметам в рюкзаке вне зависимости от их типа
        public IEnumerable<Item> AllItems
        {
            get
            {
                return _items.SelectMany(kv => kv.Value);//объединяем все списки в один типа <Item>
            }
        }

        public IEnumerable<Item> UsableItems
        {
            get
            {
                return _items.SelectMany(kv => kv.Value).Where(item => item is IUsableItem);//список расходуемых предметов
            }
        }

        public bool EquipWeapon(Weapon weapon, Hero hero)
        {
            if (AllItems.Contains(weapon))
            {
                hero.WeaponManager.EquipWeapon(weapon);
                return true;
            }
            return false;
        }


        public bool IsEmpty
        {
            get
            {
                return !AllItems.Any();
            }
        }

        public bool Add(Item item)
        {
            List<Item> list = _items[item.Type];
            if (item is Treasure newTreasure)//проверяем, если клад
            {
                AddTreasure(list, newTreasure);
                return true;
            }

            if (list.Count < MaxElementsOfOneType)
            {
                list.Add(item);
                return true;
            }
            return false;
        }

        public static void AddTreasure(List<Item> list, Treasure newTreasure)
        {
            if (list.Count == 0)//если кладов ещё нет, добавляем новый
            {
                list.Add(newTreasure);
            }
            else//если клад уже есть, переписываем его стоимость увеличивая её на стоимость нового клада 
            {
                if (list[0] is Treasure existingTreasure)
                    existingTreasure.Price += newTreasure.Price;
            }
        }

        public void DropItem(Item item)
        {
            List<Item> list = _items[item.Type];
            list.Remove(item);
            //нужно будет реализовать механизм выбрасывания предмета на землю в игре
        }

        public bool UseItem(Item item, Hero hero)
        {
            if (item is not IUsableItem usableItem)
                return false;

            List<Item> list = _items[item.Type];
            if (!list.Contains(item))
                return false;

            usableItem.Use(hero);
            DropItem(item);
            return true;
        }
    }
}
