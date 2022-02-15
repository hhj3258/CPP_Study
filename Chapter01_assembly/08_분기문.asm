%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging

    ; 분기문 (if)
    ; 특정 조건에 따라서 코드 흐름을 제어하는 것
    ; ex) 스킬 버튼 눌렀는가? YES -> 스킬 사용
    ; ex) 제한 시간 내에 던전 입장 수락 버튼을 눌렀는가? YES -> 입장, NO -> 던전 취소
    
    ; 조건 -> 흐름
    
    ; CMP(compare) dst, src (dst가 기준)
    ; 비교를 한 결과물은 Flag Register 저장
    
    ; JMP [label] 시리즈
    ; JMP : 무조건 jump
    ; JE : JumpEquals 같으면 jump
    ; JNE : JumpNotEquals 다르면 jump
    ; JG : JumpGreater 크면 jump
    ; JGE : JumpGreaterEquals 크거나 같으면 jump
    ; JL, JLE ...
    
    ; 두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램
    mov rax, 10
    mov rbx, 10
    
    cmp rax, rbx  ; 비교
    je LABEL_EQUAL ; JumpEquals
    
    ;je에 의해 점프를 안했다면, 같이 않다는 의미
    mov rcx, 0
    jmp LABEL_EQUAL_END ;Jump
    
LABEL_EQUAL:
    mov rcx, 1
    
LABEL_EQUAL_END:
    PRINT_HEX 1, rcx
    NEWLINE
    
    ; 연습 문제 : 어떤 숫자(1~100)가 짝수면 1, 홀수면 0을 출력하는 프로그램
    mov ax, 50
    mov bl, 2

    div bl
    
    cmp ah, 0
    je LABEL_EVEN
    
    PRINT_STRING 'ODD'
    jmp LABEL_END
    
LABEL_EVEN:
    PRINT_STRING 'EVEN'
LABEL_END:
    
                            
    xor rax, rax
    ret

    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1byte) - define byte
    ; dw(2) dd(4) dq(8)
;section .data

    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 1







