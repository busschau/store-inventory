/* Abe Busschau -- abusschau@gmail.com
 *
 *
 * For this program, we will be using a binary search tree as our data structure. We 
 * will be making a sorting/storage of inventory for a store.
 *
 * This File is the client code for my ADT. It interacts with the user and calls my ADT.
*/

#include "bst.h"
using namespace std;


int main()
{
	product item; // Item object to hold all of my item information
	table tree; // Table object to hold my data		
	int choice{}; // Holds choice option
	char temp[SIZE]; // Holds temp arrays for gathering info.
	int test{}; // used for outputing different cases on removal and retrival 
	float low{}; // Price low end
	float high{}; // Price high end

	while (choice != 7)
	{
		cout << "\n\nMain Menu:\n\n"
		     << "\t1. Add Product\n"
		     << "\t2. Display All Product(s)\n"
		     << "\t3. Remove Product\n"
		     << "\t4. Display Specific Item (Retrieve)\n"
		     << "\t5. Display All in Price Range\n"
		     << "\t6. Give Height of Tree\n"
		     << "\t7. Quit\n" << endl;
		cout << "Enter Option: ";
		cin >> choice; cin.ignore(100,'\n');

		// Error Check
		while (choice < 1 || choice > 7)\
		{
			cout << "\n\nChoice needs to be between 1 and 7!\nEnter (1 - 7): ";
			cin >> choice; cin.ignore(100, '\n');
		}

		// Add new Product
		if (choice == 1)
		{
			// Fill item full
			item.add();

			if (tree.insert(item))
				cout << "\n\nItem Added!\n" << endl;
			else
				cerr << "\n\nError!\n" << endl;

			// Delete item info
			item.recycle();
		}

		// Display All in sorted order
		else if (choice == 2)
		{
			if (!tree.display_all())
				cerr << "\n\nTree Is empty! No items!\n" << endl;
		}

		// Remove Product
		else if (choice == 3)
		{
			cout << "\n\nPlease Enter Product to remove (Check Spelling!): ";
			cin.get(temp, SIZE, '\n'); cin.ignore(100, '\n');
			
			// Make word uppercase
			upper_case(temp);

			test = tree.remove(temp);

			if (test == 1)
				cout << "\n\nProduct Removed!\n" << endl;
			else if (test == -1)
				cout << "\n\nProduct not in Tree!\n" << endl;
			else
				cout << "\n\nTree is Empty!\n" << endl;
		}

		// Display specific Item
		else if (choice == 4)
		{
			cout << "\n\nPlease Enter Product to Search (Check Spelling!): ";
			cin.get(temp, SIZE, '\n'); cin.ignore(100, '\n');

			// Make word Uppercase
			upper_case(temp);

			test = tree.retrieve(temp, item);

			if (test == 1)
			{
				cout << "\n\nSearch Item: " << temp << endl;
				item.display();
				item.recycle();
			}
			else if (test == -1)
				cerr << "\n\nProduct not in Tree!\n" << endl;
			else
				cerr << "\n\nTree is Empty!\n" << endl;
		}

		// Dsiplay all with in price range
		else if (choice == 5)
		{
			cout << "\n\nPlease Enter Lowest Price: ";
			cin >> low; cin.ignore(100, '\n');

			// Error Check for price low
			while (low < 0)
			{
				cout << "\n\nPrice must be a positive number!\nEnter: ";
				cin >> low; cin.ignore(100, '\n');
			}

			// Get Price high
			cout << "\n\nPlease Enter Highest Price: ";
		       	cin >> high; cin.ignore(100, '\n');

			// Error Check for price high
			while (high < low)
			{
				cout << "\n\nPrice must be above the lower Price!\nEnter: ";
				cin >> high; cin.ignore(100, '\n');
			}

			test = tree.display_price(low, high);

			if (test == -1)
				cerr << "\n\nNo Products Within that Range!\n" << endl;
			else if (!test)
				cerr << "\n\nTree is Empty!\n" << endl;
		}

		// Displays the height of the tree
		else if (choice == 6)
		{
			// Just using test because I already have the variable made
			test = tree.height();

			if (test)
				cout << "\n\nThe Height of the Tree is " << test << "\n" << endl;
			else
				cerr << "\n\nThe Tree is Empty!\n" << endl;
		}
	}
	return 0;
}

// Turns word all upper case
void upper_case(char word[])
{
	for (int i{}; word[i] != '\0'; ++i)
	{
		if (isalpha(word[i]))
			word[i] = toupper(word[i]);
	}
}

