// Function moments
// A function that applies some statistical moments on a data array
//
// Inputs: pointer to a structure of different data types and sizes
// Outputs: none
//
// Adapted from the moment function given by
// "Numerical Recipes in C" (second edition)
// by W.H.Press, S.A.Teukolsky, W.T.Vettering, B.P.Flannery
//
// Dr D I Armour - Chelu / February 2009

#include"unlimited.h"

void moments(double datablock[], int arraysize)
{

  int j, k;
  double sum = 0.0, abstotal = 0.0, p =0.0, mean = 0.0,
    avedev = 0.0, skewness = 0.0,kurtosis = 0.0, epsilon = 0.0,
    variance = 0.0, stdev = 0.0;

  // First time around the get the mean value
  for(j = 4 ; j < arraysize ; j++)
  {
	sum += datablock[j];
  }

  mean = sum / arraysize;
  cout << "The sum of the data is %f and the mean value is: " <<
	 sum << mean << endl;

  // Second time around to get the first (absolute), second, third, and
  // fourth moments of the deviation from the mean
  for(k = 4 ; k < arraysize ; k++)
  {
	avedev = fabs(abstotal = datablock[k] - mean);
	epsilon += abstotal;
	variance += (p = abstotal * abstotal);
	skewness += (p *= abstotal);
    kurtosis += (p *= abstotal);
  }

  // Corrected two-pass formula for variance and then put the pieces
  // together according to the conventional definitions
  avedev /= arraysize;
  variance = (variance - epsilon * epsilon / arraysize) / (arraysize);
  stdev = sqrt(variance);

  if(variance > 0)
  {
	skewness /= (arraysize * (variance) * (stdev));
	kurtosis = (kurtosis / (arraysize * variance * variance)) - 3.0;
  }
  else
  {
	cout << "No skewness / kurtosis when variance = 0 (in moment)" << endl;
  }

  cout << "The average deviation is: " << avedev << endl;
  cout << "The standard deviation is: " << stdev << endl;
  cout << "The skewness is: " << skewness << endl;
  cout << "The kurtosis value is: " << kurtosis << endl;

} // End of moments()