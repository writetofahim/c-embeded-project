#include<reg51.h>
#include <stdio.h>
#include <string.h>
sbit red=P1^0;
sbit yellow=P1^1;
sbit green=P1^2;

sbit rs=P1^3;
sbit rw=P1^4;
sbit en=P1^5;
void delay2();
	void lcdcmd(unsigned char val);
	void lcddata(unsigned char val);
  void displayInstruction(int count);
int j;
char north[] = "NORTH OPEN";

void ssd_delay(int y); 

void main(){
	
	red=yellow=green=0;
	while(1){
		displayInstruction(1);
		red=1;
		ssd_delay(1);
		red=0;
		yellow=1;
		ssd_delay(1);
		yellow=0;
		green=1;
		ssd_delay(1);
		green=0;
	}
}
void ssd_delay(int y){
	unsigned char
	ssd[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
	unsigned char x;
	unsigned int i,j;


		for(x=0;x<=y;x++){
		//P3=ssd[x];
		for(i=0;i<35000;i++);
			for(j=0;j<=9;j++){
				P2=ssd[j];
				for(i=0;i<35000;i++);
				if(j==9)
					P2=ssd[0];
				
			}
		}
}

void delay2(){

    unsigned int i;
    for(i=0;i<5000;i++);
}

void lcdcmd(unsigned char val){
    P3=val;
    rs=0;
    rw=0;
    en=1;
    delay2();
    en=0;
}

void lcddata(unsigned char val){
    P3=val;
    rs=1;
    rw=0;
    en=1;
    delay2();
    en=0;
}

void displayInstruction(int count)
{
	lcdcmd(0x01);
	lcdcmd(0x38);delay2();
	lcdcmd(0x80);delay2();
  lcdcmd(0x0C);delay2();
 
	
  
	
		if(count==1){
 		lcdcmd(0xC0);delay2();
        for(j = 0; j < strlen(north); j++) {
          lcddata(north[j]);delay2();
        }
		}	
}