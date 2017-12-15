#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
}
void Node::set_price(int price)
{
	this->price = price;
}
int Node::get_price()
{
	return this->price;
}
void Node::set_product(string product)
{
	this->product = product;
}
string Node::get_product()
{
	return product;
}
