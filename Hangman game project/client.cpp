#include "client.h"
#include <winsock2.h>
WSADATA WSAData;			//declaring the variable to connect server
SOCKET server;
SOCKADDR_IN addr;

string client::receive_details()
{
	int ReceivedBytes;
	char buffer[1024];
	string value;
	ReceivedBytes = recv(server, buffer, sizeof(buffer), 0);			//receive data from server

	if (ReceivedBytes > 0)
	{
		return buffer;						//return string value
	}
	else if(ReceivedBytes<=0)
	{
		system("cls");
		cout << "Server Disconnected" << endl;
		Sleep(2000);
		exit(0);
	}
}

void client::send_request(string gamedetails)
{				
	char buffer[1024];
	strcpy_s(buffer, gamedetails.c_str());
	send(server, buffer, sizeof(buffer), 0);			//send data to server
}

void client::connection()
{	
	int Result=WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_addr.s_addr = inet_addr(SERVER); 
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT_NUMBER);
	Result == connect(server, (SOCKADDR *)&addr, sizeof(addr));				//connect to server
	if(Result==SOCKET_ERROR)
	{
		cout << "Connection Failed" << endl;
	}	
	else
	{
		cout << "Connect Succesfully" << endl;
	}
}