//#ifndef Company_HEADER
//#define Company_HEADER
#pragma once

#include "Node.h"
#include<vector>
class tree
{
private:
	int product_price;	
	vector<string> product_name;
	tree *left;
	tree *right;

public:
	Node N;
	//tree *node;
	tree();
	~tree();
	void get_data();
	tree* insert_data(tree *node);
	void display_price(tree *node);
	void display_product(tree *node,int price);
	void mirror_tree(tree *node);
	int tree_height(tree*node);
	int diff(tree*node);
	tree* leftleft_rotation(tree *node);
	tree* leftright_rotation(tree *node);
	tree* rightleft_rotation(tree *node);
	tree* rightright_rotation(tree *node);
	tree* balance(tree *node);
	void inorder(tree *);

	       

	










};
//#endif

