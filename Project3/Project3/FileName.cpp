#include<iostream>
using namespace std;
int main()
{
	int a = 29;

	int* ptr = &a;

	int** ptr1 = &ptr;
	
	cout << **ptr1;






	return 0;
}