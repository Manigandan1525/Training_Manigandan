#include "graphics.h"


using namespace std;

// an instance of our class - to access member functions
graphics gf;

// to save where our cursor on the screen
int countLine = 7;



graphics::~graphics()
{
}
// f_graph class constructor
graphics::graphics(void) : std::basic_ostream<char, std::char_traits<char> >(std::cout.rdbuf())
{
	consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
}

void graphics::box(int _x1, int _y1, int _x2, int _y2)
{
	//setColor(BACKGROUND_RED);
	char topLeft = 201;
	char horizontalLines = 205;
	char topRight = 187;
	char verticalLines = 186;
	char bottomLeft = 200;
	char bottomRight = 188;
	int i;
	int xBegin = whereX();
	int yBegin = whereY();
	gotoxy(_x1, _y1); cout << topLeft;     //left top corner
	for (i = _x1 + 1; i<_x2; i++)
		cout << horizontalLines;     //top line
	gotoxy(_x2, _y1); cout << topRight;     //right top corner
	for (i = _y1 + 1; i<_y2; i++)        //vertical lines
	{
		gotoxy(_x1, i); cout << verticalLines;
		gotoxy(_x2, i); cout << verticalLines;

	}
	gotoxy(_x1, _y2); cout << bottomLeft;     //left bottom corner
	for (i = _x1 + 1; i<_x2; i++) cout << horizontalLines;       //bottom line
	gotoxy(_x2, _y2); cout << bottomRight;     //right bottom corner
	gotoxyz(xBegin, yBegin);
}
int graphics::whereX(void)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	GetConsoleScreenBufferInfo(consoleHandler, &screenInfo);

	return screenInfo.dwCursorPosition.X + 1;
}

// to get current cursor position on y dimension
int graphics::whereY(void)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	GetConsoleScreenBufferInfo(consoleHandler, &screenInfo);

	return screenInfo.dwCursorPosition.Y + 1;
}
int graphics::gotoxy(const int _x, const int _y)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	COORD coords = { static_cast<short>(_x-1), static_cast<short>(_y - 1) };
	SetConsoleCursorPosition(consoleHandler, coords);
}

int graphics::gotoxyz(const int _x, const int _y)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return 0;

	COORD coords = { static_cast<short>(_x - 1)};
	SetConsoleCursorPosition(consoleHandler, coords);
}

void graphics::setColor(const WORD _newColorToSet)
{
	if (consoleHandler == INVALID_HANDLE_VALUE)
		return;

	SetConsoleTextAttribute(consoleHandler, _newColorToSet);
}