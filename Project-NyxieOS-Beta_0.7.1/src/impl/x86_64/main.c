#include "keyboard.h"
#include "interrupts.h"
#include "print.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str("# Welcome to Project NyxieOS Beta!\n");

    // Inicializar a IDT
    init_idt();

    // Inicializar o driver de teclado
    init_keyboard();

    // Loop principal para capturar teclas
    while (1) {
        char key = get_key();
        if (key) {
            print_char(key);
        }
    }
}
