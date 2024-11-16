#include "keyboard.h"
#include <stdint.h>
#include "io.h"
#include "interrupts.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

volatile char last_key = 0;

char scancode_to_char[60] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8',
    '9', '0', '-', '=', '\b', '\t', 'q', 'w', 'e', 'r',
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
    '\'', '`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n',
    'm', ',', '.', '/', 0, '*', 0, ' ', 0
};

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_handler);
}

void keyboard_handler() {
    uint8_t status;
    char keycode;

    status = inb(KEYBOARD_STATUS_PORT);

    if (status & 0x01) {
        keycode = inb(KEYBOARD_DATA_PORT);
        if (keycode >= 0 && keycode < 60) {
            last_key = scancode_to_char[keycode];
        }
    }
}

char get_key() {
    char key = last_key;
    last_key = 0;
    return key;
}
