//create class tree
#pragma once
#include "Node.h"		// include Node.h class
#include<vector>		//using vector to create vector variable

//tree class
class tree
{
private:
	float product_price;	
	vector<string> product_name;		//vector variable
	tree *left;
	tree *right;
	

public:
	bool flag = 0;
	Node N;
	tree();
	~tree();
	//function definition
	void set_data();
	tree* insert_data(tree *node);
	void display_price(tree *node);
	int display_product(tree *node,float);
	void mirror_tree(tree *node);
	int tree_height(tree*node);
	int diff(tree*node);
	tree* leftleft_case(tree *node);
	tree* leftright_case(tree *node);
	tree* rightleft_case(tree *node);
	tree* rightright_case(tree *node);
	tree* balance(tree *node);
};


