#pragma once
#include"resource.h"			//include resource file
#include"client.h"
#pragma once
#include<string>
using namespace std;
class UserRequest
{
private:
	UserRequest();
	~UserRequest();
	client Request;
public:

	static void Instantiate();
	static bool Instance();

	static void send_requestcreategame(string);
	static void send_requestjoingame(string);
	static void usergameid(string);
	static void useroption(string, string);
	static void user_input(string);

};

