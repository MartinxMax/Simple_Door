#include<reg51.h>			
#include<intrins.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define uint unsigned int
#define uchar unsigned char
#define LC P1
sbit RS_1602=P0^5;
sbit RW_1602=P0^6;
sbit E_1602=P0^7;
sbit start_button = P0^0;
sbit stop_button = P0^1;
sbit reset_button = P0^2;


#define OUTPUT P2

void Delay100us()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	i = 2;
	j = 15;
	do
	{
		while (--j);
	} while (--i);
}


void delay(uint x)
{
uint i,j;
for(i=x;i>0;i--)
for(j=110;j>0;j--);
}

void Delay50ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 3;
	j = 26;
	k = 223;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



// LCD

void Write_Cmd(uchar cmd)
{
RS_1602=0;
RW_1602=0;
LC=cmd;
delay(5);
E_1602=1;
delay(5);
E_1602=0;
delay(5);
}
void Write_Dat(uchar Dat)
{
RS_1602=1;
RW_1602=0;	 
LC=Dat;   
delay(5);
E_1602=1;
delay(5);
E_1602=0;
delay(5);
}
void LCD1602_init()
{
RW_1602=0;
Write_Cmd(0x38);

Write_Cmd(0x0c);
Write_Cmd(0x06);
Write_Cmd(0x01);
}
void Clear_Display(char chat,int C){
Write_Cmd(0x80+chat);
while(C--){
Write_Dat(0x00);
delay(1);
}
}

void Display(char* STR,char X,Y){
Write_Cmd(0x80+(Y|X));
while(*STR!='\0'){
Write_Dat(*STR++);
}
}
 
///

void convertIntToString(char* str, int num) {
    sprintf(str, "%d", num); // 使用sprintf函数进行格式化输入
}



 
 

int check_exit(){
 if(stop_button==0){
 	delay(2);
	if(stop_button==0){
  	 return 0;		   }
  }
  else{
  	return 1;
  }
}
int check_reset(){
 if(reset_button==0){
 		delay(2);
	 if(reset_button==0){
  	 return 0;
	 }
  }
  else{
  	return 1;
  }
}
void status_finish(){
 Display("--[Finished..]--",0,64);//4 5 6
}
void status_run_display_init(){
Display("--[Ready.....]--",0,64);//4 5 6
}
void status_clean(){
Display("          ",3,64);//4 
}

int scan_bus(){
 
int num = 0;
int position=3;
status_clean();
  	while(1){
	 for(;num<=255;num++){
		 if(check_exit()==0){num = 0;position=3;status_clean();status_run_display_init();return 0;}
		 if(check_reset()==0){num = 0;position=3;status_clean();break;}
		 if(num%25==0){	 
		 Display("/",position++,64);
		 }					 
		 OUTPUT = num;
		 Delay100us();
		}
	   if(num>=255){
	   		status_finish();
			OUTPUT=0xFF;
	   	   	if(check_exit()==0){num = 0;position=3;status_clean();status_run_display_init();return 0;}
		 	if(check_reset()==0){num = 0;position=3;status_clean();break;}
	   }

	}

}




void main(){
 
LCD1602_init();
Display("--Cracking Mod--",0,0);
status_run_display_init();



while(1){
  if(start_button==0){
		delay(2);
	if(start_button==0){
		if(scan_bus()==0){
			status_run_display_init();
			}
		}
  }  
}


}