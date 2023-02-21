#include<iostream>
#include<iomanip>
#include <fstream>
#include <cstdlib> 
#include <time.h>
#include <math.h>
#include <new>
#include "sorting.h"
using namespace std;

#define StandIO 1

// Debugging routine: (Good Software would put this in seperate test.h)
void printArray(int a[], int N)
{ 
  cout << "N =" << N << endl;
  for(int i = 0;i<N;i++) cout << a[i] << "\n";
}

int main()
{ 
  int N; // size of array
  int n_power  = 12;  // power of 2 for size. 
  int Ncases = 8;  // run over a set of re_ordering lists
  int *a, *a_save, *a_tmp;
  ofstream myData;

  // Here is how  you allocate a file and write to it in C++.
  myData.open ("PlotData.txt");
  myData << "\n # Data File to collect swap count and there averages and errors for plotting \n";
  myData << "# N  Insertion   Mean  Error  |    Merge  Mean  Error |   Quick   Mean  Error |   Shell Sort  Mean  Error | \n ";
  
  srand(137); // fixes intial seed 
  // Put loop around N to make data for scaling

  
  for(int n = 0; n < n_power; n++) //loop over sizes = N for arrays
    {
      N = 16*pow(2,n);  // note cast to int N
      // allocate arrays    
      a  = (int*)malloc(N * sizeof(int));
      a_save  = (int*)malloc(N * sizeof(int));
      a_tmp  = (int*)malloc(N * sizeof(int));
      
      for(int i = 0;i< N;i++) 
	a[i] = (rand() +1)%1000000 ;  // set up a random array
      
      cout <<"Evaluate Scaling of Sorting Algorithms N = "<< N << endl;
   
      
      //  Can average over re-permuation of array of size N	 
      for(int j = 0; j < Ncases; j++)
	{
	  for(int i = 0;i<N;i++) a_save[i] = a[i]; // keep random array
	  
	  //Test insertionSort     
	  swapCount = 0;
	  insertionsort(a, N); 
#if StandIO
	  cout << "Case = " << j << "  insertionSort swapCount " << swapCount << endl;
#endif
	  
	  //Test mergeSort
	  swapCount = 0;
	  for(int i = 0;i<N;i++) a[i] = a_save[i];
	  mergeSort(a,  a_tmp, 0, N-1);
	  
#if StandIO
	  cout << "Case = " << j << " Merge  swapCount " << swapCount << endl;
#endif  
	  //Test quickSort
	  swapCount = 0;
	  for(int i = 0;i<N;i++) a[i] = a_save[i];
	  quicksort(a, 0,N-1);
#if StandIO
	  
	  cout << "Case = " << j << " Quick  swapCount " << swapCount << endl;
#endif	  
	  //Test shellSort
	  swapCount = 0;
	  for(int i = 0;i<N;i++) a[i] = a_save[i];
	  shellsort(a,N);
	  
#if StandIO
	  cout << "Case = " << j << " Shell Sort  swapCount " << swapCount << endl;
#endif	  
	  
	  //	  Get new permutation of random array.
	  for(int i = 0;i<N;i++) a[i] = a_save[i];
	  initialize_and_permute(a , N);
	  
	} // end cases
      
      free(a);
      free(a_save);
      free(a_tmp);
      
    } // end array sizes N 
  
  myData.close();
  
  return 0;
}
