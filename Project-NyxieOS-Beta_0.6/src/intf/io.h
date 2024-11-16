#pragma once
#include <stdint.h>

// Função para ler um byte de uma porta de I/O
static inline uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ __volatile__("inb %1, %0" : "=a"(result) : "dN"(port));
    return result;
}

// Função para escrever um byte em uma porta de I/O
static inline void outb(uint16_t port, uint8_t data) {
    __asm__ __volatile__("outb %0, %1" : : "a"(data), "dN"(port));
}
