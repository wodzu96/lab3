// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos
#include <algorithm>
#include <iostream>
#include <stdio.h>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];

	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);

	printf("## male test \n");
	for (vector <Slav *>::iterator i =	slavs[0].mapOfGenre[male].begin(); i != slavs[0].mapOfGenre[male].end(); i++)
		cout << (*i)->description()<<endl;

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	
	// Umieść Słowian w losowej kolejności w wektorze.
	for(int i = 0; i<n; ++i)
		vectorOfSlavs.push_back(slavs+i);
	random_shuffle(vectorOfSlavs.begin(), vectorOfSlavs.end());
	for (vector <Slav *>::iterator i = vectorOfSlavs.begin(); i != vectorOfSlavs.end(); i++)
		cout << (*i)->description()<<endl;
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze

	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for (vector <Slav *>::iterator i = vectorOfSlavs.end()-1; i != vectorOfSlavs.begin()-1; --i){
	setOfSlavs.insert(*i);
	vectorOfSlavs.pop_back();
	
}
	
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	set<Slav*>::iterator i = setOfSlavs.begin();
	while(!setOfSlavs.empty()){
		mapOfSlavs[*i]=*(i = setOfSlavs.erase(i));
		i = setOfSlavs.erase(i);
	}
	for (std::map<Slav *, Slav *>::iterator i = mapOfSlavs.begin(); i != mapOfSlavs.end(); i++)
		cout << (*i).first->description() << (*i).second->description() << endl;
	
	REPORT_CONTAINERS;
	

}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	for(int i = 0; i<n; ++i)
		queueOfSlavs.push(slavs+i);
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.
	while(!queueOfSlavs.empty()){
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
	}

	REPORT_ADAPTERS;
	

	// Wyświetl Słowian zdejmowanych ze stosu.
	while(!stackOfSlavs.empty()){
		cout<<stackOfSlavs.top()->description()<<endl;
		stackOfSlavs.pop();}

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
