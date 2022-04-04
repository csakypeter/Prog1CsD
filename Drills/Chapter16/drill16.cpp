#include "Graph.h"
#include "Lines_window.h"

/*
1. Make a completely new project with linker settings for FLTK (as de-
scribed in Appendix D).
2. Using the facilities of Graph_lib , type in the line-drawing program from
§16.5 and get it to run.
3. Modify the program to use a pop-up menu as described in §16.7 and get
it to run.
4. Modify the program to have a second menu for choosing line styles and
get it to run.
*/

int main()
{
	using namespace Graph_lib;

	Lines_window win{Point{100, 100}, 1280, 720, "Window"};

	return gui_main();
}

