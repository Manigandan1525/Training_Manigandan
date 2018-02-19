#include "UserDesign.h"
//string Name;
UserDesign::UserDesign()
{
	UserRequest::Instantiate();
}
UserDesign::~UserDesign()
{
}

void UserDesign::get_username()
{
	hangman();
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << "\n Press 1 to exit game\n" << endl;
	cout << "\n Enter your name : ";
	cin.get();
	getline(cin, Name);						// get user name to user
	cout << Name.length() << endl;
	while (1)
	{
		if (Name.length() > 50)
		{
			cout << "Only 50 character allowed, please try again " <<endl;
			cout << "Enter your name:" ;
			cin.get();
			getline(cin, Name);
		}
		else{
			break;
		}
	}
	if (Name == "1")
	{
		exit(0);
	}
	system("cls");
}
void UserDesign::game()
{
	ch.connection();
	hangman();
	int Option;
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << " 1. Play"<<endl;
	cout << " 2. Instruction"<<endl;
	cout << " 3. Exit"<<endl;
	cin >> Option;										//get option from user
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter correct option: " << '\t';
			cin >> Option;

		}
		else if (Option < 1 || Option>3)
		{
			cout << "Enter correct option: " << '\t';
			cin >> Option;
		}
		else
		{
			break;
		}
	}
	system("cls");
	hangman();
	switch (Option)
	{
	case 1:
		game_option();
		break;
	case 2:
		int Value;
		cout << "			HANGMAN GAME" << "\n" << endl;							//display istruction
		cout << "  INSTRUCTION " << "\n" << endl;
		cout << " a. The player can either create new game or join with existing game." << endl;
		cout << " b. Total chances given to the players are 6." << endl;
		cout << " c. The player can enter only one letter at a time." << endl; 
		cout << " d. for every wrong guesses the hangman image will be loaded " << endl;
		cout << " e. If chances are over the player will lose the game" << endl;
		cout << " f. For correct guesses the chances will not be reduced." << "\n\n\n" << endl;
		cout << " 1.Back" << endl;
		cin >> Value;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Enter correct option: " << '\t';
				cin >> Value;

			}
			else if (Value !=1)
			{
				cout << "Enter correct option: " << '\t';
				cin >> Option;
			}
			else
			{
				break;
			}
		}
		system("cls");
		game();
		break;
	case 3:
		exit(0);
	}

}


void UserDesign::game_option()							
{
	int UserOption;
	hangman();
	cout << "			HANGMAN GAME" << "\n\n" << endl;			//create or join game
	cout << " select your option : " << "\n" << endl;
	cout << " 1. Create " << "\n\n" << endl;
	cout << " 2. JOIN" << "\n\n" << endl;
	cout << " 3. Back" << endl;
	cin >> UserOption;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter correct option: " << '\t';
			cin >> UserOption;

		}
		else if (UserOption < 1 || UserOption>3)
		{
			cout << "Enter correct option: " << '\t';
			cin >> UserOption;
		}
		else
		{
			break;
		}
	}
	system("cls");
	if (UserOption == 1)
	{
		UserRequest::send_requestcreategame(Name);			//send create request 
	}
	else if (UserOption == 2)
	{
		UserRequest::send_requestjoingame(Name);			//send join request
	}
	else if (UserOption == 3)
	{
		game();
	}
}

void UserDesign::join_game(vector<GameData> GameId)			//display join game details
{
	vector<string> GameDetails;
	hangman();
	int UserOption,size;
	size_t Index;
	string id;
	GameDetails = GameId[0].get_gameid();
	if (stoi(GameDetails[0]) == 0)
	{
		cout << " No Game ID to Join" << endl;
		Sleep(2000);
		game_option();
	}
	else
	{
		cout << "			HANGMAN GAME" << "\n\n" << endl;
		cout << "     JOIN " << "\n" << endl;
		cout << " GAME ID" << "\n\n" << endl;
		size = GameDetails.size();
		for (Index = 0; Index <size ; Index++)
		{
			cout << "\t " << Index + 1 << ". " << GameDetails[Index] << endl;
		}
		cin >> UserOption;
		while (1)
		{
			if (cin.fail() || 0 > UserOption > GameDetails.size())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Enter correct option: " << '\t';
				cin >> UserOption;

			}
			else if (UserOption<1 || UserOption>Index)
			{
				cout << "Enter correct option: " << '\t';
				cin >> UserOption;
			}
			else
			{
				break;
			}
		}
		system("cls");
		id = GameDetails[UserOption - 1];
		UserRequest::usergameid(id);
	}
}

