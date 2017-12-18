//create Node class
#ifndef Company_HEADER
#define Company_HEADER
#include<iostream>
#include<string>
using namespace std;
//Node class
class Node
{
private:
	float price;
	string product;
	

public:
	Node();
	~Node();
	void set_price(float);
	float get_price();
	void set_product(string);
	string get_product();
	
};
#endif