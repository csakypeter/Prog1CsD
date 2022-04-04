#include "Graph.h"

/*
1. Define template<typename T> struct S { T val; }; .
2. Add a constructor, so that you can initialize with a T .
3. Define variables of types S<int> , S<char> , S<double> , S<string> , and
S<vector<int>> ; initialize them with values of your choice.
4. Read those values and print them.
5. Add a function template get() that returns a reference to val .
6. Put the definition of get() outside the class.
7. Make val private.
8. Do 4 again using get() .
9. Add a set() function template so that you can change val .
10. Replace set() with an S<T>::operator=(const T&) . Hint: Much simpler
than §19.2.5.
11. Provide const and non- const versions of get() .
12. Define a function template<typename T> read_val(T& v) that reads from
cin into v .
13. Use read_val() to read into each of the variables from 3 except the
S<vector<int>> variable.
14. Bonus: Define input and output operators ( >> and << ) for vector<T> s.
For both input and output use a { val, val, val } format. That will allow
read_val() to also handle the S<vector<int>> variable.
*/

template<typename T>
struct S {
	S() {}

	S(T t) : val(t) {}

	S& operator=(const T&);

	T& get();
	const T& get() const;

private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
	val = s;
	return *this;
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

int main()
try{

	S<int> si(1);
	cout << si.get() << endl;
	
	S<char> sc('h');
	cout << sc.get() << endl;
	
	S<double> sd(3.14);
	cout << sd.get() << endl;
	
	S<string> ss("Help");
	cout << ss.get() << endl;
	
	S<vector<int>> vi(vector<int>(10,10));
	for (int i : vi.get()) cout << i << ' '; cout << '\n';

	ss = "Meow";
	cout << ss.get() << endl;
	
	cout << "Input a string: " << endl;
	read_val(ss.get());
	cout << ss.get() << endl;

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