void UserDesign::creategame(vector<GameData> Detail)			
	{
		int UserOption;
		size_t Index;
		vector<string> UserCategory,Difficulty;
		string Category,Level;
		hangman();
		cout << "			HANGMAN GAME" << "\n\n" << endl;			//display category
		cout << "     SELECT YOUR CATEGORY " << "\n" << endl;
		for (Index = 0; Index < Detail.size(); Index++)
		{
			UserCategory = Detail[0].get_gameoption();
			for (Index = 0; Index < UserCategory.size(); Index++)
			{
				cout << "\t " << Index + 1 << ". " << UserCategory[Index] << endl;
			}
			
		}
		cin >> UserOption;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Enter correct option: " << '\t';
				cin >> UserOption;

			}
			else if (UserOption<1 || UserOption>Index)
			{
				cout << "Enter correct option: " << '\t';
				cin >> UserOption;
			}
			else
			{
				break;
			}
		}
		system("cls");
		Category = UserCategory[UserOption - 1];
	hangman();
	cout << "			HANGMAN GAME" << "\n\n" << endl;				//display difficulty
	cout << "     SELECT YOUR DIFFICULTY " << "\n" << endl;
	Difficulty = Detail[1].get_gameoption();
	for (Index = 0; Index < Difficulty.size(); Index++)
	{
		cout << "\t " << Index + 1 << ". " << Difficulty[Index] << endl;
	}
	cin >> UserOption;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter correct option: " << '\t';
			cin >> UserOption;

		}
		else if (UserOption<1 || UserOption>Index)
		{
			cout << "Enter correct option: " << '\t';
			cin >> UserOption;
		}
		else
		{
			break;
		}
	}
	system("cls");
	Level = Difficulty[UserOption - 1];
	UserRequest::useroption(Category, Level);
}

void UserDesign::game_info(vector<GameData> GameInfo)				//display game details
{
	int Turn;
	string word;
	size_t Index;
	string info = GameInfo[0].get_remainingguess();
	Turn = atoi(info.c_str());
	system("cls");
	design(Turn);
	int check = stoi(GameInfo[0].get_remainingguess());
	if (check != 0)
	{
		word = GameInfo[0].get_words();
	}
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << "Game ID : " << GameInfo[0].get_usergameid() << endl;
	cout << "\n\n";
	cout << "Word" << "\t";
	for (Index = 0; Index < word.size(); Index++)
	{
		cout << word[Index];
	}
	cout << endl;
	cout << "\n";
	cout << "Remaining Guess" << "\t\t" << GameInfo[0].get_remainingguess() << endl;
	cout << "\n";
	cout << "Wrong Guess" << "\t\t" << GameInfo[0].get_wrongguess() << endl;
	if (GameInfo[0].get_result() == WIN)
	{
		Sleep(3000);
		system("cls");
		game_result(GameInfo[0].get_words(), "YOU WIN");				//call result page
		return;
	}
	else if (GameInfo[0].get_result() == LOSE)
	{
		Sleep(3000);
		system("cls");
		game_result(GameInfo[0].get_words(), "YOU LOSE");				//call result page
		return;
	}

	if (GameInfo[0].get_chance() == "1")
	{
		chance();
	}
}

void UserDesign::chance()
{
	string Letter;
	cout << "Enter your guessing letter" << endl;

	while(1)
	{
		cin >> Letter;
		if (Letter.length() == 1)
		{
			UserRequest::user_input(Letter);			//send user entered letter
			break;
		}
		else
		{
			cout << "Enter single letter" << endl;
		}
	}
}

