#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
try
{	
	Simple_window win {Point{100, 100}, 600, 600, "Function graphs"};

	Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
	x.set_color(Color::red);
	
	Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
	y.set_color(Color::red);


	constexpr double range_min = -10;
	constexpr double range_max = 11;
	
	const Point orig {300, 300};
	
	constexpr int max_points = 400;
	
	constexpr double x_scale = 20;
	constexpr double y_scale = 20;

	Function f_one {one, range_min, range_max, orig, max_points, x_scale, y_scale};
	
	Function f_slope {slope, range_min, range_max, orig, max_points, x_scale, y_scale};
	Text slope_label {Point{100, 385}, "x/2"};

	Function f_square {square, range_min, range_max, orig, max_points, x_scale, y_scale};

	Function f_cos {cos, range_min, range_max, orig, max_points, x_scale, y_scale};
	f_cos.set_color(Color::blue);

	Function f_sloping_cos {sloping_cos, range_min, range_max, orig, max_points, x_scale, y_scale};

	win.attach(f_sloping_cos);
	win.attach(f_cos);
	win.attach(f_square);
	win.attach(slope_label);	
	win.attach(f_slope);
	win.attach(f_one);
	win.attach(y);
	win.attach(x);

	win.wait_for_button();
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
