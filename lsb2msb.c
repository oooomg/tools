// 大小端转换

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/types.h>
 
uint16_t swapInt16(uint16_t value)  
{  
    int i =0;
    uint16_t coverd = 0;

    unsigned  int mask = 0;
    unsigned int masked[16] = {0,};

// store the flags 
    for(i=0; i<16; i++){
        mask = (0x01 << i);
        masked[i] = (value & mask) >> i;
     
        printf("masked[%d] is %x  \n",i, masked[i]);
   }


// flage*weight
   for(i = 15; i >= 0; i --){
       coverd = coverd + (masked[i] <<(15-i));
        printf("coverd is %x\n", coverd);
   }


    return coverd;
}  


int main(void){
    
    uint16_t  input_data = 0xaa11;
    printf("converted data is %x\n",swapInt16(input_data));   

    return 0;
}