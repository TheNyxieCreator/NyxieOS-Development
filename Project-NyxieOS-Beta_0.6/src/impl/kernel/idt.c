#include "idt.h"
#include "interrupts.h"

idt_entry_t idt[256];
idt_register_t idt_reg;

extern void load_idt(uint32_t);

void set_idt_gate(int n, uint32_t handler) {
    idt[n].low_offset = handler & 0xFFFF;
    idt[n].sel = 0x08;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;
    idt[n].high_offset = (handler >> 16) & 0xFFFF;
}

void init_idt() {
    idt_reg.base = (uint32_t) &idt;
    idt_reg.limit = sizeof(idt) - 1;

    for (int i = 0; i < 256; i++) {
        set_idt_gate(i, (uint32_t) interrupt_handlers[i]);
    }

    load_idt((uint32_t) &idt_reg);
}
