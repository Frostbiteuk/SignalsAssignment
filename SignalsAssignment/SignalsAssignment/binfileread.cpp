// Function binfileread
// A function that reads in a binary data file
//
// Inputs: pointer to a char
// Outputs: none
//
// Dr D I Armour - Chelu / February 2009
// Modifed for Virtual Week / February 2012
#include "unlimited.h"

DoubleArrayPtr dmemblock;
bool dmemallocated;

void binfileread(char * binfile)
{

	ifstream binarray(binfile, ios::in|ios::binary|ios::ate);
	
	if(binarray.is_open())
	{
		int filesize = binarray.tellg();
		int numberofvalues = filesize / sizeof(double);
		cout << "Binary File size is: " << filesize << endl;
		cout << "The number of values from the binary file is: " << numberofvalues << endl;
		
		dmemblock = new double [filesize];
		dmemallocated = true;
		binarray.seekg (0, ios::beg);
		binarray.read(reinterpret_cast<char *>(dmemblock), filesize);
		
		// You may wish to uncomment the next four lines of code to see the data, 
		// but it will scroll for some time on screen
		for(int i = 0; i < numberofvalues; i++)
		{
			cout << "Sample " << i << ": " << dmemblock[i] << endl;
		}
		
		binarray.close();
		cout << "The complete binary file content is in memory" << endl;
		cout << endl;

	// For billbryson.bin, Fs = 8kHz and a 'dit' is about 75ms in duration
	// A'dah' will be three times longer than a 'dit'
	// Choosing a 10ms window (80 samples) should give enough resolution
	//
	// ... Add your Code here ..... 
	//
	// And if you need to call moments(), here's where ....
	//  moments(dmemblock, numberofvalues);

	}
	else
	{
		cout << "Unable to open file";
	}

	if(dmemallocated)
	{
		free(dmemblock);
	}
	
} // End of binarrayread()