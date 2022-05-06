#pragma once
#include "System.h"
#include <iostream>
#include <Windows.h>



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
	c_drukarnia(bool f_drukowanieAlbumow, std::string f_nazwa,int f_id)
	{
		DrukowanieAlbumow = f_drukowanieAlbumow;
		nazwa = f_nazwa;
		id = f_id;
	}
};

__interface ZarzadzanieDrukowaniem
{
	virtual c_drukarnia DodanieDrukarni(bool f_drukowanieAlbumow, std::string f_nazwa,int f_id)		///schemat poprawny
	{
		return c_drukarnia(f_drukowanieAlbumow, f_nazwa,f_id);
	}
};