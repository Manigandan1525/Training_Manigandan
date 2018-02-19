#include "Graphical_design.h"

using namespace std;

// an instance of our class - to access member functions
// to save where our cursor on the screen

Graphical_design::~Graphical_design()
{
}
// f_graph class constructor
Graphical_design::Graphical_design(void) : std::basic_ostream<char, std::char_traits<char> >(std::cout.rdbuf())
{
	consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Graphical_design::box(int _x1, int _y1, int _x2, int _y2)
{
	//setColor(BACKGROUND_RED);
	unsigned int Index;
	char topLeft = 201;
	char horizontalLines = 205;
	char topRight = 187;
	char verticalLines = 186;
	char bottomLeft = 200;
	char bottomRight = 188;
	int xBegin = whereX();
	int yBegin = whereY();
	gotoxy(_x1, _y1); cout << topLeft;     //left top corner
	for (Index = _x1 + 1; Index<_x2; Index++)
		cout << horizontalLines;     //top line
	gotoxy(_x2, _y1); cout << topRight;     //right top corner
	for (Index = _y1 + 1; Index<_y2; Index++)        //vertical lines
	{
		gotoxy(_x1, Index); cout << verticalLines;
		gotoxy(_x2, Index); cout << verticalLines;

	}
	gotoxy(_x1, _y2); cout << bottomLeft;     //left bottom corner
	for (Index = _x1 + 1; Index<_x2; Index++) cout << horizontalLines;       //bottom line
	gotoxy(_x2, _y2); cout << bottomRight;     //right bottom corner
	gotoxyz(xBegin, yBegin);
}
int Graphical_design::whereX(void)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	GetConsoleScreenBufferInfo(consoleHandler, &screenInfo);

	return screenInfo.dwCursorPosition.X + 1;
}

// to get current cursor position on y dimension
int Graphical_design::whereY(void)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	GetConsoleScreenBufferInfo(consoleHandler, &screenInfo);

	return screenInfo.dwCursorPosition.Y + 1;
}
int Graphical_design::gotoxy(const int _x, const int _y)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	COORD coords = { static_cast<short>(_x - 1), static_cast<short>(_y - 1) };
	SetConsoleCursorPosition(consoleHandler, coords);
}

int Graphical_design::gotoxyz(const int _x, const int _y)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	COORD coords = { static_cast<short>(_x - 1) };
	SetConsoleCursorPosition(consoleHandler, coords);
}



