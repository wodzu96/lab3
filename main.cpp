// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <stack>	// Stos
#include <queue>	// Kolejka

#include <stdio.h>
#include <stdlib.h>
#include "Slav.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	Slav *slavs = new Slav[n];
	for (int i = 0; i < n; ++i)
		printf("[%i] %s\n", i, slavs[i].name().c_str());
}