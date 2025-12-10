using ProjectTeam01.domain.Characters;

namespace ProjectTeam01.domain.Effects
{
    internal class ActiveEffectManager(List<ActiveEffect> activeEffects, Hero hero)
    {
        public List<ActiveEffect> ActiveEffects { get; } = activeEffects;
        private Hero Hero { get; set; } = hero;

        public void AddActiveEffect(ActiveEffect effect)
        {
            ActiveEffects.Add(effect);
            ApplyStateEffect(effect);
        }

        public int ApplyStatEffect(ActiveEffect effect)//применяем временный эффект
        {
            switch (effect.Type)//проверяем список на наличие значений и применяем их
            {
                case ActiveEffect.EffectTypeEnum.BuffStrength:
                    return effect.Value;
                case ActiveEffect.EffectTypeEnum.BuffAgility:
                    return effect.Value;
                case ActiveEffect.EffectTypeEnum.BuffMaxHp:
                    return effect.Value;
                default:
                    return 0;
            }

        }

        public int GetTotalStatBonus(ActiveEffect.EffectTypeEnum statType)
        {
            return ActiveEffects
                .Where(e => e.Type == statType)
                .Sum(e => ApplyStatEffect(e)); 
        }

        private void ApplyStateEffect(ActiveEffect effect)//применяем временный эффект
        {
            switch (effect.Type)
            {
                case ActiveEffect.EffectTypeEnum.Sleep:
                    Hero.ApplySleep();
                    break;
                default:
                    break;
            }
        }
        private void RemoveStateEffect(ActiveEffect effect)
        {
            switch (effect.Type)
            {
                case ActiveEffect.EffectTypeEnum.Sleep:
                    Hero.WakeUp();
                    break;
            }
        }

        public void TickEffects()//обновляем эффекты каждый тик
        {
            int counter = ActiveEffects.Count;
            for (int i = counter - 1; i >= 0; i--)
            {
                ActiveEffect effect = ActiveEffects[i];
                effect.Tick();
                if (effect.IsEffectOver)
                {
                    RemoveStateEffect(effect);
                    ActiveEffects.Remove(effect);
                }
            }
        }
    }
}
