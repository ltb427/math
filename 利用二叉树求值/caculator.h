/*------------------------------
利用二叉树求表达式
2+3*(4-1)=
波兰式求解
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
	oring 原表达式
	---------------------------------------------------*/
	double getResult(const char* oring);
	/*-------------------------------------------------
	oring 原表达式  result结果 limit 小数点
	---------------------------------------------------*/
	void getResult_s(const char* oring,char* result,const int limit);
#ifdef __cplusplus
}
#endif
#endif