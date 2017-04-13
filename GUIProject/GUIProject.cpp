#include <iostream>
#include <sstream>
#include "Graph.h"         
#include "GUI.h"
#include "Window.h"


using namespace std;
using namespace Graph_lib;


struct Lines_window : Window 
{
	Lines_window(Point xy, int w, int h, const string& title);
private:
	int pos = 0;
	std::string a[2] = {"X", "O"};
	std::string b[9];
	Line l1;
	Line l2;
	Line l3;
	Line l4;
	Button a1;
	Button a2;
	Button a3;
	Button b1;
	Button b2;
	Button b3;
	Button c1;
	Button c2;
	Button c3;
	Button reset;
	Text x1;	Text x2;	Text x3;
	Text x4;	Text x5;	Text x6;
	Text x7;	Text x8;	Text x9;
	Text tic_tac_TITLE;

	void a1_button();
	void a2_button();
	void a3_button();
	void b1_button();
	void b2_button();
	void b3_button();
	void c1_button();
	void c2_button();
	void c3_button();
	int buttonReset();
	void checkStatus()
	{
		if ((b[0] == "X" && b[1] == "X" && b[2] == "X")
			|| (b[0] == "O" && b[1] == "O" && b[2] == "O"))
		{
			Lines_window::clear();
			tic_tac_TITLE.set_label("PLAYER " + b[0] + " WINS!");
		}
		if ((b[0] == "X" && b[4] == "X" && b[8] == "X")
			|| (b[0] == "O" && b[4] == "O" && b[8] == "O"))
		{
			Lines_window::clear();
			tic_tac_TITLE.set_label("PLAYER " + b[0] + " WINS!");
		}
		if ((b[0] == "X" && b[3] == "X" && b[6] == "X")
			|| (b[0] == "O" && b[3] == "O" && b[6] == "O"))
		{
			Lines_window::clear();
			tic_tac_TITLE.set_label("PLAYER " + b[0] + " WINS!");
		}
		if ((b[1] == "X" && b[4] == "X" && b[7] == "X")
			|| (b[1] == "O" && b[4] == "O" && b[7] == "O"))
		{
			Lines_window::clear();
			tic_tac_TITLE.set_label("PLAYER " + b[1] + " WINS!");
		}
		if ((b[2] == "X" && b[5] == "X" && b[8] == "X")
			|| (b[2] == "O" && b[5] == "O" && b[8] == "O"))
		{
			Lines_window::clear();
			tic_tac_TITLE.set_label("PLAYER " + b[2] + " WINS!");
		}
		if ((b[3] == "X" && b[4] == "X" && b[5] == "X")
			|| (b[3] == "O" && b[4] == "O" && b[5] == "O"))
		{
			Lines_window::clear();
			tic_tac_TITLE.set_label("PLAYER " + b[3] + " WINS!");
		}
		if ((b[6] == "X" && b[7] == "X" && b[8] == "X")
			|| (b[6] == "O" && b[7] == "O" && b[8] == "O"))
		{
			Lines_window::clear();
			tic_tac_TITLE.set_label("PLAYER " + b[6] + " WINS!");
		}
		if ((b[2] == "X" && b[4] == "X" && b[6] == "X")
			|| (b[2] == "O" && b[4] == "O" && b[6] == "O"))
		{
			Lines_window::clear();
			tic_tac_TITLE.set_label("PLAYER " + b[2] + " WINS!");
		}
		attach(reset);
	}

