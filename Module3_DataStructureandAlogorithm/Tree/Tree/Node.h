#ifndef Company_HEADER
#define Company_HEADER
#include<iostream>
#include<string>
using namespace std;
class Node
{
private:
	int price;
	string product;
	

public:
	Node();
	~Node();
	void set_price(int);
	int get_price();
	void set_product(string);
	string get_product();
	
};
#endif