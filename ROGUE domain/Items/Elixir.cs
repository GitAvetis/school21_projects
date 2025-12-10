using static ProjectTeam01.domain.Effects.ActiveEffect;
using ProjectTeam01.domain.Items.Interfaces;
using ProjectTeam01.domain.Characters;
using ProjectTeam01.domain.Effects;

namespace ProjectTeam01.domain.Items
{
    internal class Elixir : Item, IUsableItem
    {

        public Elixir(EffectTypeEnum elixirType, int posX, int posY) : base(Item.ItemType.Elixir, posX, posY)
        {
            ElixirType = elixirType;
        }

        void IUsableItem.Use(Hero hero)
        {
            ActiveEffect effect = new ActiveEffect(ElixirType);
            if(hero.HeroBackpack.AllItems.Contains(this))
            hero.ActiveEffectManager.AddActiveEffect(effect);
        }

        public EffectTypeEnum ElixirType { get; }
    }
}
