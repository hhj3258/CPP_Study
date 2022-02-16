%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging

    ; 반복문 (while, for)
    ; 특정 조건을 만족할 때까지 반복해서 실행~
    
    ; ex) Hello World를 10번 출력해야 한다면?
    
    mov ecx, 10
    
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx  ; sub ecx, 1과 동일
    cmp ecx, 0
    jne LABEL_LOOP
    
    ; 연습 문제) 1에서 100까지의 합을 구하는 프로그램
    mov ecx, 0
    mov eax, 0
    
LABEL_SUM_LOOP:
    inc ecx  ; ecx += 1
    add eax, ecx
    cmp ecx, 100
    jne LABEL_SUM_LOOP
    
    PRINT_DEC 4, eax
    NEWLINE
    
    ; loop [라벨]
    ; ecx에 반복 횟수
    ; loop 할 때마다 ecx 1 감소. 0이면 빠져나감. 아니면 라벨로 이동
    mov ecx, 100
    xor ebx, ebx  ; ebx: 결과물
    
LABEL_LOOP_SUM:
    add ebx, ecx
    loop LABEL_LOOP_SUM

    PRINT_DEC 4, ebx
    NEWLINE    
                  
    xor rax, rax
    ret

    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1byte) - define byte
    ; dw(2) dd(4) dq(8)
;section .data
    msg db 'Hello World', 0x00
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 1







