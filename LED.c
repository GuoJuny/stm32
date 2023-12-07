#include "stm32f10x.h"

void LED_Init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//开启GPIOA的时钟
  
  GPIO_InitTypeDef GPIO_InitStructure;//初始化GPIOA和PIN0
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStructure);

  GPIO_SetBits(GPIOA,GPIO_PIN_1 | GPIO_PIN_2);//初始化之后LED默认就是关闭状态了

}

void LED1_ON(void)
{
  GPIO_ResetBits(GPIOA,GPIO_PIN_1)
}

void LED1_OFF(void)
{
  GPIO_SetBits(GPIOA,GPIO_PIN_1)
}
void LED2_ON(void)
{
  GPIO_ResetBits(GPIOA,GPIO_PIN_2)
}

void LED2_OFF(void)
{
  GPIO_SetBits(GPIOA,GPIO_PIN_2)
}
