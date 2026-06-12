#include <stdio.h>

typedef enum {
    BTN_RELEASED,
    BTN_PRESSED,
    BTN_HELD
} ButtonState;

ButtonState next_state(ButtonState current, int pressed);

int main(void) 
{
    ButtonState s = BTN_RELEASED;
    int events[] = {1, 1, 1, 0, 0, 1, 1};   /* 1 = pressed, 0 = released */
    int n = sizeof(events) / sizeof(events[0]);

    for (int i = 0; i < n; i++) 
    {
        s = next_state(s, events[i]);
        printf("event=%d state=%d\n", events[i], s);
    }
    return 0;
}

/* implement next_state with these transitions:
   - if not pressed: always go to BTN_RELEASED
   - if pressed and currently RELEASED: go to BTN_PRESSED
   - if pressed and currently PRESSED: go to BTN_HELD
   - if pressed and currently HELD: stay in BTN_HELD
*/

   ButtonState next_state(ButtonState current, int pressed) 
   {
        if (!pressed) 
            return BTN_RELEASED;
        
        switch (current) 
        {
            case BTN_RELEASED: 
                return BTN_PRESSED;
            case BTN_PRESSED:
                return BTN_HELD;
            case BTN_HELD:
                return BTN_HELD;
            default:
                return BTN_RELEASED;
        }
    }