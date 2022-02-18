%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; 함수 (어셈블리에서는 프로시저 procedure 또는 서브루틴 subroutine)
    
    ;call PRINT_MSG
    
    mov eax, 10
    mov ebx, 15
    call MAX
    PRINT_DEC 4, ecx
    NEWLINE
           
    
    xor rax, rax
    ret

PRINT_MSG:
    PRINT_STRING msg
    NEWLINE
    ret

    ; ex) 두 값중 더 큰 값을 반환하는 max
    ; 근데 두 값을 어떻게 받지? 반환은?
    ; eax와 ebx 입력 값을 ecx에 반환
MAX:
    cmp eax, ebx
    jg L1
    mov ecx, ebx
    jmp L2
L1:
    mov ecx, eax
L2:
    ret

    ; 그런데 인자가 10개라면 어떻게 할까? a b c d
    ; eax, ebx에 이미 중요한 값이 있으면 어떻게 할까?
    ; [!] .data .bss 사용하면?
    ; 인자를 도대체 몇 개를 할당해야 하지?
    
    ; 다른 메모리 구조가 필요하다
    ; 꿈이 유효한 동안에는 그 꿈을 유지시켜야 함(유효 범위의 개념이 있다)
    ; 꿈이 끝나면 그 꿈을 부셔버려도 됨(정리의 개념이 있다)
    ; 꿈에서도 또 꿈을 꿀 수 있다는 것을 고려해야 함(유동적으로 유효 범위가 확장 가능)
    
    ; [!] 스택(stack)이라는 메모리 영역을 사용
    ; 함수가 사용하는 일종의 메모장
    ; 매개 변수 전달
    ; 돌아갈 주소 관리
    


    ; 초기화 된 데이터
    ; [변수이름] [크기] [초기값]
    ; [크기] db(1byte) - define byte
    ; dw(2) dd(4) dq(8)
section .data
    msg db 'Hello World', 0x00
    
    
    
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
section .bss
    num resb 10







