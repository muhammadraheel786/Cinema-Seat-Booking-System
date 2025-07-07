#include<iostream>
using namespace std;

void swap(int& num1, int& num2)
{
	int temp=num1;
	num1 = num2;
	num2 = temp;

	
}



int main()
{
	int num1 = 0, num2 = 0;

	cout << "Enter your first number ";
	cin >> num1;

	cout << "Enter your first number ";
	cin >> num2;

	cout << "Before swap a= " << num1 << " b= " << num2 << endl;

	swap(num1, num2);

	cout << "After swap a= " << num1 << " b= " << num2;


	return 0;
}