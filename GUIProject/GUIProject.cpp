/*
Author: Samartha Mudigere
CSE-232 Oakland University Final Project
*/
#include <iostream>
#include <sstream>
#include "Graph.h"         
#include "GUI.h"
#include "Window.h"
#include <WinInet.h>
#pragma comment(lib,"Wininet.lib")

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
	Text From;
	Button USD;
	Button CAN;
	Button INR;
	Button EUR;
	Button CNY;
	Button USDto;
	Button CANto;
	Button INRto;
	Button EURto;
	Button CNYto;
	Out_box result;
	Button reset;

	std::string from;
	void button_usd();
	void button_can();
	void button_inr();
	void button_eur();
	void button_cny();
	void inrto();
	void usdto();
	void canto();
	void eurto();
	void cnyto();
	int button_reset();
	void onFromClick()
	{
		From.set_label("Choose the Currency you want to Convert to:");
		USD.hide();
		CAN.hide();
		INR.hide();
		EUR.hide();
		CNY.hide();
		attach(USDto);
		attach(CANto);
		attach(INRto);
		attach(EURto);
		attach(CNYto);

		if (from == "USD")
		{
			USDto.hide();
		} else
		if (from == "CAD")
		{
			CANto.hide();
		}
		else
		if (from == "INR")
		{
			INRto.hide();
		}
		else
		if (from == "EUR")
		{
			EURto.hide();
		}
		else
		if (from == "CNY")
		{
			CNYto.hide();
		}
	}

	static void usd_button(Address, Address);
	static void can_button(Address, Address);
	static void inr_button(Address, Address);
	static void eur_button(Address, Address);
	static void cny_button(Address, Address);
	static void inrto_button(Address, Address);
	static void usdto_button(Address, Address);
	static void reset_button(Address, Address);
	static void canto_button(Address, Address);
	static void eurto_button(Address, Address);
	static void cnyto_button(Address, Address);
};
//USD/CAN/INR/EUR/CNY
Conversion::Conversion(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	From(Point(100, 30), "Choose the Currency you want to Convert from:"),
	USD(Point(100, 50), 50, 30, "USD", usd_button),
	CAN(Point(100, 85), 50, 30, "CAD", can_button),
	INR(Point(100, 120), 50, 30, "INR", inr_button),
	EUR(Point(100, 155), 50, 30, "EUR", eur_button),
	CNY(Point(100, 190), 50, 30, "CNY", cny_button),
	USDto(Point(325, 50), 50, 30, "USD", usdto_button),
	CANto(Point(325, 85), 50, 30, "CAD", canto_button),
	INRto(Point(325, 120), 50, 30, "INR", inrto_button),
	EURto(Point(325, 155), 50, 30, "EUR", eurto_button),
	CNYto(Point(325, 190), 50, 30, "CNY", cnyto_button),
	result(Point(200, 275), 175, 50, ""),
	reset(Point(300, 325), 50, 20, "Reset", reset_button)
{
	attach(USD);
	attach(CAN);
	attach(INR);
	attach(EUR);
	attach(CNY);
	attach(From);
	From.set_color(Color::dark_blue);
	attach(reset);
}

void Conversion::cnyto_button(Address, Address pw)
{
	reference_to<Conversion>(pw).cnyto();
}

void Conversion::cnyto()
{
	bool bConnect = InternetCheckConnection(L"http://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0);

	if (bConnect)
	{
		std::string url = "\"http://api.fixer.io/latest?base=";
		url.append(from);
		url.append("&symbols=");
		url.append(from);
		url.append(",CNY\"");

		system(("curl " + url + " > to_CNY.txt").c_str());
		std::ifstream inFile;
		std::string str;
		inFile.open("to_CNY.txt");

		while (!inFile.eof())
		{
			getline(inFile, str); // Saves the line in STRING.
		}
		std::vector<std::string> v;
		char c = ':';

		std::string buff{ "" };

		for (auto n : str)
		{
			if (n != c) buff += n; else
				if (n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		inFile.close();


		char a = '}';
		buff = "";

		for (auto n : v[4])
		{
			if (n != a) buff += n; else
				if (n == a && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		std::cout << "\n\n" << v[5];

		attach(result);
		USDto.hide();
		CANto.hide();
		INRto.hide();
		EURto.hide();
		CNYto.hide();
		detach(From);
		result.put("   1 " + from + " = " + v[5] + " CNY");
	}
	else {
		system("start \"\" cmd /c \"echo Check Internet Connection!&echo(&pause\"");
	}
}

void Conversion::eurto_button(Address, Address pw)
{
	reference_to<Conversion>(pw).eurto();
}

void Conversion::eurto()
{
	bool bConnect = InternetCheckConnection(L"http://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0);

	if (bConnect)
	{
		std::string url = "\"http://api.fixer.io/latest?base=";
		url.append(from);
		url.append("&symbols=");
		url.append(from);
		url.append(",EUR\"");

		system(("curl " + url + " > to_EUR.txt").c_str());
		std::ifstream inFile;
		std::string str;
		inFile.open("to_EUR.txt");

		while (!inFile.eof())
		{
			getline(inFile, str); // Saves the line in STRING.
		}
		std::vector<std::string> v;
		char c = ':';

		std::string buff{ "" };

		for (auto n : str)
		{
			if (n != c) buff += n; else
				if (n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		inFile.close();


		char a = '}';
		buff = "";

		for (auto n : v[4])
		{
			if (n != a) buff += n; else
				if (n == a && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		std::cout << "\n\n" << v[5];

		attach(result);
		USDto.hide();
		CANto.hide();
		INRto.hide();
		EURto.hide();
		CNYto.hide();
		detach(From);
		result.put("   1 " + from + " = " + v[5] + " EUR");
	}
	else {
		system("start \"\" cmd /c \"echo Check Internet Connection!&echo(&pause\"");
	}
}

void Conversion::canto_button(Address, Address pw)
{
	reference_to<Conversion>(pw).canto();
}

void Conversion::canto()
{
	bool bConnect = InternetCheckConnection(L"http://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0);

	if (bConnect)
	{
		std::string url = "\"http://api.fixer.io/latest?base=";
		url.append(from);
		url.append("&symbols=");
		url.append(from);
		url.append(",CAD\"");

		system(("curl " + url + " > to_CAD.txt").c_str());
		std::ifstream inFile;
		std::string str;
		inFile.open("to_CAD.txt");

		while (!inFile.eof())
		{
			getline(inFile, str); // Saves the line in STRING.
		}
		std::vector<std::string> v;
		char c = ':';

		std::string buff{ "" };

		for (auto n : str)
		{
			if (n != c) buff += n; else
				if (n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		inFile.close();


		char a = '}';
		buff = "";

		for (auto n : v[4])
		{
			if (n != a) buff += n; else
				if (n == a && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		std::cout << "\n\n" << v[5];

		attach(result);
		USDto.hide();
		CANto.hide();
		INRto.hide();
		EURto.hide();
		CNYto.hide();
		detach(From);
		result.put("   1 " + from + " = " + v[5] + " CAD");
	}
	else {
		system("start \"\" cmd /c \"echo Check Internet Connection!&echo(&pause\"");
	}
}

void Conversion::usdto_button(Address, Address pw)
{
	reference_to<Conversion>(pw).usdto();
}


void Conversion::usdto()
{
	bool bConnect = InternetCheckConnection(L"http://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0);

	if (bConnect)
	{
		std::string url = "\"http://api.fixer.io/latest?base=";
		url.append(from);
		url.append("&symbols=");
		url.append(from);
		url.append(",USD\"");

		system(("curl " + url + " > to_USD.txt").c_str());
		std::ifstream inFile;
		std::string str;
		inFile.open("to_USD.txt");

		while (!inFile.eof())
		{
			getline(inFile, str); // Saves the line in STRING.
		}
		std::vector<std::string> v;
		char c = ':';

		std::string buff{ "" };

		for (auto n : str)
		{
			if (n != c) buff += n; else
				if (n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		inFile.close();


		char a = '}';
		buff = "";

		for (auto n : v[4])
		{
			if (n != a) buff += n; else
				if (n == a && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		std::cout << "\n\n" << v[5];

		attach(result);
		USDto.hide();
		CANto.hide();
		INRto.hide();
		EURto.hide();
		CNYto.hide();
		detach(From);
		result.put("   1 " + from + " = " + v[5] + " USD");
	}
	else {
		system("start \"\" cmd /c \"echo Check Internet Connection!&echo(&pause\"");
	}
}


void Conversion::reset_button(Address, Address pw)
{
	reference_to<Conversion>(pw).button_reset();
}

int Conversion::button_reset()
{
	Conversion win(Point(100, 100), 600, 400, "Currency Conversion");
	hide();
	return gui_main();
}

void Conversion::inrto_button(Address, Address pw)
{
	reference_to<Conversion>(pw).inrto();
}

void Conversion::inrto()
{
	bool bConnect = InternetCheckConnection(L"http://www.google.com", FLAG_ICC_FORCE_CONNECTION, 0);

	if (bConnect)
	{
		std::cout << "Working\n";
		std::string url = "\"http://api.fixer.io/latest?base=";
		url.append(from);
		url.append("&symbols=");
		url.append(from);
		url.append(",INR\"");

		system(("curl " + url + " > to_INR.txt").c_str());
		std::ifstream inFile;
		std::string str;
		inFile.open("to_INR.txt");

		while (!inFile.eof())
		{
			getline(inFile, str); // Saves the line in STRING.
		}
		std::vector<std::string> v;
		char c = ':';

		std::string buff{ "" };

		for (auto n : str)
		{
			if (n != c) buff += n; else
				if (n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		inFile.close();


		char a = '}';
		buff = "";

		for (auto n : v[4])
		{
			if (n != a) buff += n; else
				if (n == a && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "")
			v.push_back(buff);

		std::cout << "\n\n" << v[5];

		attach(result);
		USDto.hide();
		CANto.hide();
		INRto.hide();
		EURto.hide();
		CNYto.hide();
		detach(From);
		result.put("   1 " + from + " = " + v[5] + " INR");
	}
	else {
		system("start \"\" cmd /c \"echo Check Internet Connection!&echo(&pause\"");
	}
}
	


void Conversion::cny_button(Address, Address pw)
{
	reference_to<Conversion>(pw).button_cny();
}

void Conversion::button_cny()
{
	from = "CNY";
	onFromClick();
}

void Conversion::eur_button(Address, Address pw)
{
	reference_to<Conversion>(pw).button_eur();
}

void Conversion::button_eur()
{
	from = "EUR";
	onFromClick();
}

void Conversion::inr_button(Address, Address pw)
{
	reference_to<Conversion>(pw).button_inr();
}

void Conversion::button_inr()
{
	from = "INR";
	onFromClick();
}

void Conversion::can_button(Address, Address pw)
{
	reference_to<Conversion>(pw).button_can();
}

void Conversion::button_can()
{
	from = "CAD";
	onFromClick();
}

void Conversion::usd_button(Address, Address pw)
{
	reference_to<Conversion>(pw).button_usd();
}

void Conversion::button_usd()
{
	from = "USD";
	onFromClick();
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
	TITLE.set_color(Color::dark_blue);
	TITLE.set_font_size(30);
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
	system("System_Requirements.txt");
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