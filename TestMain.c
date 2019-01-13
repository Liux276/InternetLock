/*************  功能说明    **************

双串口全双工中断方式收发通讯程序。

通过PC向MCU发送数据, MCU收到后通过串口把收到的数据原样返回.

******************************************/
#include "STC_NET.h"

//========================================================================
// 函数: void main(void)
// 描述: 主函数。
// 参数: none.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void main(void)
{
    P0M1 = 0;   P0M0 = 0;   //设置为准双向口
    P1M1 = 0;   P1M0 = 0;   //设置为准双向口
    P2M1 = 0;   P2M0 = 0;   //设置为准双向口
    P3M1 = 0;   P3M0 = 0;   //设置为准双向口
    P4M1 = 0;   P4M0 = 0;   //设置为准双向口
    P5M1 = 0;   P5M0 = 0;   //设置为准双向口
    P6M1 = 0;   P6M0 = 0;   //设置为准双向口
    P7M1 = 0;   P7M0 = 0;   //设置为准双向口

    UART1_config();    // 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer1做波特率.
    EA = 1; //允许总中断
    P16 = 1;
    P47 = 1;
    P46 = 1;
    // while(1){
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
	// 	delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
	// 	delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
	// 	delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     PrintString1(esp_at);
    // }
    // while(!BuffCMP("OK")){
    //     PrintString1("AT\r\n");  //SUART1发送握手连接指令，返回"OK"
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    // }
    // P16 = 0;
    // while(!BuffCMP("OK")&&!BuffCMP("no change")){
    //     PrintString1("AT+CWMODE=1\r\n"); //设置ESP8266的工作模式1 Station，返回"OK"或者"no change"
    //     delay_ms(5000);
    // }
    // P47 = 0;
    // while(!BuffCMP("OK")){
    //     PrintString1("AT+CWJAP=\"ILX\",\"liuxiao123\"\r\n");
    //     delay_ms(7000);
    // }
    // P46 = 0;
    // while(1){
    //     P47 = 1;
    //     PrintString1("AT+CWMODE=1\r\n"); //设置ESP8266的工作模式1 Station，返回"OK"或者"no change"
    //     if(RX1_Buffer[RX1_Cnt-1]=="OK" || RX1_Buffer[RX1_Cnt-1]=="no change"){
    //         P47 = 0;
    //         break;
    //     }
    // }
    // while(1){
    //     P46 = 0;
    //     PrintString1("AT+CWJAP=\"ILX\",\"liuxiao123\"\r\n");
    //     if(++TX1_Cnt >= UART1_BUF_LENGTH)   TX1_Cnt = 0;
    //     delay_ms(1000);
    //     if(RX1_Buffer[RX1_Cnt-1]=="OK" || RX1_Buffer[RX1_Cnt-1]=="no change"){
    //         P46 = 0;
    //         break;
    //     } 
    //     P46 = 1;
    // }
   

    // while (1)
    // {
    //     if((TX1_Cnt != RX1_Cnt) && (!B_TX1_Busy))   //收到数据, 发送空闲
    //     {
    //         SBUF = RX1_Buffer[TX1_Cnt];     //把收到的数据远样返回
    //         B_TX1_Busy = 1;
    //         if(++TX1_Cnt >= UART1_BUF_LENGTH)   TX1_Cnt = 0;
    //     }
    // }
}