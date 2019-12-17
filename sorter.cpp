#include "sorter.h"

Sorter::Sorter(int n, int base):num_elements(n), rbase(base){
	srand(time(NULL));
	this->conf = create_config();
	this->print();
}

vector<int>* Sorter::create_config(){
	vector<int>* vals = new vector<int>;
	for(int i = 0; i<num_elements; i++){
		vals->push_back(rand()%rbase);
	}
	return vals;
}

bool Sorter::isValid(){
	int sval = this->conf->at(0);
	for(int i = 1; i<num_elements; i++){
		int cval = this->conf->at(i);
		if(cval < sval){
			return 0;
		}else{
			sval = cval; 
		}
	}
	return 1;
}

void Sorter::randomize(){
  	//random_shuffle(this->conf->begin(), this->conf->end());
	
	int sz = this->conf->size();
	vector<int> nind;
	for(int i = 0; i<sz; i++){
		int gen;
		do{
			gen = rand() % sz;
		}
		while(find(nind.begin(), nind.end(), gen) != nind.end());
		nind.push_back(gen);
	}
	for(int i = 0; i<nind.size(); i++){
		int tmp = this->conf->at(i);
		this->conf->at(i) = this->conf->at(nind[i]);
		this->conf->at(nind[i]) = tmp;
		nind.erase(remove(nind.begin(), nind.end(), nind[i]), nind.end());
	}
		
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
	unsigned long count = 1;
	time_t start;
	time(&start);
	while(!this->isValid()){
		this->randomize();
		//random_shuffle(this->conf->begin(), this->conf->end());
		cout<<count<<": ";
		this->print();
		count++;
	}
	time_t end;
	time(&end);
	time_t taken = difftime(end,start);
	struct tm* inf = localtime(&taken);
	cout<<"Ideal configuration reached in "<<endl; //taken<<"s : through "<<count<<" cycles"<<endl;
	char buf[80];
	strftime(buf,80,"%T.", inf);
	puts(buf);
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

