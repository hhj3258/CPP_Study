%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 쉬프트(shift) 연산, 논리(logiclal) 연산
    ; 게임 서버에서 ObjectID를 만들 때
    mov eax, 0x12345678
    PRINT_HEX 4, eax
    NEWLINE
    shl eax, 8
    PRINT_HEX 4, eax
    NEWLINE
    shr eax, 8
    PRINT_HEX 4, eax
    NEWLINE  
      
    ; not, and, or, xor
    
    ; 조건 A: 잘생겼다(true: 1)
    ; 조건 B: 키가 크다(true: 1)
    
    ; not A: 잘생겼다의 반대 -> (0이면 1, 1이면 0)
    ; A and B: 잘생겼고 and 키도 크고 -> 둘 다 1이면 1, 아니면 0
    ; A or B: 잘생겼거나 or 키가 크거나 -> 둘 중 하나라도 1이면 1, 아니면 0
    ; A xor B: 잘생기고 작거나 or 못생기고 크기나 -> 둘이 같으면 0, 아니면 1
    mov al, 0b10010101
    mov bl, 0b01111100
    
    ; 0b0001 0100 = 0x14
    and al, bl  ; al = al and bl
    PRINT_HEX 1, al
    NEWLINE
    
    ; 0b1110 1011 = 0xEB 
    not al
    PRINT_HEX 1, al
    NEWLINE
    
    ; 응용 사례: bitflag
    
    mov al, 0b10010101
    mov bl, 0b01111100
    NEWLINE
    
    PRINT_HEX 1, al
    NEWLINE
    
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    
    xor al, bl
    PRINT_HEX 1, al
    NEWLINE
    ; 동일한 값으로 xor 두 번하면 자기 자신으로 되돌아오는 특성
    ; 암호학에서 유용하다! (value xor key)
    
    ; mov al, 0
    xor al, al  ; 자기 자신과 xor하면 0, 비트 연산이므로 mov 보다 효율적
    PRINT_HEX 1, al
    
            
    xor rax, rax
    ret

    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1byte) - define byte
    ; dw(2) dd(4) dq(8)


    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 1