void UserDesign::game_result(string name,string result)			//display game result 
{
	int Option;
	cout << "			HANGMAN GAME" << "\n" << endl;
	cout << "\n" << endl;
	cout << "	\t\t   " <<result<< "\n" << endl;
	cout << " Correct Word :" << name << "\n\n"<<endl;
	cout << " 1. New game" << endl;
	cout << " 2. Exit" << endl;
	cin >> Option;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter correct option: " << '\t';
			cin >> Option;
		}
		else if (Option<1 || Option>2)
		{
			cout << "Enter correct option: " << '\t';
			cin >> Option;
		}
		else
		{
			break;
		}
	}
	if (Option == 1)
	{
		system("cls");
		game();
	}
	else if (Option == 2)
	{
		exit(0);
	}

}

void UserDesign::hangman()			//display hangman letter
{
	gf.box(55, 2, 79, 3);
	gf.box(75, 3, 76, 25);
	gf.box(60, 3, 61, 5);
	gf.box(44, 4, 45, 10);
	gf.box(46, 8, 47, 8);
	gf.box(48, 6, 49, 10);

	gf.box(51, 6, 52, 10);
	gf.box(52, 6, 56, 7);
	gf.box(55, 6, 56, 10);

	gf.box(59, 6, 63, 6);
	gf.box(58, 6, 59, 10);
	gf.box(62, 6, 63, 10);

	gf.box(66, 6, 70, 6);
	gf.box(65, 6, 66, 10);
	gf.box(66, 10, 70, 10);
	gf.box(65, 12, 71, 13);
	gf.box(70, 6, 71, 13);

	gf.box(47, 14, 54, 14);
	gf.box(46, 14, 47, 18);
	gf.box(50, 14, 51, 18);
	gf.box(54, 14, 55, 18);

	gf.box(57, 14, 58, 18);
	gf.box(58, 14, 62, 15);
	gf.box(61, 14, 62, 18);

	gf.box(65, 14, 68, 14);
	gf.box(64, 14, 65, 18);
	gf.box(68, 14, 69, 18);

}

void UserDesign::design(int chanceleft)				//display hangman
{
	gf.box(55, 2, 79, 3);
	gf.box(75, 3, 76, 25);
	gf.box(60, 3, 61, 5);
	if (chanceleft == 5)
	{
		gf.box(57, 5, 64, 9);
		gf.box(59, 6, 59, 6);
   		gf.box(62, 6, 62, 6);
	}
	else if (chanceleft == 4)
	{
		gf.box(57, 5, 64, 9);
		gf.box(59, 6, 59, 6);
		gf.box(62, 6, 62, 6);
		gf.box(60, 9, 61, 17);
	}
	else if (chanceleft == 3)
	{
		gf.box(57, 5, 64, 9);
		gf.box(59, 6, 59, 6);
		gf.box(62, 6, 62, 6);
		gf.box(60, 9, 61, 17);
		gf.box(51, 11, 59, 12);
	}
	else if (chanceleft == 2)
	{
		gf.box(57, 5, 64, 9);
		gf.box(59, 6, 59, 6);
		gf.box(62, 6, 62, 6);
		gf.box(60, 9, 61, 17);
		gf.box(51, 11, 59, 12);
		gf.box(62, 11, 70, 12);
	}
	else if (chanceleft == 1)
	{
		gf.box(57, 5, 64, 9);
		gf.box(59, 6, 59, 6);
		gf.box(62, 6, 62, 6);
		gf.box(60, 9, 61, 17);
		gf.box(51, 11, 59, 12);
		gf.box(62, 11, 70, 12);
		gf.box(53, 16, 59, 17);
		gf.box(53, 16, 54, 22);
	}
	else if (chanceleft == 0)
	{
		gf.box(57, 5, 64, 9);
		gf.box(59, 6, 59, 6);
		gf.box(62, 6, 62, 6);
		gf.box(60, 9, 61, 17);
		gf.box(51, 11, 59, 12);
		gf.box(62, 11, 70, 12);
		gf.box(53, 16, 59, 17);
		gf.box(53, 16, 54, 22);
		gf.box(62, 16, 68, 17);
		gf.box(67, 16, 68, 22);
	}
}
