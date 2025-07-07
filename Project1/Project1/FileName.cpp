#include<iostream>
#include<fstream>
using namespace std;
int main()
{


	ifstream read("hello.txt");

	if (!read)
	{
		cout << "Error in opening file "<<endl;
		return 1;
	}

	char word[70];

	while (read.getline(word,70))
	{
		cout << word<<endl;
		break;
	}

	read.close();

}