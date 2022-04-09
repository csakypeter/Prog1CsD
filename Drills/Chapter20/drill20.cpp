#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

/*
1. Define an array of int s with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
2. Define a vector<int> with those ten elements.
3. Define a list<int> with those ten elements.
4. Define a second array, vector, and list, each initialized as a copy of the first
array, vector, and list, respectively.
5. Increase the value of each element in the array by 2; increase the value of
each element in the vector by 3; increase the value of each element in the
list by 5.
6. Write a simple copy() operation,
template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);
that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the
standard library copy function. Note that if f1==e1 the sequence is empty,
so that there is nothing to copy.
7. Use your copy() to copy the array into the vector and to copy the list into
the array.
8. Use the standard library find() to see if the vector contains the value 3
and print out its position if it does; use find() to see if the list contains the
value 27 and print out its position if it does. The “position” of the first
element is 0, the position of the second element is 1, etc. Note that if find()
returns the end of the sequence, the value wasn’t found.
*/

template<typename T>
void printCustom(T container)
{
	for(auto& i : container)
		cout << i << ' ';
	
	cout << endl;
}

template<typename T>
void increase(T& container, int num)
{
	for(auto& i : container)
		i += num;	
}

template<typename Iter1, typename Iter2>
Iter2 copyCustom(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1 != e1)
	{
		*f2 = *f1;
		++f2; ++f1;
	}
	
	return f2;
}

int vectorSearch(vector<int> v, int num)
{
	vector<int>::iterator it;

	it = find(v.begin(), v.end(), num);
	if (it != v.end())
		return distance(v.begin(), it);
	else return -1;
}

int listSearch(list<int> l, int num)
{
	list<int>::iterator it;

	it = find(l.begin(), l.end(), num);
	if (it != l.end())
		return distance(l.begin(), it);
	else return -1;
}

int main()
try{
	constexpr int size = 10;
	array<int, size> ai = {0,1,2,3,4,5,6,7,8,9};
	
	vector<int> vi(size);
	copy(ai.begin(), ai.end(), vi.begin());
	
	list<int> li(size);
	copy(ai.begin(), ai.end(), li.begin());

	array<int, size> ai_cp = ai;
	vector<int> vi_cp = vi;
	list<int> li_cp = li;

	increase(ai, 2);
	increase(vi, 3);
	increase(li, 5);
	
	cout << "Increased array: " << endl;
	printCustom(ai);
	
	cout << "Increased vector: " << endl;
	printCustom(vi);
	
	cout << "Increased list: " << endl;
	printCustom(li);
	
	copyCustom(ai.begin(), ai.end(), vi.begin());
	copyCustom(li.begin(), li.end(), ai.begin());

	cout << "\nCustom copied array into vector: " << endl;
	printCustom(vi);
	
	cout << "Custom copied list into array: " << endl;
	printCustom(ai);

	if (vectorSearch(vi, 3) >= 0)
		cout << "Value 3 found in vector at pos: " << vectorSearch(vi, 3) << endl;
	else cout << "Value 3 not found in vector" << endl;
	
	if (listSearch(li, 27) >= 0)
		cout << "Value 27 found in list at pos: " << listSearch(li, 27) << endl;
	else cout << "Value 27 not found in list" << endl;

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
