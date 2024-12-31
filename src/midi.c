#include "midi.h"
#include "input.h"
#include "usb_device.h"
#include "usbd_midi.h"

#define MIDI_CHANNEL 0x01
#define MIDI_PORT 0x01

extern USBD_HandleTypeDef hUsbDeviceFS;

void midi_init(void) {
    MX_USB_DEVICE_Init();
}

static uint8_t midi_input_key_codes[InputKeysCount] = {
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57,
    58,
    59
};

static uint8_t midi_input_encoder_up_codes[InputEncodersCount] = {
    60,
    61,
};

static uint8_t midi_input_encoder_down_codes[InputEncodersCount] = {
    62,
    63,
};

void midi_send_message_button(uint8_t btn_id, uint8_t value) {
    uint8_t cmd = MIDI_MESSAGE_NOTE_OFF;
    if(value) cmd = MIDI_MESSAGE_NOTE_ON;

    uint8_t key_code = midi_input_key_codes[btn_id];
    uint8_t velocity = 127;

    uint8_t buf[4] = {
        (MIDI_PORT << 4) | cmd,
        (cmd << 4) | MIDI_CHANNEL,
        key_code,
        velocity
    };
    while (USBD_MIDI_GetState(&hUsbDeviceFS) != MIDI_IDLE) {};
    USBD_MIDI_SendReport(&hUsbDeviceFS, buf, (sizeof(buf) / sizeof(uint8_t)));
}

void midi_send_message_encoder(uint8_t enc_id, uint8_t value) {
    uint8_t cmd = MIDI_MESSAGE_NOTE_ON;

    uint8_t key_code = midi_input_encoder_down_codes[enc_id];
    if (value) {
        key_code = midi_input_encoder_up_codes[enc_id];
    }
    uint8_t velocity = 127;

    uint8_t buf[4] = {
        (MIDI_PORT << 4) | cmd,
        (cmd << 4) | MIDI_CHANNEL,
        key_code,
        velocity
    };
    while (USBD_MIDI_GetState(&hUsbDeviceFS) != MIDI_IDLE) {};
    USBD_MIDI_SendReport(&hUsbDeviceFS, buf, (sizeof(buf) / sizeof(uint8_t)));
}
