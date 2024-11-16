section .text
global putpixel, drawline, fillrect

; Função para desenhar um pixel na tela
putpixel:
    ; entrada: cx = x, dx = y, al = cor
    push rax
    push rbx
    push rcx
    push rdx
    mov ah, 0x0C    ; Função 0Ch da BIOS: Ponto de pixel
    mov bh, 0x00    ; Página de vídeo
    int 0x10        ; Chamar a interrupção de vídeo da BIOS
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

; Função para desenhar uma linha na tela
drawline:
    ; entrada: cx1, dx1 = coordenadas de início, cx2, dx2 = coordenadas de fim, al = cor
    ; Implementação do algoritmo de Bresenham para desenhar linhas

fillrect:
    ; entrada: cx = x, dx = y, si = largura, di = altura, al = cor
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
.fill_loop_y:
    mov cx, si
.fill_loop_x:
    call putpixel
    inc cx
    loop .fill_loop_x
    add dx, 1
    loop .fill_loop_y
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret
