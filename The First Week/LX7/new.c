#include <reg51.h>
#include <stdio.h>
#include <stdlib.h>

// ����LED�˿�
sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;
sbit LED5 = P1^4;
sbit LED6 = P1^5;
sbit LED7 = P1^6;
sbit LED8 = P1^7;

// ���忪�ض˿�
sbit SW1 = P2^0;
sbit SW2 = P2^1;
sbit SW3 = P2^2;
sbit SW4 = P2^3;

// ��������
void delay(unsigned int time);
void displayConstant();
void displaySequence();
void displayBlink();
void displayRandom();

void main() {
    P1 = 0x00; // ��ʼ��P1�˿�Ϊ0
    while (1) {
        if (SW1 == 0) { // ��鿪���Ƿ��£��͵�ƽ������
            displayConstant();
        } else if (SW2 == 0) {
            displaySequence();
        } else if (SW3 == 0) {
            displayBlink();
        } else if (SW4 == 0) {
            displayRandom();
        } else {
            P1 = 0x00; // ���û�п��ذ��£��ر�����LED
        }
    }
}

// ��ʱ����
void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 500; j++);
    }
}

// ����ģʽ
void displayConstant() {
    P1 = 0xFF; // ����LED����
}

// ���ε���ģʽ
void displaySequence() {
    unsigned char pattern = 0x01;
    int i;
    for (i = 0; i < 8; i++) {
        P1 = pattern;
        delay(500); // ��ʱ500����
        pattern <<= 1;
    }
}

// ��˸ģʽ
void displayBlink() {
    P1 = 0xFF; // ����LED��
    delay(500); // ��ʱ500����
    P1 = 0x00; // ����LED��
    delay(500); // ��ʱ500����
}

// ���ģʽ
void displayRandom() {
    unsigned char pattern = 0;
    int i;
    for (i = 0; i < 8; i++) {
        pattern |= (rand() % 2) << i; // �������0��1�������ö�ӦLED
    }
    P1 = pattern;
    delay(500); // ��ʱ500����
}
