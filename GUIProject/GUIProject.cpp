

#include <iostream>
#include <sstream>
#include "Graph.h"         // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"
using namespace std;
using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
private:
	std::string a[2] = { "X", "O" };
	int pos;
	Button a1;
	

	void changed();

	static void A1(Address, Address);
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	a1(Point(200, 200), 40, 40, "", A1)
{
	attach(a1);
	pos = 0;
}

void Lines_window::A1(Address, Address pw)    // "the usual"
{
	reference_to<Lines_window>(pw).changed();
}

void Lines_window::changed()
{
	if (pos%2 == 0)
	{
		a1.label = a[0];
	}
	else {
		a1.label = a[1];
	}
	pos++;
}


int main()
try {
    Lines_window win(Point(100,100),600,400,"Temperature Conversion");
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}

//------------------------------------------------------------------------------
