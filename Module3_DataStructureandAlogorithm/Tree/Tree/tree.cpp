#include "tree.h"




tree::tree()
{
}


tree::~tree()
{
}
void tree::get_data()
{
	int price;
	string product;
	cout << "Enter product name:" << "\t\t";
	cin >> product;
	N.set_product(product);
	cout << "Enter product price:" << "\t\t";
	cin >> price;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter correct option: " << '\t';
			cin >> price;
			continue;
		}
		else
		{
			break;
		}
	}
	N.set_price(price);

}
tree* tree :: insert_data(tree *node)
{
	
	if (node == NULL)
	{
		int count = 1;
		node = new tree;
		node->product_price = N.get_price();
		node->product_name.push_back(N.get_product());
		node->left = NULL;
		node->right = NULL;
		return node;
		
	}
	if (node->product_price == N.get_price())
	{
		node->product_name.push_back(N.get_product());
		return node;
	}
	if (node->product_price > N.get_price())
	{
		node->left = insert_data(node->left);
		node = balance(node);
	}
	else if (node->product_price < N.get_price())
	{
		node->right = insert_data(node->right);
		node = balance(node);
	}
	return node;
}
tree* tree::leftleft_rotation(tree* node)
{
	tree* temp;
	temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}
tree* tree::leftright_rotation(tree* node)
{
	tree* temp;
	temp = node->left;
	node->left = rightright_rotation(temp);
	return leftleft_rotation(node);
}
tree* tree::rightleft_rotation(tree* node)
{
	tree* temp;
	temp = node->right;
	node->right = leftleft_rotation(temp);
	return rightright_rotation(node);
}
tree* tree::rightright_rotation(tree* node)
{
	tree* temp;
	temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}
tree* tree::balance(tree* node)
{
	int bal_factor = diff(node);
	if (bal_factor > 1)
	{
		if (diff(node->left) > 0)
			node = leftleft_rotation(node);
		else
			node = leftright_rotation(node);
	}
	else if (bal_factor < -1)
	{
		if (diff(node->right) > 0)
			node = rightleft_rotation(node);
		else
			node = rightright_rotation(node);
	}
	return node;
}
int tree::tree_height(tree* node)
{
		int height = 0,left_height=0,right_height=0;
		if (node != NULL)
		{
			left_height = tree_height( node->left);
			right_height = tree_height(node->right);
		}
		if (left_height >= right_height)
		{
			height = left_height + 1;
		}
		else
		{
			height = right_height + 1;
		}
		return height;
}
int tree::diff(tree* node)
{
	int left_height=0, right_height=0, bf = 0;
	left_height = tree_height(node->left);
	right_height = tree_height(node->right);
	bf = left_height - right_height;
	return bf;
}
void tree::mirror_tree(tree* node)
{
	tree* temp;
	temp = node;

	if (node != NULL)
	{
		mirror_tree(temp->right);
		cout << temp->product_price << '\t';
		mirror_tree(temp->left);
	}
	if (node == NULL)
	{
		return;
	}
}

void tree::display_price(tree *node)
{

	if (node != NULL)
	{
		display_price(node->left);
		cout << node->product_price << "\n ";
		display_price(node->right);
	}
	if (node == NULL)
	{
		return;
	}
}
void tree::display_product(tree *node,int price)
{
	if (node != NULL)
	{
		if (node->product_price == price)
		{
			cout << "The number of product is " <<node->product_name.size() ;
		}
		display_product(node->left, price);
		display_product(node->right, price);
	}
	if (node == NULL)
	{
		return;
	}
}
