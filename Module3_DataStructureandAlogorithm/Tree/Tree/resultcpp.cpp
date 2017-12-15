
#include "tree.h"
int main()
{
	
	tree *node=NULL;
	tree t;
	int option,price;

	do
	{
		cout << "1. Insert product details" << endl;
		cout << "2. Mirror copy of tree" << endl;
		cout << "3.sort the tree according to price" << endl;
		cout << "4.Display number of products in given price" << endl;
		cout << "5. Exit"<<endl;
		cout << "\n";
		cout << "Enter your option:  ";
		cin >> option;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter correct option: " << '\t';
				cin >> option;
				continue;
			}
			else if (1>option && option>5)
			{
				cout << "Enter correct option: " << '\t';
				cin >> option;
			}
			else
			{
				break;
			}
		}  
		switch (option)
		{
		case 1: t.get_data();
				node=t.insert_data(node);
				break;
		case 2: t.mirror_tree(node);
				break;
		case 3: t.display_price(node);
				break;
		case 4: cout << "Enter price:" << '\t';
				cin >> price;
				t.display_product(node, price);
				break;
		case 5: option = 5;
				cout << "Thank you";
				break;
		}
	} while (option != 5);
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}