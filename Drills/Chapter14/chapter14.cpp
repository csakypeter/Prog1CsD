#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

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











