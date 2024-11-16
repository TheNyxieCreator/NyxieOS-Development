#pragma once
#include <stdint.h>

#define IRQ0 32
#define IRQ1 33

extern void (*interrupt_handlers[256])(void);

void register_interrupt_handler(int irq, void (*handler)(void));
void init_idt();
void set_idt_gate(int n, uint32_t handler);
