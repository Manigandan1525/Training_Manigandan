#pragma once
#include<iostream>
#include<vector>		//using vector to store data
using namespace std;
class GameData
{
private:
	vector<string> TotalGameId;					//declaring the variable
	string GameId;
	string GameWord;
	string RemainingGuess;
	string WrongGuess;
	string Result;
	string Chance;
	vector<string> CategoryList;
	vector<string> Level;
public:
	void set_usergameid(string);
	string get_usergameid();
	void set_words(string);
	string get_words();
	void set_remainingguess(string);
	string get_remainingguess();
	void set_wrongguess(string);
	string get_wrongguess();
	void set_result(string);
	string get_result();
	void set_chance(string);
	string get_chance();
	void set_gameoption(vector<string>);
	vector<string> get_gameoption();
	void set_gameid(vector<string> id);
	vector<string> get_gameid();
	GameData();
};

