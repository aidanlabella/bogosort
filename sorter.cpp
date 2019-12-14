#include "sorter.h"

Sorter::Sorter(int n):num_elements(n){
	srand(time(NULL));
	this->conf = create_config();
	this->print();
}

vector<int>* Sorter::create_config(){
	vector<int>* vals = new vector<int>;
	for(int i = 0; i<num_elements; i++){
		vals->push_back(rand()%1000);
	}
	return vals;
}

bool Sorter::isValid(){
	int sval = this->conf->at(0);
	for(int i = 1; i<num_elements; i++){
		if(this->conf->at(i) < sval){
			return 0;
		}else{
			sval = this->conf->at(i);
		}
	}
	return 1;
}

void Sorter::randomize(){
	random_shuffle(this->conf->begin(), this->conf->end());
}

void Sorter::print(){
	cout<<"[";
	for(int i = 0; i<num_elements; i++){
		cout<<this->conf->at(i);
		if(i+1 != num_elements)
			cout<<", ";
	}
	cout<<"]\n";
}

void Sorter::bogo_sort(){
	time_t start = time(NULL);
	unsigned long count = 1;
	while(!this->isValid()){
		this->randomize();
		cout<<count<<": ";
		this->print();
		count++;
	}
	time_t taken = time(NULL) - start;
	int min = taken/60;
	int sec = taken%60;
	cout<<"Ideal configuration reached in "<<min<<"m "<<sec<<"s : through "<<count<<" cycles"<<endl;
	this->print();
	if(taken != 0){
		int speed_avg = count/(int)taken;
		cout<<"Average processing speed was "<<speed_avg<<" per second."<<endl;
	}
}

void Sorter::bubble_sort(){
	time_t start = time(NULL);
	unsigned long count = 1;
	while(!this->isValid()){
		for(int i = 0; i<num_elements-1; i++){
			if(conf->at(i) > conf->at(i+1)){
				iter_swap(conf->begin() + i, conf->begin() + 1 + i);
			}
		}
		cout<<count<<": ";
		this->print();
		count++;
	}
	time_t taken = time(NULL) - start;
	int min = taken/60;
	int sec = taken%60;
	cout<<"Ideal configuration reached in "<<min<<"m "<<sec<<"s : through "<<count<<" cycles"<<endl;
	this->print();
	if(taken != 0){
		int speed_avg = count/(int)taken;
		cout<<"Average processing speed was "<<speed_avg<<" per second."<<endl;
	}
}

