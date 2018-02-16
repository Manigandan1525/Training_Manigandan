#pragma once
#define NOMINMAX
#include "Graphical_design.h"
#include"GameData.h"
#include"UserRequest.h"
#include<iostream>
#include<vector>
#include<string>
#include <limits>
using namespace std;
class UserDesign
{
private:
	GameData detail;
	Graphical_design gf;
	client ch;
	void game_option();
	void chance();
	void hangman();
	void design(int);
public:
	string UserDetails;
	void get_username();
	void game();
	void game_result(string,string);
	void join_game(vector<GameData>);
	void creategame(vector<GameData>);
	void game_info(vector<GameData>);
	UserDesign();
	~UserDesign();
};
