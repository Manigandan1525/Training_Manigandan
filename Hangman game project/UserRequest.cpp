#pragma once
#include "UserRequest.h"
string UserName;
static UserRequest *userReq;
UserRequest::UserRequest()
{
}

UserRequest::~UserRequest()
{
	if (userReq) {
		delete userReq;
	}
	userReq = NULL;
}

void UserRequest::Instantiate()
{
	if (userReq == NULL) {
		userReq = new UserRequest;
	}

}
bool UserRequest::Instance()
 {
	if (userReq == NULL) {
		return false;
	}
	return true;
}

void UserRequest::send_requestcreategame(string Name)		//send create game request
{
	if (Instance()) {
		UserName = Name;
		string CreateGame = "<"HANGMAN"><"CREATE">User wants to create game</"CREATE"></"HANGMAN">";		
		userReq->Request.send_request(CreateGame);
	}

}

void UserRequest::send_requestjoingame(string Name)			//send join game request 
{
	if (Instance()) {
		UserName = Name;
		string JoinGame = "<"HANGMAN"><"JOIN">User wants to join game</"JOIN"></"HANGMAN">";
		userReq->Request.send_request(JoinGame);
	}

}

void UserRequest::usergameid(string GameId)					//send  gameid request 
{
	if (Instance()) {
		string JoinGame = "<"HANGMAN"><"JOINGAME"><"GAMEID">" + GameId + "</"GAMEID"></"JOINGAME"><"USERNAME">" + UserName + "</"USERNAME"></"HANGMAN">";
		userReq->Request.send_request(JoinGame);
	}
}

void UserRequest::useroption(string Category, string Difficulty)	//send category and difficulty to server
{
	if (Instance()) {
		string CreateGame = "<"HANGMAN"><"CREATEGAME"><"CATEGORY">" + Category + "</"CATEGORY"><"LEVEL">" + Difficulty + "</"LEVEL"></"CREATEGAME"><"USERNAME">" + UserName + "</"USERNAME"></"HANGMAN">";
		userReq->Request.send_request(CreateGame);
	}
}


void UserRequest::user_input(string Letter)				//send user letter to server
{
	if (Instance()) {
		string UserInput = "<"HANGMAN"><"LETTER">" + Letter + "</"LETTER"></"HANGMAN">";
		userReq->Request.send_request(UserInput);
	}
}