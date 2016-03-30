#pragma once
#include <string>
#include <vector>

using namespace std;

class Slav
{
private:
	static void init();
	static std::vector <string> names;
	string _name;
public:
	Slav();
	string name();
};