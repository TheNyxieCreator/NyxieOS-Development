global load_idt
section .text
load_idt:
    lidt [esp+4]
    ret