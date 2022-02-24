#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

int main()
try
{
	using namespace Graph_lib;

	Point tl {50,50};

	Simple_window win {tl, 600, 400, "My window"}; //12.7.1
	
	Axis xa {Axis::x, Point{20,300}, 300, 10, "x axis"}; //12.7.2
	
	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"}; //12.7.3
	ya.set_color(Color::red);
	ya.label.set_color(Color::yellow);
	
	Function sine {sin,0,100,Point{20,150},1000,50,50}; //12.7.4
	sine.set_style(Line_style::dash);
	sine.set_color(Color::green);

	Polygon poly; // 12.7.5
	poly.add(Point{300,200}); 
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::dark_red);
	poly.set_style(Line_style::dot);

	Rectangle r {Point{200,180}, 150, 75}; //12.7.6
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{150,75});
	
	r.set_fill_color(Color::magenta); // 12.7.7
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dashdotdot,2));
	poly_rect.set_fill_color(Color::green);
	
	Text t {Point{50,150}, "Hello, graphical world!"}; //12.7.8
	t.set_font(Font::helvetica_bold_italic);
	t.set_font_size(20);

	//Image ii {Point{100,50}, "badge.jpg"}; // 12.7.9
	Image ap {Point{100,50}, "apple.jpeg"};
	//ii.move(100,200);
	
	Circle c {Point{100,200},35}; //12.7.10
	c.set_fill_color(Color::red);

	Ellipse e {Point{400,200}, 75,25};
	e.set_color(Color::dark_red);
	
	Mark m {Point{500,120},'x'};
	m.set_color(Color::blue);
	
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	 << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,30},oss.str()};
	
	Image cal {Point{325,225},"snow_cpp.gif"};
	cal.set_mask(Point{40,40},200,150);

	win.attach(cal);
	win.attach(sizes);
	win.attach(c);
	win.attach(m);
	win.attach(e);	
	win.attach(ap);
	//win.attach(ii);
	win.attach(t);
	win.attach(poly_rect);
	win.attach(r);
	win.attach(poly);
	win.attach(sine);
	win.attach(ya);
	win.attach(xa);
	win.wait_for_button();

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
