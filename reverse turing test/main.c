#include "macros.h"
#include <ulk.h>
#include <stdio.h>
int main(void) PROGRAM_ENTRY;
struct PIXEL
{
	unsigned int x;
	unsigned int y;
};
extern struct PIXEL pixel;
extern struct PIXEL ulk_proc_touch_spi_enable(void);
extern struct PIXEL ulk_proc_touch_spi_poll(void);
extern void ulk_proc_touch_spi_disable(void);
int main()
{
	ulk_fpga_clcd_init();
	ulk_fpga_clcd_display_on();
	ulk_fpga_clcd_display_clear();
        ulk_fpga_clcd_cursor_home();
	unsigned int a,b;
	char color[6][10]={"BLACK","RED","BROWN","GREY","PINK"};
	ulk_cpanel_printf("ENTER NUMBER BETWEEN 0-4");
	ulk_scanf_hex(&a);
	ulk_cpanel_printf("\nCLICK THE COLOR DISPLAYED IN LED...!\n");
	ulk_fpga_clcd_display_string(color[a]);
	ulk_proc_touch_spi_enable();
	int row=0,column=0, *address = 0x80500000;
	for(row=0;row<80;row++)
		{
		 for(column=0; column<106; column++)
			{
				*(address+(row*320)+column) = 0x000000;
			}

		}
	for(row=80;row<160;row++)
		{
		for(column=0; column<106; column++)
			{
				*(address+(row*320)+column) = 0x808080;
			}
		}
	for(row=160;row<240;row++)
		{
		for(column=0; column<106; column++)
			{
				*(address+(row*320)+column) = 0xA52A2A;
			}
		}
	for(row=0;row<80;row++)
		{
		for(column=106;column<212; column++)
			{
				*(address+(row*320)+column) = 0xF454C8;
			}
		}
	for(row=0;row<80;row++)
		{
		for(column=212; column<320; column++)
			{
				*(address+(row*320)+column) = 0x00FF00;
			}
		}
	for(row=80;row<160;row++)
		{
		for(column=106.7; column<212; column++)
			{
				*(address+(row*320)+column) = 0xFF0000;
			}
		}
	for(row=80;row<160;row++)
		{
		for(column=212; column<320; column++)
			{
				*(address+(row*320)+column) = 0xFFFFFF;
			}
		}
	for(row=160;row<240;row++)
		{
		for(column=106.7; column<212; column++)
			{
				*(address+(row*320)+column) = 0x54F4EA;
			}
		}
	for(row=160;row<240;row++)
		{
		for(column=212; column<320; column++)
			{
				*(address+(row*320)+column) = 0xFFFF00;
			}
		}
		ulk_proc_touch_spi_disable();
		ulk_fpga_clcd_init();
		ulk_fpga_clcd_display_on();
		ulk_fpga_clcd_display_clear();
		ulk_fpga_clcd_cursor_home();
	
//column-1****************************************************************
	
		if(pixel.x>0 && pixel.x<106 )
			{
			   if(pixel.y>0 && pixel.y<80)
				{
				    ulk_cpanel_printf("you clicked Brown");
				    b=2;
				}
			    if(pixel.y>80 && pixel.y<160)
				{
			    		ulk_cpanel_printf("you clicked gray");
					b=3;
				}
			    if(pixel.y>160 && pixel.y<240)
				{
					ulk_cpanel_printf("you clicked black");
					b=0;
				}
			}
	
//column-2*****************************************************************
	
		if(pixel.x>106 && pixel.x<213 )
			{
			   if(pixel.y>0 && pixel.y<80)
				{
				   ulk_cpanel_printf("you clicked blue");
				    b=6;
				}
			    if(pixel.y>80 && pixel.y<160)
				{
			    		ulk_cpanel_printf("you clicked red");
					b=1;
				}
			    if(pixel.y>160 && pixel.y<240)
				{
					ulk_cpanel_printf("you clicked pink");
					b=4;
				}
			}
	
//column-3******************************************************************
	
		if(pixel.x>212 && pixel.x<320 )
			{
			   if(pixel.y>0 && pixel.y<80)
				{
					ulk_cpanel_printf("you clicked yellow");
				        b=6;
				}
			    if(pixel.y>80 && pixel.y<160)
				{
			    	   	ulk_cpanel_printf("you clicked white");
					b=6;
				}
			    if(pixel.y>160 && pixel.y<240)
				{
					ulk_cpanel_printf("you clicked green");
					b=6;
				}
			}
		 if(a==b)
		 	{
				ulk_cpanel_printf("\nYOU ARE A HUMAN :)");
			}
		 else
		        {
				ulk_cpanel_printf("\nYOU ARE NOT A HUMAN :(");
			}

ulk_fpga_clcd_display_off();
return 0;
}
