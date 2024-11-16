# Encontre todos os arquivos de origem C e ASM
x86_64_c_source_files := $(shell find src/impl/x86_64 -name *.c)
x86_64_c_source_files += src/impl/x86_64/keyboard.c src/impl/x86_64/interrupts.c src/impl/x86_64/idt.c
x86_64_asm_source_files := $(shell find src/impl/x86_64 -name *.asm)
x86_64_asm_source_files += src/impl/x86_64/idt_load.asm

# Crie os arquivos objeto correspondentes
x86_64_c_object_files := $(patsubst src/impl/x86_64/%.c, build/x86_64/%.o, $(x86_64_c_source_files))
x86_64_asm_object_files := $(patsubst src/impl/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

# Todos os arquivos objeto
x86_64_object_files := $(x86_64_c_object_files) $(x86_64_asm_object_files)

# Regras para compilar os arquivos C
build/x86_64/%.o: src/impl/x86_64/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/intf -ffreestanding $(patsubst build/x86_64/%.o, src/impl/x86_64/%.c, $@) -o $@

# Regras para compilar os arquivos ASM
build/x86_64/%.o: src/impl/x86_64/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/impl/x86_64/%.asm, $@) -o $@

# Regra para construir o projeto
.PHONY: build-x86_64
build-x86_64: $(x86_64_object_files)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(x86_64_object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso
