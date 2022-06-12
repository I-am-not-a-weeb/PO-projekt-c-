#pragma once
#include <Windows.h>
#include <string>

class except :public std::exception
{
	std::string msg;
public:
	except(std::string mess) : msg(mess){}
	std::string getMsg() { return msg; }
	virtual ~except() throw() {}
};
