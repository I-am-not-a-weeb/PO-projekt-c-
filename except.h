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

class except_au : public except
{

};

class except_ks : public except
{

};

class except_cz : public except
{

};

class except_bs : public except
{

};
