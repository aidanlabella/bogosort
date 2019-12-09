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
	sorter.print();
	time_t start = time(NULL);
	while(!sorter.isValid()){
		sorter.randomize();
		sorter.print();
	}
	time_t taken = time(NULL) - start;
	int min = taken/60;
	int sec = taken%60;
	cout<<"Ideal configuration reached in "<<min<<"m "<<sec<<"s : "<<endl;
	sorter.print();
	return 0;
}
