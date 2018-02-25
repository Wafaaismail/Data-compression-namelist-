// namelsit.cpp : Defines the entry point for the console application.
//
/*
	butterfly team
	wafaa ismail 
	sec 2

*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

#define  s 8  
#define  m 4


int counter0 = 0; // num of 0
char value ; //value to encode
int coun1 = 0; //num of 1
int flag = 0; //detect 1 cases

bitset<s> to_binary(char c) //convert input char to 8 bit ascii
{
	bitset<s> b1(c);

	return b1;

}

bitset<m> dectobinary(int count) // covert num of zeros or ones to 4 bit  to make it encoded 
{ 
	bitset<m> b(count);
	return b;
}
fstream e;
void Display(int n)  //write compressed text at final file 
{ 
	if (!e.is_open())
	{
		e.open("compresed.txt", ios::app);
	}

	e << dectobinary(n);
	e.close();
}

void counterCheck() //check counter of 0 , 1 to make a desion according to algorithm
{
	while (counter0 % 15 != 0) // check 0 conter cases 
	{
		Display(counter0);
		counter0 = counter0 - 15;
		if (counter0 < 0) 
			break;
	}
	if (coun1 >= 2) // work to print 0000 if 11
	{
		Display(0);
	}

}
double op = 0;
void Encoding() //comprission 
{
	bool toggle = false; // flag to indicate 1 positions 
	fstream f1;
	f1.open("binary.txt", ios::in);  //open 8 bit file 
	if (!f1.is_open())
	{
		cout << "the problem binary file at Encoding! " << endl;
	}
	
	while (!f1.eof()) //Do until file binary is end
	{
		value = f1.get(); // read char by char from binary file 
		op += 1;
		//cout << value;
		if (value =='0')   // value Read is 0
		{
			if (toggle == false && flag >= 1) // use to toggle if the last value is 1 
			{
				counterCheck();

			}
			toggle = true;
			coun1 = 0;
			++counter0; 
			flag++;
		}
		else             //value  read is 1
		{
			if (toggle == true) //if the last value is 0
			{

				counterCheck();
			}
			toggle = false;
			counter0 = 0;
			if (flag == 0 && coun1 == 0) //check to cover 11 n condition
			{
				counterCheck();
				++coun1;
			}
			else
			{
				++coun1; // inc num of 1 
			}

		}
	}
	if (value +1 == 0) //check if the last value is 1 
			Display(0);

	f1.close(); //close file
}
double ip = 0;
void read_file()  //read name list file as input 
{
	char my_char;
	fstream fin;
	fstream fout;
	fout.open("binary.txt", ios::out);  //open binary file to save valuse of 8 bit ascii
	if (!fout.is_open())
	{
		cout << " the problem is at binary file !  " << endl;
	}
	fin.open("namelist.txt", ios::in); // open file input 
	if (!fin.is_open())
	{
		cout << " the problem is at name list file !  " << endl;
	}


	while (fin.get(my_char)) //read values 
	{ 
		ip += 8;
		if (my_char == ' '||my_char =='\n') continue; //escape spaces and end of line 
		cout << "wait until finish coverting ..." << endl;
		fout << to_binary(my_char);           //save 8 bit at binary 
		//cout << to_binary(my_char) << endl; //to consol 

	}
	
	fin.close(); //close file name list 
	fout.close(); //close binary 
}



int main()
{ 
	read_file();
	Encoding();
	cout << "the Ratio is " << op/ip<<endl; //print the comprission ratio
	while (true)
	{
		//open console for any warning 
	}

	return 0;
}
