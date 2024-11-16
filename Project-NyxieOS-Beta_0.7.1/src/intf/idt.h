#pragma once
#include <stdint.h> // Para uint32_t

typedef struct {
    uint16_t low_offset;   // Offset bits 0-15
    uint16_t sel;          // Selector
    uint8_t always0;       // Always 0
    uint8_t flags;         // Flags
    uint16_t high_offset;  // Offset bits 16-31
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_register_t;

void init_idt();
void set_idt_gate(int n, uint32_t handler);
