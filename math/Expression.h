/*
/����c���Ե����ּ���ģ��
/��ӦXML�ڵ�CMP���� <X TYPE="00" CMP="0000[X04X05]*25/255" UNIT="V">��ѹ</X>
/��ȡ������
*/
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  U8 unsigned char

#ifdef __cplusplus
extern "C" {
#endif
	//Save valid digits  ������Ч����
	//str �����ַ��� result ���������� limit �������Чλ��
	//һ�������ַ��� ����С����
	void saveVDigits(const char* str, char* result, U8 limit);
	//
	//str �����ַ��� result ���������� number ��Ч���ݳ��� limit �������Чλ��
	//һ�������ַ��� ������Чλ����С����Чλ��
	void saveVDigits_pro(const char* str, char* result, const U8 number, const U8 limit);
	//
	//hexstr ʮ�������ʲ�ff ee
	//����ʮ����
	unsigned int getDec(const char* hexstr);
	//
	//buffer ʮ���������� result������
	//����ʮ�������ַ���
	void getHexStr(const unsigned char* buffer, const U8 length, char* result);
	//
	//��һ��ʮ�������ַ���ת��һ��ʮ������
	//
	U8 getHex(const char* hexstr);

#ifdef __cplusplus
};
#endif




#endif
