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
