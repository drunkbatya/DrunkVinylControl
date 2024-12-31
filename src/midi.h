#pragma once

#include <stdint.h>

#define MIDI_IN_PORTS_NUM   0x01 // Specify input ports number of your device
#define MIDI_OUT_PORTS_NUM  0x01 // Specify output ports number of your device

#define MIDI_MESSAGE_NOTE_OFF          0x08
#define MIDI_MESSAGE_NOTE_ON           0x09
#define MIDI_MESSAGE_KEY_PRESSURE      0x0A
#define MIDI_MESSAGE_CONTROL_CHANGE    0x0B
#define MIDI_MESSAGE_PROGRAM_CHANGE    0x0C
#define MIDI_MESSAGE_CHANNEL_PRESSURE  0x0D
#define MIDI_MESSAGE_PITCH_BAND_CHANGE 0x0E

void midi_init(void);
void midi_send_message_button(uint8_t btn_id, uint8_t value);
void midi_send_message_encoder(uint8_t enc_id, uint8_t value);
