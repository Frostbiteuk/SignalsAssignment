// main.cpp : Defines the entry point for the console application.
//
// A program to bring in binary data from a file and assign that data to an
// array for the purpose of program development.
//
// Usage: unlimited 'file'.txt 'file'.bin
//
// Developed for the Programming for Engineers 3 course (ANSI C)
// June 2001
//
// Adapted for the Programming for Engineers 4 course
// January 2005
//
// Further adapted for the Programming for Software Systems course in C++
// February 2007 / 2008
//
// Further adaption in C++ February 2009
// Additional adaptation for Virtual Week exercise February 2012
// Dr D I Armour-Chelu / School of Engineering
#include "unlimited.h"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{

		cout << "Usage: " << argv[0] << "<data file>" << endl;
		exit(0);

	}

	if(argc > 2)
	{
		cout << "Too many input parameters" << endl;
		cout << "Usage: " << argv[0] << " <textfile> <data file>" << endl;
		exit(0);
	}
	
	
	// argc[2] is for the binarray array
	binfileread(argv[1]);

	// argc[2] is for the chararray array
	//stringfileread(argv[1]);

	// Code to be added here

	return 0;

} // End of main()