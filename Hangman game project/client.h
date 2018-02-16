#pragma once
#include<iostream>		
#include<string>			//Using string variable
using namespace std;
class client
{
public:
	string receive_details();		//receive data from server
	void send_request(string);		// send request to server
	void connection();				// connect to server
	client();
	~client();
};

