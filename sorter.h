#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

class Sorter{
	private:
		int num_elements;
		vector<int>* conf;
		vector<int>* create_config();
	public:
		Sorter(int);
		bool isValid();
		void randomize();
		void print();
};
