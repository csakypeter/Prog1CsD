#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

int main()
try
{
	using namespace Graph_lib;

	Point tl {50,50};

	Simple_window win {tl, 800, 1000, "Simple window"};
	
	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for (int y = y_grid; y<y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});
		
	win.attach(grid);
		
	Vector_ref<Rectangle> vr;
	
	for (int i = 0; i<8; ++i)
	{
			vr.push_back(new Rectangle{Point{0,i*100},100,100});
			vr[i].set_color(Color::red);
			win.attach(vr[i]);
	}

	Image homer1 {Point{100,0}, "200by200homer.jpg"};
	Image homer2 {Point{600,200}, "200by200homer.jpg"};
	Image homer3 {Point{300,400}, "200by200homer.jpg"};

	win.attach(homer1);
	win.attach(homer2);
	win.attach(homer3);

	Image homerNew {Point{0, 0}, "200by200homer.jpg"};
	homerNew.set_mask(Point{0, 0}, 100, 100);
	
	//homerNew.move(100, 100);

	win.attach(homerNew);
	
	win.wait_for_button();

	/*for (int i = 0; i<8; ++i)
		for (int j = 0; j<8; ++j)
		{
			homer_move.move(i*100, j*100);
		
			win.wait_for_button();
		}
	*/
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
