#include "client.h"
#include <winsock2.h>
WSADATA WSAData;			//declaring the variable to connect server
SOCKET server;
SOCKADDR_IN addr;
client::client()
{
}
client::~client()
{
}
string client::receive_details()
{
	int ReceivedBytes;
	char buffer[1024];
	string value;
	ReceivedBytes = recv(server, buffer, sizeof(buffer), 0);			//receive data from server

	if (ReceivedBytes > 0)
	{
		value = buffer;
	}
	else
	{
		system("cls");
		cout << "Client disconnected" << endl;
	}
	return value;		//return string value
}

void client::send_request(string gamedetails)
{
	char tab2[1024];
	strcpy_s(tab2, gamedetails.c_str());				//perform string copy operation
	send(server, tab2, sizeof(tab2), 0);			//send data to server
	return;
}

void client::connection()
{

	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_addr.s_addr = inet_addr("172.29.124.236"); 
	addr.sin_family = AF_INET;
	addr.sin_port = htons(138);
	connect(server, (SOCKADDR *)&addr, sizeof(addr));		//connect to server
}