#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

struct Person
{
private:
	string p_f_name;
	string p_l_name;
	int p_age;
	
	void checkAge(int age);
	void checkName(string first, string last);
public:
	Person() {}
	Person(string fname, string lname, int age) { init(fname, lname, age); }
	
	void init(string fn, string ln, int a)
	{	
		checkName(fn, ln);
		checkAge(a);

		p_f_name = fn;
		p_l_name = ln;
		p_age = a;
	}

	string getFirstName() const { return p_f_name; }
	string getLastName() const { return p_l_name; }
	int getAge() const { return p_age; }
};

void Person::checkName(string first, string last)
{
	string name = first + last;

	for (char c : name)
	{
		switch(c)
		{
		case ';': case ':': case '"': case '[': case ']': case '*':
		case '&': case '^': case '%': case '$': case '#': case '@':
		case '!':
			error("Bad char in name");
			break;
		default:
			break;
		}
	}
}

void Person::checkAge(int age)
{
	if (age < 0 || age > 150)
		error("Age is outside of range 0-150");
}

ostream& operator<<(ostream& os, const Person& p) 
{ 
	os << p.getFirstName() << ' ' << p.getLastName() << ": " << p.getAge() << endl;
	return os; 
}

istream& operator>>(istream& is, Person& p)
{
	string fn, ln;
	int age;
	
	is >> fn >> ln >> age;

	p.init(fn, ln, age);

	return is;
}

int main()
try
{
	/*Person p1 {"Goofy", 63};
	cout << p1 << endl;
	
	Person p2;
	cin >> p2;*/
	
	vector<Person> vec_pers;
	
	cout << "Enter some info about people:" << endl;
	
	for (Person p; cin >> p; )
	{
		if (p.getFirstName() == "end") break;
		vec_pers.push_back(p);
	}

	for (Person p : vec_pers)
	cout << p;
	
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
