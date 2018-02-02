#pragma once

#ifndef _F_GRAPH_H
#define _F_GRAPH_H

#include <windows.h>
#include<amp_graphics.h>
#include <iostream>
class graphics : public std::basic_ostream<char, std::char_traits<char> >
{
private:
		// copy constructor and operator= forbidden
		graphics(const graphics&) : std::basic_ostream<char, std::char_traits<char> >(std::cout.rdbuf()) {};
		graphics & operator=(const graphics&) { return *this; };
	protected:
		// to handle console window
		HANDLE consoleHandler;
public:
	void box(int _x1, int _y1, int _x2, int _y2);
	int whereX(void);

	// to get current cursor position on y dimension
	int whereY(void);
	int gotoxy(const int _x, const int _y);
	int gotoxyz(const int _x, const int _y);
	void setColor(const WORD _newColorToSet);
	graphics();
	~graphics();
};

extern graphics gf;

#endif