
#include "stm32f10x.h"

void Key_init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启GPIOA的时钟
  
  GPIO_InitTypeDef GPIO_InitStructure;//初始化GPIOA和PIN0
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStructure);

}

uint8_t Ket_GetNum(void)
{
  uint8_t KeyNum=0;
  if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0){
    Delay_ms(20);
    while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0);
    Delay_ms(20);
    KeyNum=1;
  }
 if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0){
    Delay_ms(20);
    while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0);
    Delay_ms(20);
    KeyNum=2;
  }


}
