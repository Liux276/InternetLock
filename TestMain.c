#include "STC_NET.h"

void main(void)
{
    P0M1 = 0;
    P0M0 = 0; //设置为准双向口
    P1M1 = 0;
    P1M0 = 0; //设置为准双向口
    P2M1 = 0;
    P2M0 = 0; //设置为准双向口
    P3M1 = 0;
    P3M0 = 0; //设置为准双向口
    P4M1 = 0;
    P4M0 = 0; //设置为准双向口
    P5M1 = 0;
    P5M0 = 0; //设置为准双向口
    P6M1 = 0;
    P6M0 = 0; //设置为准双向口
    P7M1 = 0;
    P7M0 = 0; //设置为准双向口

    UART1_config(); // 选择波特率
    EA = 1;         //允许总中断
    P16 = 1;
    P47 = 1;
    P46 = 1;
    delay_ms(500);
    ATConnect();
    ATMode();
    ATWifi("test","test123456");
    TCPConnect("172.18.32.6","3333");
    TCPSend("hello world!");
    while(1){
        delay_ms(500);
        if(BuffCMP("+IPD,4:http")){
            P46 = 0;
        }
    }
}