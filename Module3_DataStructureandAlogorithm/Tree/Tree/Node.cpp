#include "Node.h"


Node::Node()
{
}
Node::~Node()
{
}

//set and get product details
void Node::set_price(float price)	
{
	this->price = price;
}
float Node::get_price()
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
