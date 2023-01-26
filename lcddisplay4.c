#include<reg51.h>
#include <stdio.h>
#include <string.h>

sbit S1 = P0^7;
sbit S2 = P2^7;

sbit north_red = P1^0;
sbit north_yellow = P1^1;
sbit north_green = P1^2;

sbit south_red = P1^3;
sbit south_yellow = P1^4;
sbit south_green = P1^5;

sbit east_red = P1^6;
sbit east_yellow = P1^7;
sbit east_green = P2^0;

sbit west_red = P2^1;
sbit west_yellow = P2^2;
sbit west_green = P2^3;
sbit rs=P2^4;
sbit rw=P2^5;
sbit en=P2^6;

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void delay(unsigned int time);
void displayOpen();

int j;
char full_name[] = "NOTHING";
char south[] = "SOUTH OPEN";
char north[] = "NORTH OPEN";
char east[] = "EAST OPEN";
char west[] = "WEST OPEN";

void delay2(){
    unsigned int i;
    for(i=0;i<5000;i++);
}

void displayOpen(int count){
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


       if(count==2){
 		lcdcmd(0xC0);delay2();
        for(j = 0; j < strlen(south); j++) {
          lcddata(south[j]);delay2();
        }
	   }

	   if(count==3){
 lcdcmd(0xC0);delay2();
        for(j = 0; j < strlen(east); j++) {
          lcddata(east[j]);delay2();
        }
	   }

	   if(count==4){
		lcdcmd(0xC0);delay2();
        for(j = 0; j < strlen(west); j++) {
          lcddata(west[j]);delay2();
        }
	   }
		delay2();delay2();
    	//lcdcmd(0x01);delay();
}

void delay3(unsigned int time) 
{
	
    unsigned int i, j;
    for(i=0; i<time; i++)
        for(j=0; j<1275; j++);
}

void delay(unsigned int time) 
{
	
  
	unsigned char seg[10]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
	unsigned char x;
	int num1,num2;
	
	P0=0x00;
		for(x=time; x<=time; x--){
			
			//P0=seg[x];
			//delay3(150);
			num1 = x/10;   
			S1 = 1;					
			S2 = 0;
			P0 = seg[num1];  
			delay3(150);

			
			num2 = x%10;    
			S1 = 0;					
      S2 = 1;
			P0 = seg[num2];
			delay3(150);
		}
}

void main(){
	
    P3=0x00;
    while(1)
    {		
			north_red=1;
			north_green=north_yellow=0;
			south_red=1;
			south_green=south_yellow=0;
			east_red=1;
			east_green=east_yellow=0;
			west_red=1;
			west_green=west_yellow=0;
			
        // open north
        north_red = 0;
				north_yellow=0;
        north_green = 1;
				displayOpen(1);
				delay(9);
				east_red = 0;
				east_yellow=1;
				delay(4);
				north_green = 0;
				north_red = 1;
				
				// open east
        east_red = 0;
				east_yellow=0;
        east_green = 1;
				displayOpen(2);
				delay(9);
				south_red = 0;
				south_yellow=1;
				delay(4);
				east_green = 0;
				east_red = 1;
				
			
				// open south
				south_red = 0;
				south_yellow=0;
        south_green = 1;
				displayOpen(3);
				delay(9);
				west_red = 0;
				west_yellow=1;
				delay(4);
				south_green = 0;
				south_red = 1;
				
				// open west
				west_red = 0;
				west_yellow=0;
        west_green = 1;
				displayOpen(4);
				delay(9);
				north_red = 0;
				north_yellow=1;
				delay(4);
				west_green = 0;
				west_red = 1;	
    }
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

