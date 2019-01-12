//RCC register
#define RCC_(x) (*(volatile unsigned long *)(RCC_BASE+x))

#define RCC_BASE 0x40021000
#define RCC_CR (*(volatile unsigned long *)(RCC_BASE))
#define RCC_CFGR (*(volatile unsigned long *)(RCC_BASE+0x4))
#define RCC_CIR (*(volatile unsigned long *)(RCC_BASE+0x8))
#define RCC_APB2ENR (*(volatile unsigned long *)(RCC_BASE+0x18))
#define RCC_APB2RSTR (*(volatile unsigned long *)(RCC_BASE+0x0c))

#define GPIOC_BASE 0x40011000
#define GPIOC_CRH   (*(volatile unsigned short *)(GPIOC_BASE+0x04))
#define GPIOC_ODR   (*(volatile unsigned short *)(GPIOC_BASE+0x0c))
int ymj_main(){
#if 1
    int i;
int value[]={
  0x03034a83,
  0x001d040a,
  0,
  0,
  0,
  14,
  0x0000401d,
  0,
  0,
  0x0c000000
};
    for(i=0;i<=0x24;i+=4){
        RCC_(i) =value[i/4];
    }
    GPIOC_CRH = 0x2222;  // pin13 out 50Mhz
        GPIOC_ODR = 0;
while(1){
    GPIOC_ODR  = 0xffff;
    for(i=0;i<1000000;i++);
    GPIOC_ODR = 0;
    for(i=0;i<1000000;i++);
}
#else
#define GPIOC_BRR   (*(volatile unsigned short *)(GPIOC_BASE+0x14))
    int i;
    int ii,j;
int value[]={
  0x03034a83,
  0x001d040a,
  0,  
  0,  
  0,  
  14, 
  0x0000401d,
  0,  
  0,  
  0x0c000000
};
    for(i=0;i<=0x24;i+=4){
        RCC_(i) =value[i/4];
    }   
    GPIOC_CRH = 0x2222;  // pin13 out 50Mhz
while(1)
{
        GPIOC_ODR = 0;
}
#endif
return 0;
}
