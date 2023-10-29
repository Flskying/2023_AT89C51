#ifndef LCD_H
#define LCD_H


#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define out P0
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;

void lcd_initial(void);//初始化
void check_busy(void);//检查忙标志位函数
void write_command(uchar com);//写命令函数
void write_data(uchar dat);//写数据函数
void string(uchar ad,uchar *s);//显示字符串函数
void delay(unit);//延时函数


#endif