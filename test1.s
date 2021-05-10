    AREA MOV_TEST,CODE,READONLY
    ENTRY
    CODE32
    MOVS R2,#0x0
    MOV R1,#01
    CMP R2,R1
    MOVEQ R2,R1
    MOV R0,R1,LSL #3

    END 

    MOV R1,#0xF5
    AND R0,R1,#0X07

    MOV R1,#0xf5
    MOV R2,#0x00
    ANDS R0,R1,R2

    MOV R1,#0x01
    EOR R0,R1,#0X0F

    MOV R1,#0x01
    MOV R2,#0x0F
    EOR R0,R1,R2

    MOV R1,#0x01
    MOV R2,#0x00
    SUBS R0,R1,R2

    MOV R1,#0x01
    MOV R2,#0x00
    CMP R2,R1
    SUBNE R0,R2,R1,LSL #3

    MOV R1,#0x0f
    CMP R1,#0x0f
    SUBEQ R0,R1,#3

    MOV R1,#0x0F
    MOV R2,#0x00
    RSBS R0,R2,R1

@ N  当用两个补码表示的带符号数进行运算时，N=1表示运算的结果为负数；N=0表示运算的结果为正数或零.
@ Z  Z=1表示运算的结果为零，Z=0表示运算的结果非零。
@ C  可以有4种方法设置C的值：
@    加法运算（包括CMN）：当运算结果产生了进位时（无符号数溢出），C=1，否则C=0。
@    减法运算（包括CMP）：当运算时产生了借位时（无符号数溢出），C=0，否则C=1。
@    对于包含移位操作的非加/减运算指令，C为移出值的最后一位。
@    对于其它的非加/减运算指令，C的值通常不会改变。
@ V  可以有2种方法设置V的值：
@    对于加减法运算指令，当操作数和运算结果为二进制的补码表示的带符号数时，V=1表示符号位溢出
@    对于其它的非加/减运算指令，V的值通常不会改变。

    MOV R1,#0x01
    MOV R2,#0x00
    CMP R1,R2
    RSBNES R0,R1,R1,lsl #1

MOV R1,#0x01
ADDS R0,R1,R1,lsl #1

MOV R1,#0x01
ADDS R0,R1,#0x03

MOV R1,#0x01
ADCS R0,R1,R1

MOV R1,#0x01
MOV R2,#0x00
SBCS R0,R1,R2