	static void A1(Address, Address);
	static void A2(Address, Address);
	static void A3(Address, Address);
	static void B1(Address, Address);
	static void B2(Address, Address);
	static void B3(Address, Address);
	static void C1(Address, Address);
	static void C2(Address, Address);
	static void C3(Address, Address);
	static void resetButton(Address, Address);
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	a1(Point(200, 200), 40, 40, "", A1),
	a2(Point(250, 200), 40, 40, "", A2),
	a3(Point(300, 200), 40, 40, "", A3),
	b1(Point(200, 250), 40, 40, "", B1),
	b2(Point(250, 250), 40, 40, "", B2),
	b3(Point(300, 250), 40, 40, "", B3),
	c1(Point(200, 300), 40, 40, "", C1),
	c2(Point(250, 300), 40, 40, "", C2),
	c3(Point(300, 300), 40, 40, "", C3),
	x1(Point(370, 230), "_"),
	x2(Point(400, 230), "_"),
	x3(Point(430, 230), "_"),
	x4(Point(370, 280), "_"),
	x5(Point(400, 280), "_"),
	x6(Point(430, 280), "_"),
	x7(Point(370, 330), "_"),
	x8(Point(400, 330), "_"),
	x9(Point(430, 330), "_"),
	l1(Point(390, 200), Point(390, 350)),
	l2(Point(420, 200), Point(420, 350)),
	l3(Point(360, 250), Point(450, 250)),
	l4(Point(360, 300), Point(450, 300)),
	tic_tac_TITLE(Point(200, 100), "TIC-TAC-TOE"),
	reset(Point(200, 40), 50, 20, "Reset", resetButton)
{
	attach(reset);
	attach(a1);
	attach(a2);
	attach(a3);
	attach(b1);
	attach(b2);
	attach(b3);
	attach(c1);
	attach(c2);
	attach(c3);
	attach(x1);	attach(x2);	attach(x3);
	attach(x4);	attach(x5);	attach(x6);
	attach(x7);	attach(x8);	attach(x9);
	x1.set_font_size(18);	x2.set_font_size(18);	x3.set_font_size(18);
	x4.set_font_size(18);	x5.set_font_size(18);	x6.set_font_size(18);
	x7.set_font_size(18);	x8.set_font_size(18);	x9.set_font_size(18);
	x1.set_color(Color::black);	x2.set_color(Color::black);	x3.set_color(Color::black);
	x4.set_color(Color::black);	x5.set_color(Color::black);	x6.set_color(Color::black);
	x7.set_color(Color::black);	x8.set_color(Color::black);	x9.set_color(Color::black);
	attach(l1);
	attach(l2);
	attach(l3);
	attach(l4);
	attach(tic_tac_TITLE);
	tic_tac_TITLE.set_font_size(30);
	tic_tac_TITLE.set_color(Color::dark_blue);
	l1.set_color(Color::black);
	l2.set_color(Color::black);
	l3.set_color(Color::black);
	l4.set_color(Color::black);
}

void Lines_window::resetButton(Address, Address pw)
{
	reference_to<Lines_window>(pw).buttonReset();
}

int Lines_window::buttonReset()
{
	hide();
	Lines_window win(Point(100, 100), 600, 400, "TIC-TAC-TOE");
	return gui_main();
}

void Lines_window::A1(Address, Address pw)    
{
	reference_to<Lines_window>(pw).a1_button();
}

void Lines_window::a1_button()
{
	a1.hide();
	
	if (pos == 0)
	{
		x1.set_label(a[pos]);
		b[0] = a[pos];
		pos = 1;
	}	
	else if (pos == 1)
	{
		x1.set_label(a[pos]);
		b[0] = a[pos];
		pos = 0;
	}
	checkStatus();
}

void Lines_window::A2(Address, Address pw)
{
	reference_to<Lines_window>(pw).a2_button();
}

void Lines_window::a2_button()
{
	a2.hide();

	if (pos == 0)
	{
		x2.set_label(a[pos]);
		b[1] = a[pos];
		pos = 1;
	}
	else if (pos == 1)
	{
		x2.set_label(a[pos]);
		b[1] = a[pos];
		pos = 0;
	}
	checkStatus();
}

void Lines_window::A3(Address, Address pw)
{
	reference_to<Lines_window>(pw).a3_button();
}

void Lines_window::a3_button()
{
	a3.hide();

	if (pos == 0)
	{
		x3.set_label(a[pos]);
		b[2] = a[pos];
		pos = 1;
	}
	else if (pos == 1)
	{
		x3.set_label(a[pos]);
		b[2] = a[pos];
		pos = 0;
	}
	checkStatus();
}

void Lines_window::B1(Address, Address pw)
{
	reference_to<Lines_window>(pw).b1_button();
}

void Lines_window::b1_button()
{
	b1.hide();

	if (pos == 0)
	{
		x4.set_label(a[pos]);
		b[3] = a[pos];
		pos = 1;
	}
	else if (pos == 1)
	{
		x4.set_label(a[pos]);
		b[3] = a[pos];
		pos = 0;
	}
	checkStatus();
}

void Lines_window::B2(Address, Address pw)
{
	reference_to<Lines_window>(pw).b2_button();
}

void Lines_window::b2_button()
{
	b2.hide();

	if (pos == 0)
	{
		x5.set_label(a[pos]);
		b[4] = a[pos];
		pos = 1;
	}
	else if (pos == 1)
	{
		x5.set_label(a[pos]);
		b[4] = a[pos];
		pos = 0;
	}
	checkStatus();
}

void Lines_window::B3(Address, Address pw)
{
	reference_to<Lines_window>(pw).b3_button();
}

void Lines_window::b3_button()
{
	b3.hide();
	if (pos == 0)
	{
		x6.set_label(a[pos]);
		b[5] = a[pos];
		pos = 1;
	}
	else if (pos == 1)
	{
		x6.set_label(a[pos]);
		b[5] = a[pos];
		pos = 0;
	}
	checkStatus();
}

void Lines_window::C1(Address, Address pw)
{
	reference_to<Lines_window>(pw).c1_button();
}

void Lines_window::c1_button()
{
	c1.hide();

	if (pos == 0)
	{
		x7.set_label(a[pos]);
		b[6] = a[pos];
		pos = 1;
	}
	else if (pos == 1)
	{
		x7.set_label(a[pos]);
		b[6] = a[pos];
		pos = 0;
	}
	checkStatus();
}

void Lines_window::C2(Address, Address pw)
{
	reference_to<Lines_window>(pw).c2_button();
}

void Lines_window::c2_button()
{
	c2.hide();

	if (pos == 0)
	{
		x8.set_label(a[pos]);
		b[7] = a[pos];
		pos = 1;
	}
	else if (pos == 1)
	{
		x8.set_label(a[pos]);
		b[7] = a[pos];
		pos = 0;
	}
	checkStatus();
}

void Lines_window::C3(Address, Address pw)
{
	reference_to<Lines_window>(pw).c3_button();
}

void Lines_window::c3_button()
{
	c3.hide();

	if (pos == 0)
	{
		x9.set_label(a[pos]);
		b[8] = a[pos];
		pos = 1;
	}
	else if (pos == 1)
	{
		x9.set_label(a[pos]);
		b[8] = a[pos];
		pos = 0;
	}
	checkStatus(); 
}

struct Conversion : Window
{
	Conversion(Point xy, int w, int h, const string& title);

private:

};

Conversion::Conversion(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title)
{
	
}

struct Main_Screen : Window
{
	Main_Screen(Point xy, int w, int h, const string& title);
private:

