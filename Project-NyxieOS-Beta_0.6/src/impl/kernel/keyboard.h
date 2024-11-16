#pragma once
#include <stdint.h>

extern volatile char last_key;
extern char scancode_to_char[60];

void init_keyboard();
void keyboard_handler();
char get_key();
