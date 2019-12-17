#include <ctime>
#include <cstdio>
#include <iostream>
#include <string>

#include "sorter.h"

using namespace std;

int main(int c, char** argc){
	cout<<"sorter(.exe)"<<endl;
	int num = atoi(argc[1]);
	int base = atoi(argc[2]);
	cout<<"Generating and sorting "<<num<<" elements"<<endl;
	Sorter sorter(num, base);
	sorter.bogo_sort();
	cout<<"\n\n\n"<<endl;
	for(int i = 0; i<20; i++)
		sorter.randomize();
	cout<<"Beginning bubble sort: \n";
	sorter.bubble_sort();
	return 0;
}
