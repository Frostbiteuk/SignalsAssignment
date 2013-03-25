// Function stringfileread
// A function that reads in a text data file
//
// Inputs: pointer to a char
// Outputs: none
//
// Dr D I Armour - Chelu / February 2009
#include "unlimited.h"

CharArrayPtr cmemblock;
bool cmemallocated;

void stringfileread(char *stringfile)
{

	ifstream textarray(stringfile, ios::in|ios::ate);

	if(textarray.is_open())
	{
		int filesize = textarray.tellg();
		cout << "Text File size is: " << filesize << endl;
		int numberofvalues = filesize / sizeof(char);
		cout << "The number of values from the text file is: " << numberofvalues << endl;

		cmemblock = new char [filesize];
		cmemallocated = true;
		textarray.seekg (0, ios::beg);
		textarray.read(cmemblock, filesize);

		for(int i = 0; i < numberofvalues ; i++)
		{
			cout << cmemblock[i];
		}
		
		textarray.close();
		cout << endl;
		cout << "The complete text file content is in memory" << endl;
		cout << endl;

	// For billbryson.txt, Fs = 8kHz and a 'dit' is about 75ms in duration
	// A'dah' will be three times longer than a 'dit'
	// Choosing a 10ms window (80 samples) should give enough resolution
	//
	// ... Add your Code here .....
	//

	}
	else
	{
		cout << "Unable to open file";
	}

	if(cmemallocated)
	{
		free(cmemblock);
	}

}  // End of stringfileread()