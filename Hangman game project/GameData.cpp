#include "GameData.h"


GameData::GameData()
{
}

void GameData::set_usergameid(string Id)
{
	this->GameId = Id;						//set user choose game id
}

string GameData::get_usergameid()
{
	return this->GameId;					//get user choose game id
}
void GameData::set_words(string Word)
{
	this->GameWord = Word;					//set game word
}

string GameData::get_words()
{
	return this->GameWord;					//get game word
}

void GameData::set_remainingguess(string RemainingGuess)
{
	this->RemainingGuess = RemainingGuess;			//set remaining guess letter
}

string GameData::get_remainingguess()
{
	return this->RemainingGuess;					//get remaining guess letter
}

void GameData::set_wrongguess(string WrongGuess)
{
	this->WrongGuess = WrongGuess;					//set user wrong guess
}

string GameData::get_wrongguess()
{
	return this->WrongGuess;						//get user wrong guess
}

void GameData::set_result(string Result)
{
	this->Result = Result;							//set user result
}

string GameData::get_result()
{
	return this->Result;							//get user result
}

void GameData::set_chance(string Chance)
{
	this->Chance = Chance;							//set which user turn
}

string GameData::get_chance()
{
	return this->Chance;							//get user turn
}

void GameData::set_gameoption(vector<string> Category)
{
	this->CategoryList = Category;					//set usercategory
}

vector<string> GameData::get_gameoption()
{
	return this->CategoryList;						//get category
}


void GameData::set_gameid(vector<string> Id)
{
	this->TotalGameId = Id;						//set id
}

vector<string> GameData::get_gameid()
{
	return this->TotalGameId;				//get id
}