	Text TITLE;
	Button TIC_TAC_TOE;
	Button exiting;
	Button conversion;

	void exiting_project();
	int convert_currency();
	int tictactoe_open();

	static void open_tictactoe(Address, Address);
	static void exit_project(Address, Address);
	static void currency_convert(Address, Address);
};

Main_Screen::Main_Screen(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	TITLE(Point(200, 50), "C++ Final Project"),
	TIC_TAC_TOE(Point(200, 100), 150, 40, "TIC TAC TOE", open_tictactoe),
	exiting(Point(200, 300), 50, 20, "EXIT", exit_project),
	conversion(Point(200, 150), 150, 40, "Currency Conversion", currency_convert)
{
	attach(TITLE);
	attach(TIC_TAC_TOE);
	attach(exiting);
	attach(conversion);
}

void Main_Screen::exit_project(Address, Address pw)
{
	reference_to<Main_Screen>(pw).exiting_project();
}

void Main_Screen::currency_convert(Address, Address pw)
{
	reference_to<Main_Screen>(pw).convert_currency();
}

int Main_Screen::convert_currency()
{
	Conversion win(Point(100, 100), 600, 400, "Currency Conversion");
	return gui_main();
}

void Main_Screen::exiting_project()
{
	exit(0);
}

void Main_Screen::open_tictactoe(Address, Address pw)
{
	reference_to<Main_Screen>(pw).tictactoe_open();
}

int Main_Screen::tictactoe_open()
{
	Lines_window w(Point(100, 100), 600, 400, "TIC-TAC-TOE");
	return gui_main();
}


int main()
try {
	Main_Screen win(Point(100, 100), 600, 400, "C++ Project");
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