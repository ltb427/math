/*------------------------------
���ö���������ʽ
2+3*(4-1)=
����ʽ���
-------------------------------*/
#ifndef _CACULATOR_H_
#define _CACULATOR_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __cplusplus
extern "C" {
#endif
	/*-------------------------------------------------
	oring ԭ���ʽ
	---------------------------------------------------*/
	double getResult(const char* oring);
	/*-------------------------------------------------
	oring ԭ���ʽ  result��� limit С����
	---------------------------------------------------*/
	void getResult_s(const char* oring,char* result,const int limit);
#ifdef __cplusplus
}
#endif
#endif