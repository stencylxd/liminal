using static LiminalGame.General;

namespace LiminalGame
{
    public static class Transitions
    {
        public enum Transition { 
            None = -1,
            StartButtonToPlayer = 0;
        }

        public static Transition CurrentTransition;

        public static void SetTransitionActive(Transition TransitionType)
        {
            CurrentTransition = TransitionType;
            return;
        }
        
        public static void T_StartButtonToPlayer() {
            return;
        }
    }
}