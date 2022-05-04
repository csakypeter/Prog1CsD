#include <iostream>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

/*
1. Define a struct Item { string name; int iid; double value; ... }; , make
a vector<Item> , vi , and fill it with ten items from a file.
2. Sort vi by name.
3. Sort vi by iid .
4. Sort vi by value; print it in order of decreasing value (i.e., largest value
first).
5. Insert Item("horse shoe",99,12.34) and Item("Canon S400", 9988,499.95) .
6. Remove (erase) two Item s identified by name from vi .
7. Remove (erase) two Item s identified by iid from vi .
8. Repeat the exercise with a list<Item> rather than a vector<Item> .
*/

struct Item {
	string name;
	int iid;
	double value;
	
	Item() : name("unknown"), iid(-1), value(0) {}
	Item(string n, int id, double val) : name(n), iid(id), value(val) {}
};

ostream& operator<<(ostream& os, Item& item)
{
	return os << "|" << item.name << ' ' << item.iid << ' ' << item.value << "|" << endl;
}

istream& operator>>(istream& is, Item& item)
{
	char dummy;
	is >> dummy;
	if(dummy != '|')
	{
		is.unget();
		return is;
	}
	
	is >> item.name >> item.iid >> item.value;
	
	return is;
}

template <class RandomAccessIterator, class Compare>
	void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);

int main()
try
{
	vector<Item> vi;
	
	ifstream indata;
	indata.open("items.txt");
	
	if(!indata)
	{
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	
	for(int i = 0; i < 10; i++)
	{
		Item item;
		indata >> item;
		vi.push_back(item);
	}
	
	indata.close();
	
	sort(
	
	return 0;
}

catch(exception& e)
{
	cerr << "exception: " << e.what() << '\n';
	return 1;
}

catch(...)
{
	cerr << "error\n";
	return 2;
}
