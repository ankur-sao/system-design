#include<iostream>
#include<fstream>

using  namespace std;

class Filecloser
{
	public:
	Filecloser(fstream *file)
	{
		_file = file;
	}
	~Filecloser()
	{
		_file->close();
		delete _file;
	}
    private:
	    fstream *_file;
};

void exceptionRoutine()
{
	cout<<"throwing exception";
}

void  loadFromFile(fstream &file)
{
	cout<<"loading from file..."<<endl;
}

class MyFile;

 void loadFromFile(MyFile &file)
{
	cout<<"loading from file..."<<endl;
}

class MyFile
{
	public:
		MyFile(){}
		~MyFile()
		{
			if(_file.is_open())
			{
				_file.close();
			}
		}

		void open(const string fileName)
		{
			_file.open(fileName);
		}

		bool isOpen()
		{
			return  _file.is_open();
		}


	private:
		fstream _file;

};

class OpenFile
{
	public:
		OpenFile(const string  filename)
		{
			file.open(filename);
		}

		~OpenFile()
		{
			if (file.is_open())
			file.close();
		}

	private:
		fstream file;
}
int main()
{
	{

		fstream file;
		file.open("../mysql");
		Filecloser closer(&file);

		exceptionRoutine();
		loadFromFile(file);

		file.close();
	}
	{
		MyFile file;
		file.open("../mysql");

		loadFromFile(file);

	}

	{
		OpenFile file("../mysql");
		exceptionRoutine();
	}
   return 0;
}

