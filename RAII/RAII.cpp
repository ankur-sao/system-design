#include<iostream>
#include<vector>
#include<fstream>
#include<mutex>

using namespace std;

void  routineCausingException()
{
	cout << "raised mock  exception, now who will"
	      << "close the opened file" << endl;
}

class Dog
{
    string name;
    string owner;
};

int main()
{
	{
		fstream File;
		File.open("../mysql");

		while (File) 
		{
			string line;
			getline(File, line);

			cout<<line<<endl; 
		}

		routineCausingException();

		File.close();
	}

	{
		Dog *dog =  new Dog(); //heap allocation
		routineCausingException();
		delete dog;
	}

	{
		mutex foo,bar;
		lock(foo,bar);
		routineCausingException();

		foo.unlock();
		bar.unlock();

	}

	return 0;

}



