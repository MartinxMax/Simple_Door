#include<reg51.h>
#include<intrins.h>
#define KEY P1
sbit LED=P0^0;
// Max 0x7F
const char PASSWORD[1]={0x12};

void Delay1000ms()	 
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main(){
KEY=0xFF;
 
 		  	
while(1){
if(KEY==PASSWORD[0]){
 LED=1 ;
 Delay1000ms();

}else{
  LED=0;
}
}
}