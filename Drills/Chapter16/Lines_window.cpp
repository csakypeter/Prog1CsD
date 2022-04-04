#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy, w, h, title},
    
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
        
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
  
    color_menu_button{Point{x_max()-450, 0}, 150, 40, "Color menu",
	[](Address, Address pw) {reference_to<Lines_window>(pw).color_menu_pressed();}},
    
    style_menu_button{Point{x_max()-600, 0}, 150, 40, "Style menu",
	[](Address, Address pw) {reference_to<Lines_window>(pw).style_menu_pressed();}},
    
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    
    color_menu{Point{x_max()-450, 0}, 150, 40,Menu::vertical, "Colors"},
    
    style_menu{Point{x_max()-600, 0}, 150, 40,Menu::vertical, "Styles"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    
    color_menu.attach(new Button(Point{0,0},0,0,"Red",
	[](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}));
    color_menu.attach(new Button(Point{0,0},0,0,"Blue",
	[](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}));
    color_menu.attach(new Button(Point{0,0},0,0,"Black",
	[](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}));
    attach(color_menu);
    color_menu.hide();
    attach(color_menu_button);
    
    style_menu.attach(new Button(Point{0,0},0,0,"Solid",
	[](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();}));
    style_menu.attach(new Button(Point{0,0},0,0,"Dash",
	[](Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed();}));
    style_menu.attach(new Button(Point{0,0},0,0,"Dot",
	[](Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed();}));
    style_menu.attach(new Button(Point{0,0},0,0,"DashDot",
	[](Address, Address pw) {reference_to<Lines_window>(pw).dashdot_pressed();}));
    style_menu.attach(new Button(Point{0,0},0,0,"DashDotDot",
	[](Address, Address pw) {reference_to<Lines_window>(pw).dashdotdot_pressed();}));
    attach(style_menu);
    style_menu.hide();
    attach(style_menu_button);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point{x,y});

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------

void Lines_window::color_menu_pressed()
{
	color_menu_button.hide();
	color_menu.show();
}

void Lines_window::red_pressed()
{
	change_color(Color::red);
	hide_color_menu();
	redraw();
}

void Lines_window::blue_pressed()
{
	change_color(Color::blue);
	hide_color_menu();
	redraw();
}

void Lines_window::black_pressed()
{
	change_color(Color::black);
	hide_color_menu();
	redraw();
}

void Lines_window::change_color(Color c)
{
	lines.set_color(c);
}

void Lines_window::hide_color_menu()
{
	color_menu.hide();
	color_menu_button.show();
}

//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------

void Lines_window::style_menu_pressed()
{
	style_menu_button.hide();
	style_menu.show();
}

void Lines_window::solid_pressed()
{
	change_style(Line_style::solid);
	hide_style_menu();
	redraw();
}

void Lines_window::dash_pressed()
{
	change_style(Line_style::dash);
	hide_style_menu();
	redraw();
}

void Lines_window::dot_pressed()
{
	change_style(Line_style::dot);
	hide_style_menu();
	redraw();
}

void Lines_window::dashdot_pressed()
{
	change_style(Line_style::dashdot);
	hide_style_menu();
	redraw();
}

void Lines_window::dashdotdot_pressed()
{
	change_style(Line_style::dashdotdot);
	hide_style_menu();
	redraw();
}

void Lines_window::change_style(Line_style style)
{
	lines.set_style(style);
}

void Lines_window::hide_style_menu()
{
	style_menu.hide();
	style_menu_button.show();
}


