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
	unsigned long count = 1;
	while(!sorter.isValid()){
		sorter.randomize();
		cout<<count<<": ";
		sorter.print();
		count++;
	}
	time_t taken = time(NULL) - start;
	int min = taken/60;
	int sec = taken%60;
	cout<<"Ideal configuration reached in "<<min<<"m "<<sec<<"s : through "<<count<<" cycles"<<endl;
	sorter.print();
	int speed_avg = count/taken;
	cout<<"Average processing speed was "<<speed_avg<<" per second."<<endl;
	return 0;
}
