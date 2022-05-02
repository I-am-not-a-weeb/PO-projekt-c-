#pragma once
#include "System.h"
#include <iostream>
#include <Windows.h>

class ZarzadzanieDrukowaniem :public System
{
	c_drukarnia DodanieDrukarni(bool f_drukowanieAlbumow, std::string f_nazwa)									///schemat poprawny
	{
		return c_drukarnia(f_drukowanieAlbumow, f_nazwa);
	}
};

class c_drukarnia :protected ZarzadzanieDrukowaniem
{
private: 
	bool DrukowanieAlbumow;
	std::string nazwa;
public:
	c_drukarnia()
	{

	}
	c_drukarnia(bool f_drukowanieAlbumow, std::string f_nazwa)
	{
		DrukowanieAlbumow = f_drukowanieAlbumow;
		nazwa = f_nazwa;
	}
};

