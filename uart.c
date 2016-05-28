#include <stm32f10x.h>

void uart_init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE );

	GPIO_InitTypeDef ur;
	ur.GPIO_Mode=GPIO_Mode_AF_PP;
	ur.GPIO_Pin=GPIO_Pin_9;
	ur.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&ur);
	ur.GPIO_Pin=GPIO_Pin_10;
	ur.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&ur);
	
	
	USART_InitTypeDef us;
	us.USART_BaudRate=9600;
	us.USART_Mode=USART_Mode_Tx;
	us.USART_StopBits=USART_StopBits_1;
	us.USART_Parity=USART_Parity_No;
	us.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&us);
	
	USART_Cmd(USART1,ENABLE);
}
void uart_send(const char * a)
{
	int i=0;int j;
	while(*(a+i)!='\0')
		{USART_SendData(USART1,*(a+i));i++;for(j=1;j<10000;j++);}
}
