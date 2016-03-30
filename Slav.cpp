#include "Slav.h"
#include <fstream>

using namespace std;

vector <string> Slav::names;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
         istream_iterator<string>(),
         back_inserter(names));
	file.close();
}

Slav::Slav()
{
	static int ret = (init(), 1);	// Leniwa inicjalizacja
	_name = names[rand() % names.size()];
}

string Slav::name()
{
	return _name;
}