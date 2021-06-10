/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-06-02 19:21:59
 @FilePath     : /1.c
 @Description  : message
*********************************************/
#include <S3C2440.H>

#define rGPBCON (*(volatile unsigned *)0x56000010) //Port B control
#define rGPBDAT (*(volatile unsigned *)0x56000014) //Port B data
#define rGPBUP (*(volatile unsigned *)0x56000018)  //Pull-up control B

#define LED1_ON (rGPBDAT &= ~(1 << 5)) //GPB5 位清0
#define LED1_OFF (rGPBDAT |= (1 << 5)) //GPB5 位置1
#define LED2_ON (rGPBDAT &= ~(1 << 6))
#define LED2_OFF (rGPBDAT |= (1 << 6))
#define LED3_ON (rGPBDAT &= ~(1 << 7))
#define LED3_OFF (rGPBDAT |= (1 << 7))
#define LED4_ON (rGPBDAT &= ~(1 << 8))
#define LED4_OFF (rGPBDAT |= (1 << 8))

void delay(void)
{
    int i, j;
    for (i = 0; i < 10000; i++)
    {
        for (j = 0; j < 50; j++)
            ;
    }
}

int Main()
{
    rGPBCON &= ~((3 << 10) | (3 << 12) | (3 << 14) | (3 << 16)); //对GPBCON[10:17]清零
    // rGPBCON |= ((1 << 10) | (1 << 12) | (1 << 14) | (1 << 16));  //设置GPB5~8为输出
    rGPBCON = 0x155551;                                     //设置GPB5~8为输出
    rGPBUP &= ~((1 << 5) | (1 << 6) | (1 << 7) | (1 << 8)); //设置GPB5~8的上拉功能
    rGPBDAT |= (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8);   //关闭LED

    while (1)
    {
        if ((rGPBDAT & 0x01) = 0x01)
        {
            LED1_ON;
            delay();
            LED1_OFF;
            LED2_ON;
            delay();
            LED2_OFF;
            LED3_ON;
            delay();
            LED3_OFF;
            LED4_ON;
            delay();
            LED4_OFF;
        }
        else
        {
            LED4_ON;
            delay();
            LED4_OFF;
            LED3_ON;
            delay();
            LED3_OFF;
            LED2_ON;
            delay();
            LED2_OFF;
            LED1_ON;
            delay();
            LED1_OFF;
        }
    }
    return 0;
}