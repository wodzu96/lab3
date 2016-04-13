#include "Slav.h"
#include <fstream>

using namespace std;

vector <string> Slav::names;
int Slav::_counter = 0;
vector <Slav *> Slav::man, Slav::woman;
map <sex, vector <Slav *> > Slav::mapOfGenre;
void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
	mapOfGenre[male]=man;
	mapOfGenre[female]=woman;
}

Slav::Slav()
{
	/* jest to leniwa inicjalizacja, czyli wymuszenie inicjalizacji obiektu dopiero wtedy kiedy następuje pierwsze jego użycie */
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_id = _counter++;
	mapOfGenre[get_sex()].push_back(this);
	
}



string Slav::description()
{
	return string("  ") + _name + " [" + std::to_string(_id) + "]";
}
sex Slav::get_sex()
{
	return _name.back()=='a'?female:male;
}
