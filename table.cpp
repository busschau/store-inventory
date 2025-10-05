/* Abe Busschau -- abusschau@gmail.com
 *
 *
 * For this program, we will be using a binary search tree as our data structure. We 
 * will be making a sorting/storage of inventory for a store.
 *
 * This File is the implementation of the Binary Search Tree. It is how the products are stored
*/

#include "bst.h"
using namespace std;

// Constructor
table::table()
{
	root = nullptr;
}


// (Wrapper) Destructor
table::~table()
{
	if (destructor(root))
		root = nullptr;
}

// (Recursive) Destructor
int table::destructor(node *& root)
{
	if (!root) return 1;

	// Go all Left then right
	int left = destructor(root->left);
	int right = destructor(root->right);

	// Delete root
	delete root;
	root = nullptr;

	return left + right;
}


// (Wrapper) Insert data into BST
int table::insert(const product & item)
{
	return insert(root, item);
}


// (Recursive) Insert data into BST
int table::insert(node *& root, const product & item)
{
	// Base Case, Insert here!
	if (!root)
	{
		node * temp = new node;
		temp->data.copy(item);
		temp->left = nullptr;
		temp->right = nullptr;
		root = temp;
		return 1;
	}

	if (root->data.comes_after(item))
		return insert(root->right, item);
	return insert(root->left, item);
}


// (Wrapper) Display all Information
int table::display_all() const 
{
	// Empty
	if (!root) return 0;

	cout << "\n\nProduct(s) in Sorted Order by Name:\n\n" << endl;

	return display_all(root);
}

// (Recursive) Display all information
int table::display_all(node * root) const 
{
	if (!root) return 1;

	// Go all the way left
	int left = display_all(root->left);

	// Display root data
	cout << "\n\nProduct:" << endl;

	root->data.display();

	// Go all the way right
	int right = display_all(root->right);

	return right + left;
}


// (Wrapper) Remove Item
int table::remove(const char name[])
{
	// Empty List
	if (!root) return 0;

	// Match found or no match
	if (remove(root, name))
		return 1;
	return -1;
}

// (Recursive) Remove Item
int table::remove(node *& root, const char name[])
{
	if (!root) return 0;

	// Found Match
	if (root->data.retrieve(name))
	{
		// Match is a leaf
		if (!root->left && !root->right)
		{
			delete root;
			root = nullptr;
		}

		// Match has left child
		else if (root->left && !root->right)
		{
			node * hold = root->left;
			delete root;
			root = hold;
		}

		// Match has right child
		else if (!root->left && root->right)
		{
			node * hold = root->right;
			delete root;
			root = hold;
		}

		// Match has two children
		else
		{
			node * current = root->right;
			node * hold{nullptr};

			// Current has no left child
			if (!current->left)
			{
				// delete root data
				root->data.recycle();

				// Copy current data into root data
				root->data.copy(current->data);

				// Delete and Reconnect
				hold = current->right;
				delete current;
				root->right = hold;
			}

			// Current has Left child
			else
			{
				node * prev{current};

				// Traverse to IOS and hold previous node
				while (current->left)
				{
					prev = current;
					current = current->left;
				}

				// Delete Root data
				root->data.recycle();

				// Copy IOS Data into root
				root->data.copy(current->data);

				// Delete IOS and Reconnect
				hold = current->right;
				delete current;
				prev->left = hold;
			}
		}

		// Success
		return 1;
	}

	// Move to next node if no match
	else
	{
		if (root->data.name_after(name))
			return remove(root->right, name);
		return remove(root->left, name);
	}
}


// (Wrapper) Peek an Item
int table::retrieve(const char name[], product & item)
{
	// Empty List
	if (!root) return 0;

	// Found Match or no match
	if (retrieve(root, name, item)) return 1;
	return -1;
}

// (Recursive) Peek an Item
int table::retrieve(node * root, const char name[], product & item)
{
	if (!root) return 0;
	
	// Match!
	if (root->data.retrieve(name))
	{
		// Grab data
		item.copy(root->data);
		return 1;
	}

	// No match, traverse farther
	if (root->data.name_after(name))
		return retrieve(root->right, name, item);
	return retrieve(root->left, name, item);
}


// (Wrapper) Display all items within price range
int table::display_price(float low, float high) const
{
	// Empty Tree
	if (!root) return 0;

	cout << "\n\nProduct(s) Within that Price Range is/are:\n" << endl;

	// If we found matches
	if (display_price(root, low, high)) return 1;
	
        // If we did not display anything	
	return -1;
}

// (Recursive) Display all items within price range
int table::display_price(node * root, float low, float high) const
{
	if (!root) return 0;
	
	// Go all the way left
	int left = display_price(root->left, low, high);

	// Check if in price range
	int count{};
	if (root->data.price_range(low, high))
	{
		root->data.display();
		++count; // We found a match
	}

	// Go all the way right
	int right = display_price(root->right, low, high);

	return left + right + count;
}


// (Wrapper) Finds height of tree
int table::height() const
{
	// Empty Tree
	if (!root) return 0;

	return height(root);
}

// (Recursive) Finds Height of tree
int table::height(node * root) const
{
	if (!root) return 0;

	int left = height(root->left) + 1;
	int right = height(root->right) + 1;
	
	// return the bigger height
	return max(left, right);
}


// Returns the bigger number of the two
int table::max(const int num1, const int num2) const
{
	if (num1 >= num2) return num1;
	return num2;
}
