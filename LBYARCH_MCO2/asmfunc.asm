section .text
bits 64
default rel

global dotProduct

dotProduct:
    xorpd xmm0, xmm0 ; Clear xmm0
    ; rcx already contains *X
    ; rdx already contains *Y
    mov     rsi, r8            ; size

dot_loop:
    movsd  xmm2, [rcx]         ; Load X into xmm2
    movsd  xmm3, [rdx]         ; Load Y into xmm3

    mulsd   xmm2, xmm3          ; X * Y
    addsd   xmm0, xmm2          ; Accumulate

    add     rcx, 8             ; Move pointer to next element in X
    add     rdx, 8             ; Move pointer to next element in Y

    dec     rsi                 ; Decrement loop counter
    jnz     dot_loop            ; Jump if not zero
    ret
