/*************  ����˵��    **************

˫����ȫ˫���жϷ�ʽ�շ�ͨѶ����

ͨ��PC��MCU��������, MCU�յ���ͨ�����ڰ��յ�������ԭ������.

******************************************/
#include "STC_NET.h"

//========================================================================
// ����: void main(void)
// ����: ��������
// ����: none.
// ����: none.
// �汾: VER1.0
// ����: 2014-11-28
// ��ע: 
//========================================================================
void main(void)
{
    P0M1 = 0;   P0M0 = 0;   //����Ϊ׼˫���
    P1M1 = 0;   P1M0 = 0;   //����Ϊ׼˫���
    P2M1 = 0;   P2M0 = 0;   //����Ϊ׼˫���
    P3M1 = 0;   P3M0 = 0;   //����Ϊ׼˫���
    P4M1 = 0;   P4M0 = 0;   //����Ϊ׼˫���
    P5M1 = 0;   P5M0 = 0;   //����Ϊ׼˫���
    P6M1 = 0;   P6M0 = 0;   //����Ϊ׼˫���
    P7M1 = 0;   P7M0 = 0;   //����Ϊ׼˫���

    UART1_config();    // ѡ������, 2: ʹ��Timer2��������, ����ֵ: ʹ��Timer1��������.
    EA = 1; //�������ж�
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
    //     PrintString1("AT\r\n");  //SUART1������������ָ�����"OK"
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    //     delay_ms(250);
    // }
    // P16 = 0;
    // while(!BuffCMP("OK")&&!BuffCMP("no change")){
    //     PrintString1("AT+CWMODE=1\r\n"); //����ESP8266�Ĺ���ģʽ1 Station������"OK"����"no change"
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
    //     PrintString1("AT+CWMODE=1\r\n"); //����ESP8266�Ĺ���ģʽ1 Station������"OK"����"no change"
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
    //     if((TX1_Cnt != RX1_Cnt) && (!B_TX1_Busy))   //�յ�����, ���Ϳ���
    //     {
    //         SBUF = RX1_Buffer[TX1_Cnt];     //���յ�������Զ������
    //         B_TX1_Busy = 1;
    //         if(++TX1_Cnt >= UART1_BUF_LENGTH)   TX1_Cnt = 0;
    //     }
    // }
}