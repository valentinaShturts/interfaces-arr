#include "interfaces.h"
#include <iostream>
using namespace std;


int main()
{
	const int size = 5;
	int a[size] = { 3,-9,0,55,3 };

	Array arr1(a, size);
	arr1.Show("Init array ");
	cout << endl;

	cout << "Max: " << arr1.Max() << endl;
	cout << "Min: " << arr1.Min() << endl;
	cout << "Avg: " << arr1.Avg() << endl;
	cout << "Search 0: " << arr1.Search(0) << endl;
	cout << endl;

	arr1.SortAsc();
	arr1.Show("SortAsc ");
	cout << endl;

	arr1.SortDesc();
	arr1.Show("SortDesc ");
	cout << endl;

	arr1.SortByParam(true);
	arr1.Show("SortByParam: SortAsc ");

}