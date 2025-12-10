namespace ProjectTeam01.domain
{
    internal class BattleService
    {
        public static bool HitSuccess(int attackerBaseAgility, int targetBaseAgility)
        {

            int hitChance = 50 + (attackerBaseAgility - targetBaseAgility);
            if(hitChance < 5)
            {
                hitChance = 5;
            }
            else if (hitChance > 95)
            {
                hitChance = 95;
            }
            return Random.Shared.Next(0, 100) < hitChance;
        }
    }
}
