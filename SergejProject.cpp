#include <iostream>
#include "Raid.h"

using namespace std;

int main() {
	Raid<double> arr, arr1(2,5);//arr = [], arr1 = [2, 2, 2, 2, 2]
	arr1.display();
	double m = 1.4;
	for (int i = 0; i < 10; i++)
		arr.push_back(m);
	arr.display();
	arr.pop_back();
	arr.display();
}