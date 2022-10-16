//============================================================================
// Name        : Question5.cpp
// Author      : Mostafa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/*
5- Create a class for email address book. Your class should have the following
   - An array of strings containing email followed by the person name, an integer number to tell
     how many emails are stored so far. (private)
   - gets and sets methods for email and name for each entry. Print_all method to list all entry
     values (public) a constructor method to initialize the size used so far to zero
*/

class email_Book
{
private:
	string *emails;
	string *names;
	int bookSize;
	int MAX_SIZE;

public:
	email_Book(int MAX_SIZE = 100)
	{
		this->MAX_SIZE = MAX_SIZE;
		emails = new string[MAX_SIZE];
		names = new string[MAX_SIZE];
		bookSize = 0;
	}

	void set_email_name(string name, string email, int index)
	{
		names[index] = name;
		emails[index] = email;
		bookSize++;
	}

	string getEmail(int index)
	{
		return emails[index];
	}

	string getName(int index)
	{
		return names[index];
	}

	void PrintAll()
	{
		for (int i = 0; i < bookSize; i++)
		{
			cout<< "Name: "<< names[i] << "   Email: "<< emails[i]  << endl;
		}
	}

	~email_Book()
	{
		delete[] emails;
		delete[] names;
	}

};


int main()
{

	email_Book b1;

	b1.set_email_name("name_1", "email_1", 0);

	b1.set_email_name("name_2", "email_2", 1);

	b1.PrintAll();

	return 0;
}
