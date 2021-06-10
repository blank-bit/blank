/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-06-02 19:28:01
 @FilePath     : /2.c
 @Description  : message
*********************************************/
#include <stdlib.h>
#include <string.h>
#include <S3C2440.H>
#include "2440addr.h"

#define U32 unsigned int

static void __irq Key_ISR(void);

void delay()
{
    int i, j;
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 50; j++)
            ;
    }
}

void key_init(void)
{
    //设置EINT[8]-EINT[13]为中断

    //设置EINT[8]-EINT[13]为边沿触发

    //清EINTPEND对应的标志位为0

    //设置EINT[8]-EINT[13]的屏蔽标志位，使能对应的外中断

    //把编写的按键中断服务程序的入口地址写入到 IRQ中断向量表中对应的外中断（EINT8_23）的存储单元中。

    //使能按键中断对应的一级屏蔽标志位（EINT8_23）。
}

void LED_init(void)
{
    //正确配置LED对应的端口
    rGPBCON &= ~((3 << 10) | (3 << 12) | (3 << 14) | (3 << 16)); //对GPBCON[10:17]清零
    rGPBCON |= ((1 << 10) | (1 << 12) | (1 << 14) | (1 << 16));  //设置GPB5~8为输出
    rGPBUP &= ~((1 << 5) | (1 << 6) | (1 << 7) | (1 << 8));      //设置GPB5~8的上拉功能
}

void button1press() //点亮LED1
{
    rGPBDAT &= ~(1 << 5);
}

void button2press() //点亮LED2
{
    rGPBDAT &= ~(1 << 6);
}

void button3press() //点亮LED3
{
    rGPBDAT &= ~(1 << 7);
}

void button4press() //点亮LED4
{
    rGPBDAT &= ~(1 << 8);
}

void button5press() //点亮所有LED
{
    rGPBDAT &= ~(1 << 5);
    rGPBDAT &= ~(1 << 6);
    rGPBDAT &= ~(1 << 7);
    rGPBDAT &= ~(1 << 8);
}

void button6press() //关闭所有LED
{
    rGPBDAT |= ~(1 << 5);
    rGPBDAT |= ~(1 << 6);
    rGPBDAT |= ~(1 << 7);
    rGPBDAT |= ~(1 << 8);
}

static void __irq Key_ISR(void) //定义中断服务程序
{
    //首先判断，中断是否是由对应的EINT8_23所引起的？如果是，才做进一步处理

    //如果中断中是由对应的EINT8_23所引起的，然后再进一步判断，中断是由EINT8_23中的哪一个外中断所引起的，并根据判断的结果，进一步调用对应的按键处理程序，进行按键响应。
    //注：在调用按键响应前，应当先相关标志位清0。具体步骤是：把EINTPEND中对应的标志位清0，在把SRCPND、INTPND对应标志为清0.
    //实验证明，如果不先清零EINTPEND，而是先清零SRCPND、INTPND对应标志为。EINTPEND对应的标志位会再次引起SRCPND、INTPND对应标志位置1，从而导致第二次中断，第二次中断后，由于第一次中断中清理了EINTPEND的标志位，所以不会引起第3次中断。
}

int main()
{
    LED_init();
    key_init();
    while (1)
    {
        delay();
        delay();
    }
}
