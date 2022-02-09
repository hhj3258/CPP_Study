%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging

    PRINT_STRING msg

    xor rax, rax
    ret

    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1byte) - define byte
    ; dw(2) dd(4) dq(8)
section .data
    msg db 0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,0x6c,0x64,0x00
    
    a db 0x11, 0x11, 0x11, 0x11   ; [변수이름] [크기] [초기값]
    
    b dd 0x12345678 ; 순서가 78 56 34 12로 저장됨, Little-Endian
    ; 장단점
    ; - 빅 엔디안 : 숫자 비교에 유리
    ; - 리틀 엔디안 : 캐스팅에 유리하다( 78(1byte)만 꺼내고 싶다 )


    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    e resb 10













