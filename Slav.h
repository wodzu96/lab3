#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
#include <iterator>
using namespace std;
enum sex  { male, female };
class Slav
{
private:
	static void init();

	static std::vector <string> names;
	static int _counter;
	static vector <Slav *> man, woman;
	string _name;
	int _id;

public:
	Slav();
	static map <sex, vector <Slav *> > mapOfGenre;
	static int counter() { return _counter; }
	
	string name() { return _name; }
	int id() { return _id; }

	string description();
	
	sex get_sex();
};
