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
  int Ntrials = 1;  // run over a set of re_ordering lists
  int *a, *a_save, *a_tmp;
  ofstream myData;
  double MeanInsert, MeanMerge, MeanQuick, MeanShell;
  double rmsInsert, rmsMerge, rmsQuick, rmsShell;
  double InvCases;
  
 
  // Here is how  you allocate a file and write to it in C++.

  FILE* cFile;
  cFile = fopen ("Plotfile.txt","w+");
 
  fprintf(cFile,"#                N               |     MeanInsert        rmsInsert     |      MeanMerge         rmsMerge     |     MeanQuck         rmsQuick      |     MeanShell        rmShell     |\n ");
   
  srand(137); // fixes intial seed 
  // Put loop around N to make data for scaling

   
  for(int n = 0; n < n_power; n++) //loop over sizes = N for arrays
    {
 
    MeanInsert = 0.0;  MeanMerge = 0.0; MeanQuick = 0; MeanShell = 0.0;
    rmsInsert = 0.0;  rmsMerge = 0.0;  rmsQuick = 0.0;  rmsShell = 0.0;
  
      N = 16*pow(2,n);  // note cast to int N
      // allocate arrays    
      a  = (int*)malloc(N * sizeof(int));
      a_save  = (int*)malloc(N * sizeof(int));
      a_tmp  = (int*)malloc(N * sizeof(int));
      
      for(int i = 0;i< N;i++) 
	a[i] = (rand() +1)%1000000 ;  // set up a random array
      
      cout <<"Evaluate Scaling of Sorting Algorithms N = "<< N << endl;
   
      
      //  Can average over re-permuation of array of size N

      
      InvCases  = 1.0/(double)Ntrials;
	 
      for(int j = 0; j < Ntrials; j++)
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

;
	  
	  //	  Get new permutation of random array.
	  for(int i = 0;i<N;i++) a[i] = a_save[i];
	  initialize_and_permute(a , N);
	  
	} // end cases
      
      rmsInsert  = sqrt(rmsInsert -  MeanInsert* MeanInsert);
      rmsMerge  = sqrt(rmsMerge -  MeanMerge* MeanMerge);
      rmsQuick  = sqrt(rmsQuick -  MeanQuick* MeanQuick);
      rmsShell  = sqrt(rmsShell -  MeanShell* MeanShell);
      
      
    fprintf(cFile,"%20.15d  %15.5e  %15.5e  %15.5e  %15.5e  %15.5e  %15.5e  %15.5e  %15.5e \n", N, MeanInsert,  rmsInsert, MeanMerge,  rmsMerge,  MeanQuick, rmsQuick,  MeanShell,  rmsShell );
       
      free(a);
      free(a_save);
      free(a_tmp);
      
    } // end array sizes N
  
  fclose(cFile);
  
  return 0;
}
