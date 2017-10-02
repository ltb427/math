/*
/基于c语言的数字计算模块
/对应XML节点CMP属性 <X TYPE="00" CMP="0000[X04X05]*25/255" UNIT="V">电压</X>
/获取计算结果
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
	//Save valid digits  保存有效数字
	//str 输入字符串 result 保存输出结果 limit 保存的有效位数
	//一个数字字符串 控制小数点
	void saveVDigits(const char* str, char* result, U8 limit);
	//
	//str 输入字符串 result 保存输出结果 number 有效数据长度 limit 保存的有效位数
	//一个数字字符串 控制有效位数和小数有效位数
	void saveVDigits_pro(const char* str, char* result, const U8 number, const U8 limit);
	//
	//hexstr 十六进制资产ff ee
	//返回十进制
	unsigned int getDec(const char* hexstr);
	//
	//buffer 十六进制数组 result保存结果
	//返回十六进制字符串
	void getHexStr(const unsigned char* buffer, const U8 length, char* result);
	//
	//将一个十六进制字符串转成一个十六进制
	//
	U8 getHex(const char* hexstr);

#ifdef __cplusplus
};
#endif




#endif
