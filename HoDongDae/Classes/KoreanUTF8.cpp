#include "KoreanUTF8.h"

const std::string UTF8(const std::string& string)
{
	int bufflen = MultiByteToWideChar(CP_ACP, 0, string.c_str(), -1, NULL, 0);
	WCHAR* widebuff = new WCHAR[bufflen + 1];
	memset(widebuff, 0, sizeof(WCHAR)* (bufflen + 1));
	MultiByteToWideChar(CP_ACP, 0, string.c_str(), -1, widebuff, bufflen);

	bufflen = WideCharToMultiByte(CP_UTF8, 0, widebuff, -1, NULL, 0, NULL, NULL);
	char* buff = new char[bufflen + 1];
	memset(buff, 0, sizeof(char)* (bufflen + 1));
	WideCharToMultiByte(CP_UTF8, 0, widebuff, -1, buff, bufflen, NULL, NULL);

	std::string strResult(buff);

	delete[] widebuff;
	delete[] buff;

	return strResult;
}