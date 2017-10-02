#include<Windows.h>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include<vector>
#include"Folder.h"

/*convert mbcs to unicode string*/
std::wstring GBKToUnicode(const std::string& src)
{
	setlocale(LC_ALL, "chs");// 设置为中文环境，不然可能会转换失败
	std::vector<wchar_t> dst(src.size() + 1, L'\0');
	size_t count = std::mbstowcs(&dst[0], src.c_str(), dst.size() - 1);
	setlocale(LC_ALL, "C");
	return std::wstring(&dst[0]);
}
bool hasChinese(const std::string& src)
{
	auto w = GBKToUnicode(src);
	for (auto c : w)
	{
		if (c >= 0x4E00 && c <= 0x9FCB
			|| c >= 0x3400 && c <= 0x4DB5)// 自己再添加中文编码范围
			return true;
	}
	return false;
}
bool hasChinese(const char* str)
{
	return hasChinese((std::string)str);
}

int main()
{

}