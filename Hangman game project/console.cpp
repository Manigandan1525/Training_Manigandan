#include "console.h"


console::console()
{
}


console::~console()
{
}

void console::getusername()
{
	gf.box(50, 2, 75, 3);
	gf.box(70, 3, 71, 24);
	string username;
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << " Enter your name : ";
	cin >> username;
	system("cls");

}

void console::game()
{
	gf.box(50, 2, 75, 3);
	gf.box(70, 3, 71, 24);
	int option;
	int newgame;
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << " 1. Play"<<endl;
	cout << " 2. Instruction"<<endl;
	cout << " 3. Exit"<<endl;
	cin >> option;
	system("cls");
	gf.box(50, 2, 75, 3);
	gf.box(70, 3, 71, 24);
	switch (option)
	{
	case 1:
		cout << "			HANGMAN GAME" << "\n" << endl;
		cout << " JOIN" << "\n" << endl;
		cout << " 1. Game ID : GAME145321" << endl;
		cout << " Players" << endl;
		cout << "	1. Name1" << endl;
		cout << "	2. Name2" << endl;
		cout << "	3. Name3" << endl;
		cout << "2. Game ID : GAME234321" << endl;
		cout << " Players" << endl;
		cout << "	1. Name4" << endl;
		cout << "	2. Name5" << endl;
		cout << "	3. Name6" << endl;
		cout << "\n\n\n" << endl;
		cout << " Create New game Enter 1" << endl;
		cin >> newgame;
		system("cls");
		if (newgame == 1)
		{
			gamecategory();
		}
		break;
	case 2:
		int value;
		cout << "			HANGMAN GAME" << "\n" << endl;
		cout << "  INSTRUCTION " << "\n" << endl;
		cout << " 1. Play individually or in groups." << endl;
		cout << " 2. select your category and difficulty" << endl;
		cout << " 3. you entered the correct letter the word" << endl; 
		cout << "    to change dash to letter, if you" << endl; 
		cout << "    entered wrong ahangman portion added." << endl;
		cout << " 4. You have only six wrong guess, if you " << endl;
		cout<<  "    not complete the word, you will lose "<<"\n\n" << endl;
		cout << " Enter 1 to colse instruction" << endl;
		cin >> value;
		system("cls");
		game();
		break;
	case 3:
		exit(0);
	}
}
void console::gamecategory()
{
	int useroption;
	gf.box(50, 2, 75, 3);
	gf.box(70, 3, 71, 24);
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << " Select your category" << "\n" << endl;
	cout << "	1. Movies" << endl;
	cout << "	2. Geography" << endl;
	cout << "	3. Festival" << endl;
	cout << "	4. Back" << endl;
	cin >> useroption;
	if (useroption == 4)
	{
		system("cls");
		game();
	}
	system("cls");
	gf.box(50, 2, 75, 3);
	gf.box(70, 3, 71, 24);
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << " Select your difficulty" << "\n" << endl;
	cout << "	1. Easy" << endl;
	cout << "	2. Normal" << endl;
	cout << "	3. Hard" << endl;
	cout << "	4. Back" << endl;
	cin >> useroption;
	if (useroption == 4)
	{
		system("cls");
		gamecategory();
	}
	system("cls");
	playgame();
}

void console::playgame()
{
	char letter;
	int i = -1;
	while (i < 7)
	{
		gf.box(50, 2, 75, 3);
		gf.box(70, 3, 71, 24);
		gf.box(55, 3, 56, 5);
		cout << "			HANGMAN GAME" << "\n" << endl;
		cout << " word : _ _ _ _ _ _" << endl;
		cout << " \n" << " Remaining Guess : " << endl;
		cout << "Wrong Guess : " << endl;
		cout << "\n" << "Enter Leter :" << endl;
		if (i == 6)
		{
			result();
		}
		cin >> letter;
		++i;
		system("cls");
		if (i == 1)
		{
			system("cls");
			gf.box(52, 5, 59, 9);//1
			gf.box(54, 6, 54, 6);//1
			gf.box(57, 6, 57, 6);//1
		}
		else if (i == 2)
		{
			system("cls");
			gf.box(52, 5, 59, 9);//1
			gf.box(54, 6, 54, 6);//1
			gf.box(57, 6, 57, 6);//1
			gf.box(55, 9, 56, 17);//2
			//gf.box(46, 11, 54, 12);//3
			//gf.box(57, 11, 65, 12);//4
			//gf.box(47, 16, 54, 17);//5
			//gf.box(47, 16, 48, 22);//5
			//gf.box(57, 16, 64, 17);//6
			//gf.box(63, 16, 64, 22);//6
		}
		else if (i == 3)
		{
			system("cls");
			gf.box(52, 5, 59, 9);//1
			gf.box(54, 6, 54, 6);//1
			gf.box(57, 6, 57, 6);//1
			gf.box(55, 9, 56, 17);//2
			gf.box(46, 11, 54, 12);//3
			//gf.box(57, 11, 65, 12);//4
			//gf.box(47, 16, 54, 17);//5
			//gf.box(47, 16, 48, 22);//5
			//gf.box(57, 16, 64, 17);//6
			//gf.box(63, 16, 64, 22);//6
		}
		else if (i == 4)
		{
			system("cls");
			gf.box(52, 5, 59, 9);//1
			gf.box(54, 6, 54, 6);//1
			gf.box(57, 6, 57, 6);//1
			gf.box(55, 9, 56, 17);//2
			gf.box(46, 11, 54, 12);//3
			gf.box(57, 11, 65, 12);//4
		//	gf.box(47, 16, 54, 17);//5
		//	gf.box(47, 16, 48, 22);//5
			//gf.box(57, 16, 64, 17);//6
			//gf.box(63, 16, 64, 22);//6
		}
		else if (i == 5)
		{
			system("cls");
			gf.box(52, 5, 59, 9);//1
			gf.box(54, 6, 54, 6);//1
			gf.box(57, 6, 57, 6);//1
			gf.box(55, 9, 56, 17);//2
			gf.box(46, 11, 54, 12);//3
			gf.box(57, 11, 65, 12);//4
			gf.box(47, 16, 54, 17);//5
			gf.box(47, 16, 48, 22);//5
			//gf.box(57, 16, 64, 17);//6
			//gf.box(63, 16, 64, 22);//6
		}
		else if (i == 6)
		{
			system("cls");
			gf.box(52, 5, 59, 9);//1
			gf.box(54, 6, 54, 6);//1
			gf.box(57, 6, 57, 6);//1
			gf.box(55, 9, 56, 17);//2
			gf.box(46, 11, 54, 12);//3
			gf.box(57, 11, 65, 12);//4
			gf.box(47, 16, 54, 17);//5
			gf.box(47, 16, 48, 22);//5
			gf.box(57, 16, 64, 17);//6
			gf.box(63, 16, 64, 22);//6
		}
	}
}

void console::result()
{
	int option;
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << "\n" << endl;
	cout << "			YOU WON " <<"\n"<< endl;
	cout << "\n" << endl;
	cout << " 1. New game" << endl;
	cout << " 2.Exit" << endl;
	cin >> option;
	if (option == 1)
	{
		system("cls");
		game();
	}
	else if (option == 2)
	{
		exit(0);
	}
}