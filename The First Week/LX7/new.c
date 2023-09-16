#include <reg51.h>
#include <stdio.h>
#include <stdlib.h>

// 定义LED端口
sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;
sbit LED5 = P1^4;
sbit LED6 = P1^5;
sbit LED7 = P1^6;
sbit LED8 = P1^7;

// 定义开关端口
sbit SW1 = P2^0;
sbit SW2 = P2^1;
sbit SW3 = P2^2;
sbit SW4 = P2^3;

// 函数声明
void delay(unsigned int time);
void displayConstant();
void displaySequence();
void displayBlink();
void displayRandom();

void main() {
    P1 = 0x00; // 初始化P1端口为0
    while (1) {
        if (SW1 == 0) { // 检查开关是否按下（低电平触发）
            displayConstant();
        } else if (SW2 == 0) {
            displaySequence();
        } else if (SW3 == 0) {
            displayBlink();
        } else if (SW4 == 0) {
            displayRandom();
        } else {
            P1 = 0x00; // 如果没有开关按下，关闭所有LED
        }
    }
}

// 延时函数
void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 500; j++);
    }
}

// 常亮模式
void displayConstant() {
    P1 = 0xFF; // 所有LED常亮
}

// 依次点亮模式
void displaySequence() {
    unsigned char pattern = 0x01;
    int i;
    for (i = 0; i < 8; i++) {
        P1 = pattern;
        delay(500); // 延时500毫秒
        pattern <<= 1;
    }
}

// 闪烁模式
void displayBlink() {
    P1 = 0xFF; // 所有LED亮
    delay(500); // 延时500毫秒
    P1 = 0x00; // 所有LED灭
    delay(500); // 延时500毫秒
}

// 随机模式
void displayRandom() {
    unsigned char pattern = 0;
    int i;
    for (i = 0; i < 8; i++) {
        pattern |= (rand() % 2) << i; // 随机生成0或1，并设置对应LED
    }
    P1 = pattern;
    delay(500); // 延时500毫秒
}
