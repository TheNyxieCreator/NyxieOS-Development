#include <stdint.h>
#include "interrupts.h"
#include "idt.h"

void (*interrupt_handlers[256])(void);

void register_interrupt_handler(int irq, void (*handler)(void)) {
    interrupt_handlers[irq] = handler;
}

void init_idt() {
    idt_register_t idt_reg;
    idt_entry_t idt[256];

    idt_reg.base = (uint32_t) &idt;
    idt_reg.limit = sizeof(idt) - 1;

    for (int i = 0; i < 256; i++) {
        interrupt_handlers[i] = 0;
        set_idt_gate(i, (uint32_t) interrupt_handlers[i]);
    }

    load_idt((uint32_t) &idt_reg);
}
