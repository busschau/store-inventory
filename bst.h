/* Abe Busschau -- abusschau@gmail.com
 *
 *
 * For this program, we will be using a binary search tree as our data structure. We 
 * will be making a sorting/storage of inventory for a store.
 *
 * This File is the header file. It will hold the class prototypes and Other information
*/

#include <iostream>
#include <cctype>
#include <cstring>

const int SIZE{200}; // For my temp arrays when needed


// Product Details
class product
{
        public:
                product(); // Constructor
                ~product(); // Destructor
                void add(); // Add information
                void copy(const product & to_copy); // Copy information
                void recycle(); // Resets all of the product data so I can use it again
                void display() const; // Displays current information
                int retrieve(const char title[]) const; // Sees if it is a match
		int price_range(float low, float high) const; // Checks if in range
		int comes_after(const product & item) const; // Returns true if item should go after current object
		int name_after(const char shop_name[]) const; // Same thing as comes after but takes a title as argument rather than class

        private:
                char * title; //  Name of product
                char * info; // Description of item
                char * category; // Category of item
                char * type; // What type of product (vintage, Homemade, etc)
                float price; // Price of item
                int quantity; // Quantity of item
                char * id; // Seller ID
                char * name; // Name of Shop selling
};

// Nodes in my BST
struct node
{
	product data; // Product Details
	node * left; // Left Child
	node * right; // Right Child
};

// BST Class Information
class table
{
	public:
		table(); // Constructor
		~table(); // Destructor
		int insert(const product & item); // Insert Data into BST
		int display_all() const; // Display all information
		int remove(const char name[]); // Remove Item
		int retrieve(const char name[], product & item); // Peek an Item
		int display_price(float low, float high) const; // Display all items within price range
		int height() const; // Finds height of tree

	private:
		node * root; // My root of BST

		int destructor(node *& root); // Recursive function for my destructor
		int insert(node *& root, const product & item); // Recursive function for Insert
		int display_all(node * root) const; // Recursive function for display_all
		int remove(node *& root, const char name[]); // Recursive function for remove
		int retrieve(node * root, const char name[], product & item); // Recursive function for retrieve
		int display_price(node * root, float low, float high) const; // Recursive function for display_price
		int height(node * root) const; // Recursive function for finding height

		int max(const int num1, const int num2) const; // Returns the bigger number of the two
};

void upper_case(char word[]); // Turns char array all upper case
