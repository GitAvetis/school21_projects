using ProjectTeam01.domain.Items;

namespace ProjectTeam01.domain.Effects
{
    internal class WeaponManager
    {
        public Weapon? EquippedWeapon { get; private set; }// чтобы принимать параметр weapon только через спец. метод, где у нас строгая типизация входных параметров

        public Weapon? EquipWeapon(Weapon weapon)
        {
            Weapon? previousWeapon = EquippedWeapon;
            UnequipWeapon();
            EquippedWeapon = weapon;
            return previousWeapon;
        }

        public Weapon? UnequipWeapon()// возможно потребуется доработка (выкинуть/положить в инвентарь)
        {
            Weapon? previousWeapon = EquippedWeapon;
            if (EquippedWeapon != null)
            {
                EquippedWeapon = null;
            }
            return previousWeapon;
        }

        public int GetStrengthBonus()
        {
            return EquippedWeapon != null ? EquippedWeapon.StrengthBonus : 0;
        }
    }
}
