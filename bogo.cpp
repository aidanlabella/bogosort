#include <ctime>
#include <cstdio>
#include <iostream>
#include <string>

#include "sorter.h"

using namespace std;

int main(int c, char** argc){
	cout<<"sorter(.exe)"<<endl;
	int num = atoi(argc[1]);
	cout<<"Generating and sorting "<<num<<" elements"<<endl;
	Sorter sorter(num);
	sorter.bogo_sort();
	cout<<"\n\n\n"<<endl;
	cout<<"Beginning bubble sort: \n";
	sorter.bubble_sort();
	return 0;
}
