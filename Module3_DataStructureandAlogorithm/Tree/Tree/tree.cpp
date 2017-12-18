#include "tree.h"

tree::tree()
{
}
tree::~tree()
{
}

void tree::set_data()			//set the product details
{
	float price;
	string product;
	cout << "Enter product name:" << "\t";
	getline(cin >>ws, product);
	N.set_product(product);
	cout << "Enter product price:" << "\t";
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

tree* tree :: insert_data(tree *node)				//insert the product details in node
{
	if (node == NULL)
	{
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
	cout << product_name.size();

	return node;
}

tree* tree::balance(tree* node)					//Balancing the tree
{
	int bal_factor = diff(node);
	if (bal_factor > 1)
	{
		if (diff(node->left) > 0)
			node = leftleft_case(node);
		else
			node = leftright_case(node);
	}
	else if (bal_factor < -1)
	{
		if (diff(node->right) > 0)
			node = rightleft_case(node);
		else
			node = rightright_case(node);
	}
	return node;
}

int tree::diff(tree* node)
{
	int left_height = 0, right_height = 0, bf = 0;
	left_height = tree_height(node->left);
	right_height = tree_height(node->right);
	bf = left_height - right_height;
	return bf;
}


int tree::tree_height(tree* node)						//find the height of the tree
{
	int height = 0, left_height = 0, right_height = 0;
	if (node != NULL)
	{
		left_height = tree_height(node->left);
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

tree* tree::leftleft_case(tree* node)			//rotate the tree in right side
{
	tree* temp;
	temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

tree* tree::leftright_case(tree* node)			//rotate the tree in left side and right side
{
	tree* temp;
	temp = node->left;
	node->left = rightright_case(temp);
	return leftleft_case(node);
}

tree* tree::rightleft_case(tree* node)			//rotate the tree in right side and left side
{
	tree* temp;
	temp = node->right;
	node->right = leftleft_case(temp);
	return rightright_case(node);
}

tree* tree::rightright_case(tree* node)			//rotate the tree in left side
{
	tree* temp;
	temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}


void tree::mirror_tree(tree* node)				//display the mirror tree
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

void tree::display_price(tree *node)			//display the tree in inorder
{

	if (node != NULL)
	{
		display_price(node->left);
		cout << node->product_price << "\t";
		display_price(node->right);
	}
	if (node == NULL)
	{
		return;
	}
}

void tree::display_product(tree *node, float price)			//display number of products in particular price
{
	if (node == NULL)
	{
		return;
	}
	if (node != NULL)
	{
		if (node->product_price == price)
		{
			cout << "The number of product is " << node->product_name.size();
			return;
		}
		display_product(node->left, price);
		display_product(node->right, price);
	}
}
