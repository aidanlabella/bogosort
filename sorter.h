#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <stack>

using namespace std;

class Sorter{
	private:
		int num_elements, rbase;
		vector<int>* conf;
		vector<int>* create_config();
	public:
		Sorter(int, int);
		bool isValid();
		void randomize();
		void bogo_sort();
  		void bubble_sort();
		void print();
};
