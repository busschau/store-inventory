/* Abe Busschau -- abusschau@gmail.com
 *
 *
 * For this program, we will be using a binary search tree as our data structure. We 
 * will be making a sorting/storage of inventory for a store.
 *
 * This File is the class implementation for the products themselves. It will hold the products and their respected info.
*/

#include "bst.h"
using namespace std;

// Constructor
product::product()
{
	title = nullptr;
	info = nullptr;
	category = nullptr;
	type = nullptr;
	price = 0;
	quantity = 0;
	id = nullptr;
	name = nullptr;	
}

// Destructor
product::~product()
{
	if (title)
	{
		delete [] title;
		delete [] info;
		delete [] category;
		delete [] type;
		delete [] id;
		delete [] name;
	}
}

// Add Information to private data
void product::add()
{
	char temp[SIZE]; // Temp array to help with filling out data

	// Name of Product
	cout << "\n\nEnter Name of Product: ";
	cin.get(temp, SIZE, '\n'); cin.ignore(100,'\n');

	title = new char[strlen(temp) + 1];
	strcpy(title, temp);

	// Make Title all Upper case
	for (int i{}; title[i] != '\0'; ++i)
	{
		if (isalpha(title[i]))
		{
			title[i] = toupper(title[i]);
		}
	}
	

	// Info on product
	cout << "\nEnter Description of Product: ";
	cin.get(temp, SIZE, '\n'); cin.ignore(100,'\n');

	info = new char[strlen(temp) + 1];
	strcpy(info, temp);

	// Category of Product
	cout << "\nEnter Category(s) of Product (Seperate Categories with '>' Symbol): ";
	cin.get(temp, SIZE, '\n'); cin.ignore(100,'\n');

	category = new char[strlen(temp) + 1];
	strcpy(category, temp);

	// Type
	cout << "\nEnter Product Type (Handmade, Vintage, etc.): ";	
	cin.get(temp, SIZE, '\n'); cin.ignore(100,'\n');

	type = new char[strlen(temp) + 1];
	strcpy(type, temp);

	// Price of Item
	cout << "\nEnter Price of Product: ";
	cin >> price; cin.ignore(100,'\n');

	// Error Check
	while (price < 0)
	{
		cout << "\n\nPrice Must be a Positive Number!\nEnter: ";
		cin >> price; cin.ignore(100, '\n');
	}

	// Quantity of item
	cout << "\nQuantity of Product: ";
	cin >> quantity; cin.ignore(100, '\n');

	// Error Check
	while (quantity < 0)
	{
		cout << "\n\nQuantity Must be a Positive Number!\nEnter: ";
		cin >> quantity; cin.ignore(100, '\n');
	}

	// Seller ID
	cout << "\nEnter Seller ID: ";
	cin.get(temp, SIZE, '\n'); cin.ignore(100, '\n');

	id = new char[strlen(temp) + 1];
	strcpy(id, temp);

	// Name of Shop
	cout << "\nEnter Name of Shop: ";
	cin.get(temp, SIZE, '\n'); cin.ignore(100,'\n');

	name = new char[strlen(temp) + 1];
	strcpy(name, temp);
}

// Copy Information
void product::copy(const product & to_copy)
{
	// Copy Title
	title = new char[strlen(to_copy.title) + 1];
	strcpy(title, to_copy.title);

	// Copy Description
	info = new char[strlen(to_copy.info) + 1];
	strcpy(info, to_copy.info);

	// Copy Category
	category = new char[strlen(to_copy.category) + 1];
	strcpy(category, to_copy.category);

	// Copy Product Type
	type = new char[strlen(to_copy.type) + 1];
	strcpy(type, to_copy.type);

	// Copy Price
	price = to_copy.price;

	// Copy Quantity
	quantity = to_copy.quantity;

	// Copy Seller ID
	id = new char[strlen(to_copy.id) + 1];
	strcpy(id, to_copy.id);

	// Copy Shop Name
	name = new char[strlen(to_copy.name) + 1];
	strcpy(name, to_copy.name);
}

// Resets all of the product data
void product::recycle()
{
	delete [] title;
	title = nullptr;

	delete [] info;
	info = nullptr;

	delete [] category;
	category = nullptr;

	delete [] type;
	type = nullptr;

	price = 0;

	quantity = 0;

	delete [] id;
	id = nullptr;

	delete [] name;
	name = nullptr;
}

// Displays Current Information
void product::display() const
{
	cout << "\n\nTitle: " << title
	     << "\nDescription: " << info
	     << "\nCategory(s): " << category
	     << "\nType: " << type
	     << "\nPrice: " << price
	     << "\nQuantity: " << quantity
	     << "\nSeller ID: " << id
	     << "\nShop Name: " << name << endl;
}

// Sees if it is a match
int product::retrieve(const char name[]) const
{
	if (strcmp(title, name) == 0) return 1;
	return 0;
}	

// Checks if in range of price
int product::price_range(float low, float high) const
{
	if ((price >= low) && (price <= high)) return 1;
	return 0;
}

// returns true if item shoudl go after current object
int product::comes_after(const product & item) const
{
	if (strcmp(item.title, title) >= 0) return 1;
	return 0;
}
		
// Same thing as comes after but takes a title as argument rather than class
int product::name_after(const char shop_name[]) const
{
	if (strcmp(shop_name, title) >= 0) return 1;
	return 0;
}
