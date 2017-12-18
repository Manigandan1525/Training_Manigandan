#include "tree.h"
//main function
int main()
{
	tree *node=NULL;				//create node
	tree t1;						//create object in tree classs
	int option,check_option,value;
	float new_option;
	float price;
	do
	{
		cout << '\n'<<"1. Insert product details" << endl;
		cout << "2. Mirror copy of tree" << endl;
		cout << "3. sort the tree according to price" << endl;
		cout << "4. Display number of products in given price" << endl;
		cout << "5. Exit"<<endl;
		cout << "\n";
		cout << "Enter your option: "<<'\t';
		cin >> new_option;
		check_option = int(new_option);
		while (1)					//validation
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter valid option: " << '\t';
			cin >> new_option;
			check_option = int(new_option);
			continue;
		}
			else if (check_option != new_option)
			{
				cout << "Enter valid option: " << '\t';
				cin >> new_option;
				check_option = int(new_option);
				continue;
			}
			else
			{
				option = new_option;
				break;
			}
		}
		switch (option)						//using switch case
		{
		case 1: t1.set_data();
				node=t1.insert_data(node);
				break;
		case 2: t1.mirror_tree(node);
				break;
		case 3: t1.display_price(node);
				break;
		case 4:
			if (t1.flag == 0)
			{
				cout << "Tree is empty";
			}
			else
			{
				cout << "Enter price:" << '\t';
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
				value = t1.display_product(node, price);
				if (value > 0)
				{
					cout << "The number of product is " << value << endl;
				}
				else
				{
					cout << "The given price is unmatched";
				}
			}
				break;
		case 5: exit(0);
				break;
		default: cout << "Enter valid option: " << '\t';
		}
	} while (1);
	cin.ignore(1000, '\n');
	cin.get();
	return 0;
}