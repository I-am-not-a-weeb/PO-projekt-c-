#pragma once
#include "System.h"
#include <iostream>
#include <Windows.h>
#include <sstream>


class c_drukarnia 
{
private: 
	bool DrukowanieAlbumow = 0;
	std::string nazwa;
	int id = -1;
public:
	c_drukarnia()
	{

	}
	c_drukarnia(std::string f_nazwa, bool f_drukowanieAlbumow,int f_id)
	{
		DrukowanieAlbumow = f_drukowanieAlbumow;
		nazwa = f_nazwa;
		id = f_id;
	}
	std::string dump()
	{
		std::stringstream out;
		out << id << " " << nazwa << " " << DrukowanieAlbumow << std::endl;
	}
	friend bool operator==(c_drukarnia l, c_drukarnia r)
	{
		if (l.id == r.id) return 1; else return 0;
	}
};

//__interface ZarzadzanieDrukowaniem
//{
//	virtual c_drukarnia DodanieDrukarni(bool f_drukowanieAlbumow, std::string f_nazwa,int f_id)		///schemat poprawny
//	{
//		return c_drukarnia(f_drukowanieAlbumow, f_nazwa,f_id);
//	}
//};