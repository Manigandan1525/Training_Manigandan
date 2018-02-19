#pragma once
#define NOMINMAX			
#include "XmlParser.h"			
#include "client.h"
#include "FormDesign.h"
#include <iostream> 
#include<string>
using namespace Hangman;
using namespace std;
[STAThreadAttribute]
int main()
{
	system("cls");
	FormDesign form;
	UserDesign design;
	client client;
	XmlParser parse;
	vector<GameData> details;
	string Information; 
	char option[1024];
	char new_data[1024];
	string value;
	int choice;
	cout << "Enter 1 to windows\n";
	cout << "Enter 2 to console\n";
	cin >> choice;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Enter correct option: " << '\t';
			cin >> choice;
		}
		else if (choice<1 || choice>2)
		{
			cout << "Enter correct option: " << '\t';
			cin >> choice;
		}
		else
		{
			break;
		}
	}
	system("cls");
	if (choice == 1)				//choose windows application
	{
		HWND hWnd = GetConsoleWindow();
		if (hWnd != 0) {
			ShowWindow(hWnd, SW_HIDE);
		}
		form.InitializeComponent();
		form.ShowDialog();
	}
	else                                    //choose console applicati0n 
	{
		design.get_username();
		design.game();
		while (1)
		{
			Information = client.receive_details();
			if (!Information.empty())
			{
				strcpy_s(option, Information.c_str());
				strcpy_s(new_data, Information.c_str());
				value = parse.receive_data(option);
				details = parse.parser(new_data);
				if (value == JOIN)
				{
					design.join_game(details);
				}
				else if (value == CATEGORYLIST)
				{
					design.creategame(details);
				}
				else if (value == GAMEINFO)
				{
					design.game_info(details);
				}
			}
			else
			{
				Sleep(3000);
				exit(0);
			}
		}
	}
	cin.get();
	cin.ignore(1000, '\n');
	return EXIT_SUCCESS;
}
