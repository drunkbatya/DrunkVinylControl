#include "core.h"
#include "input.h"
#include "midi.h"

#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    core_init();
    midi_init();
    input_init();

    InputState* previous_state = malloc(sizeof(InputState));
    InputState* current_state = malloc(sizeof(InputState));
    input_get_state(previous_state);
    midi_send_message_button(0, 0);
    while (true) {
        input_get_state(current_state);
        for (uint8_t i = 0; i < InputKeysCount; i++) {
            if (previous_state->button_state[i] != current_state->button_state[i]) {
                midi_send_message_button(i, current_state->button_state[i]);
                previous_state->button_state[i] = current_state->button_state[i];
            }
        }
        for (uint8_t i = 0; i < InputEncodersCount; i++) {
            if (previous_state->encoder_state[i] != current_state->encoder_state[i]) {
                uint8_t enc_direction_up = current_state->encoder_state[i] > previous_state->encoder_state[i];
                midi_send_message_encoder(i, enc_direction_up);
                previous_state->encoder_state[i] = current_state->encoder_state[i];
            }
        }
    }
    free(current_state);
    free(previous_state);
    return 0;
}
