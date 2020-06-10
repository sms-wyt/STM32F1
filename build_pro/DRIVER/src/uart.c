#include "uart.h"

//����1��ʼ������
void uart1_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;//����GPIO�ṹ��
    USART_InitTypeDef uart_struct;//����UART�ṹ��
    
    //ʹ������ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//ʹ��UART1����ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//ʹ��UART1����ʱ��
    
    USART_DeInit(USART1);//��λ����1
    
    //IO�˿ڸ��ù�������
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP; //���츴�������TX�������ţ�
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);//��ʼ��PA9Ϊ���츴�����?
    
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
    GPIO_Init(GPIOA, &GPIO_InitStruct);//��ʼ��PA10Ϊ��������
    
    //���ڲ�������
    uart_struct.USART_BaudRate = 115200;
    uart_struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    uart_struct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    uart_struct.USART_Parity = USART_Parity_No;
    uart_struct.USART_StopBits = USART_StopBits_1;
    uart_struct.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &uart_struct);
    
    USART_Cmd(USART1,ENABLE);//ʹ�ܴ���1����
}

//���ڷ��ͺ���
//ע�⣺STM32���ڷ��ͱ����ȼ��״̬�������һ���ֽ��޷�������������ϣ������ⷢ��״̬�Ƿ���ɣ����򣬷��Ͳ��ɹ�
//��һ���ȡSR�Ĵ������ڶ���дDR�Ĵ��� �պ������TC��־λ ����һ��whileѭ������������
void Uart_write(u8 *pBuf,u8 ulLen)
{
    u8 i = 0;
    USART1->SR;//��ȡSR�Ĵ���
    for(i = 0; i < ulLen; i++)
    { 
       USART_SendData(USART1,*pBuf);//����һ���ֽ�
       while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); //����Ƿ������
       pBuf++; //����ָ��ָ����һ������
    }
}

void vprint(const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string,fmt,argp)) // build string
    {
        Uart_write((u8*)string, strlen(string));
    }
}

//printf����
void printfs(char*fmt,...)
{  
    /*va_list argp;
    va_start(argp, fmt);
    vprint(fmt, argp);
    va_end(argp);*/
    //printf("nn\n");
    
}	