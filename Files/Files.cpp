#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:

	string name;
	string surname;
	int age;

public:

	Student() = default;
	Student(const char* n, const char* srn, int a)
	{
		name = n;
		surname = srn;
		age = a;
	}
	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
	}
	void SaveFile()
	{
		ofstream file("C:\\Users\\User\\Desktop\\Student.txt", ios::out | ios::app);
		if (file.is_open())
		{
			file << name << endl;
			file << surname << endl;
			file << age << endl;
			file.close();
		}
		else
		{
			cout << "ERROR!!! Failed to open file for WRITING!" << endl;
		}
	}
	void ReadFile()
	{
		ifstream file("C:\\Users\\User\\Desktop\\Student.txt", ios::in);
		if (file.is_open())
		{
			getline(file, name);
			getline(file, surname);
			file >> age;
			file.close();
		}
		else
		{
			cout << "ERROR!!! Failed to open file for READING!" << endl;
		}
	}
};

int main()
{
	Student student1("Artur", "K", 16);
	student1.SaveFile();

	Student student2;
	student2.ReadFile();
	student2.Print();



	/*char str[100];
	cout << "Input text: \n";
	cin.getline(str, 100);
	cout << str << endl;

	ofstream write("MyFile.txt");
	write << str << endl;
	write.close();

	ifstream read("MyFile.txt");
	char buff[10];
	while (read.eof() != 0 )
	{
		read >> buff;
		cout << buff;
	}
	
	read.close();*/

}