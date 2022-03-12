#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

/*1. Define a class B1 with a virtual function vf() and a non-virtual function f() .
Define both of these functions within class B1 . Implement each function
to output its name (e.g., B1::vf() ). Make the functions public . Make a B1
object and call each function.
2. Derive a class D1 from B1 and override vf() . Make a D1 object and call vf()
and f() for it.
3. Define a reference to B1 (a B1& ) and initialize that to the D1 object you
just defined. Call vf() and f() for that reference.
4. Now define a function called f() for D1 and repeat 1–3. Explain the results.
5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. Ex-
plain the result.
6. Define a class D2 derived from D1 and override pvf() in D2 . Make an
object of class D2 and invoke f() , vf() , and pvf() for it.
7. Define a class B2 with a pure virtual function pvf() . Define a class D21
with a string data member and a member function that overrides pvf() ;
D21::pvf() should output the value of the string . Define a class D22 that
is just like D21 except that its data member is an int . Define a function f()
that takes a B2& argument and calls pvf() for its argument. Call f() with a
D21 and a D22 .*/

<<<<<<< HEAD
class B1
{
public: 
	virtual void pvf() = 0; //Drill 5
	virtual void vf() { cout << "B1::vf()" << endl; }
	void f() { cout << "B1::f()" << endl; }
};

class D1 : public B1
{
public:
	void vf() override {}
	void f() { cout << "D1::f()" << endl; } //Drill 4
};

class D2 : public D1
{
public:
	void pvf() override { cout << "D2::pvf()" << endl; }
};

class B2
{
public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
public:
	void pvf() override { cout << meow << endl; }

	string meow = "Im a cat :3";
};

class D22 : public D21
{
public:
	void pvf() override { cout << i << endl; }
	void f(B2& testD22Ref) { testD22Ref.pvf(); }
	int i = 7;
};


int main()
try
{	
	/*B1 test; //Drill 1
	
	test.f();
	test.vf();
	test.pvf();
	
	D1 testD; //Drill 2
	
	testD.f();
	testD.vf();
	testD.pvf();
	
	B1& testRef = testD; //Drill 3
	
	testRef.f();
	testRef.vf();
	testRef.pvf();*/
	
	D2 testD2; //Drill 6
	
	testD2.f();
	testD2.vf();
	testD2.pvf();
	
	D21 testD21;
	
	//testD21.f(); -- D21 doesn't have an f() function
	
	D22 testD22;
	
	testD22.f(testD21);
	
	
	
	return 0;
=======
class B1 {
public: 
	virtual void vf() const ( cout << "B1::vf()" << endl; );
	void f() const ( cout << "B1::vf()" << endl; );
};

class D1 : public B1 {
public:
	virtual void vf() const ( cout << "D1::vf()" << endl; );
	void f() const ( cout << "D1::vf()" << endl; );
};
};


int main()
try
{	
	B1 test;
	
	test.f();
	
	test.vf();
	
	D1 testD;
	
	testD.f();
	
	testD.vf();
>>>>>>> e20287ccd6495dc8855b6407b2191995dfd82830
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
