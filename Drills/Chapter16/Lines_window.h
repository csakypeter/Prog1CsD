#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	Menu color_menu;
	Menu style_menu;

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;
	Button color_menu_button;
	Button style_menu_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

	void red_pressed();
	void blue_pressed();
	void black_pressed();

	void solid_pressed();
	void dash_pressed();
	void dot_pressed();
	void dashdot_pressed();
	void dashdotdot_pressed();

	void color_menu_pressed();
	void style_menu_pressed();

	void change_style(Line_style style);
	void change_color(Color c);
	void hide_color_menu();
	void hide_style_menu();
};
