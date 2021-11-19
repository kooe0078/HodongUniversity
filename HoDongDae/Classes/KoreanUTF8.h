#ifndef __KOREAN_UTF8_H__
#define __KOREAN_UTF8_H__

#include "cocos2d.h"

USING_NS_CC;

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

const std::string UTF8(const std::string& string);

#define UTF8PCHAR(string)    UTF8(string).c_str()

#else

#define UTF8(string)    string
#define UTF8PCHAR(string)    string

#endif

#endif // __KOREAN_UTF8_H__