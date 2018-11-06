#ifndef __STC_NET_H__
#define __STC_NET_H__
#include "Common.h"
void UART1_config();   // 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer1做波特率.
void PrintString1(u8 *); //发送数据到单片机串
//========================================================================
// 函数: void PrintString1(u8 *puts)
// 描述: 串口1发送字符串函数。
// 参数: puts:  字符串指针.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void PrintString1(u8 *puts) //发送一个字符串
{
    for (; *puts != 0;  puts++)     //遇到停止符0结束
    {
        SBUF = *puts;
        B_TX1_Busy = 1;
        while(B_TX1_Busy);
    }
}
//========================================================================
// 函数: void   UART1_config(u8 brt)
// 描述: UART1初始化函数。
// 参数: brt: 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer1做波特率.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void    UART1_config(u8 brt)    // 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer1做波特率.
{
    /*********** 波特率使用定时器1 *****************/
    //115200bps@11.0592MHz
    SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
	TL1 = 0xE8;		//设定定时初值
	TH1 = 0xFF;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
    /*************************************************/
//  PS  = 1;    //高优先级中断
    ES  = 1;    //允许中断
    REN = 1;    //允许接收
    P_SW1 &= 0x3f;
    P_SW1 |= 0x80;      //UART1 switch to, 0x00: P3.0 P3.1, 0x40: P3.6 P3.7, 0x80: P1.6 P1.7 (必须使用内部时钟)
//  PCON2 |=  (1<<4);   //内部短路RXD与TXD, 做中继, ENABLE,DISABLE

    B_TX1_Busy = 0;
    TX1_Cnt = 0;
    RX1_Cnt = 0;
}


//========================================================================
// 函数: void UART1_int (void) interrupt UART1_VECTOR
// 描述: UART1中断函数。
// 参数: nine.
// 返回: none.
// 备注: 
//========================================================================
void UART1_int (void) interrupt 4
{
    if(RI)
    {
        RI = 0;
        RX1_Buffer[RX1_Cnt] = SBUF;
        if(++RX1_Cnt >= UART1_BUF_LENGTH)   RX1_Cnt = 0;    //防溢出
    }

    if(TI)
    {
        TI = 0;
        B_TX1_Busy = 0;
    }
}
//========================================================================
// 函数: void  delay_ms(u8 ms)
// 描述: 延时函数。
// 参数: ms,要延时的ms数, 这里只支持1~255ms. 自动适应主时钟.
// 返回: none.
// 备注: 
//========================================================================
void  delay_ms(u8 ms)
{
     u16 i;
     do{
          i = MAIN_Fosc / 13000;
          while(--i)    ;   //14T per loop
     }while(--ms);
}
#endif
//=========================================================================
//函数：bool BuffCMP(u8* cmp)
//参数：用来比对缓冲区的字符串cmp
//返回：布尔值
bit BuffCMP(u8* cmp){
    u8 i;
    for(i = 0;i<32 && *cmp!=0;i++,cmp++){
        if(TX1_Cnt == RX1_Cnt || *cmp != RX1_Buffer[TX1_Cnt]){
            TX1_Cnt = RX1_Cnt;
            return 0;
        }
        if(++TX1_Cnt >= UART1_BUF_LENGTH)   TX1_Cnt = 0;
    }
    return 1;
}
//===============================
bit ATConnect(){
    PrintString1("AT\r\n");
    return 1;
}
//==============================
bit ATMode(u8 mode){
    PrintString1("AT+CWMODE=1\r\n");
    return 1;
}
//===============================
bit ATWifi(u8* name,u8* password){
    PrintString1("AT+CWJAP=\"lxx\",\"liuxiao123\"\r\n");
    return 1;
}