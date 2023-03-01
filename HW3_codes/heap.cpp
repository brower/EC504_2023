#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
#include "sorting.h"
using namespace std;


/***********************************************************
Main progam template build a Max Heap and Heap Sort in place
************************************************************/

static int OpCount = 0;

int localSize = 100;

void Heapify(int *Heap, int n);
void CheckHeapOrder(int *Heap,int n);
int  DeleteHeap(int index,int *Heap,int ntemp);
void InsertHeap(int value ,int *Heap, int ntemp);
void HeapSort(int *Heap, int n);
 
int main(int argc, char *argv[]) 
{
  /* Timeing and IO setup */
  chrono::time_point<chrono::steady_clock> start, stop; 
  chrono::duration<double> difference_in_time;
  double difference_in_seconds_heap_sort;  // Holds the final run time
  ifstream infile;
  ofstream outfile;
  
  /* Local data */
  int n;
 
  
  // Input Data:  DO NOT CHANGE 
  infile.open(argv[1]);

  int* Heap = NULL;
  
  if(!infile)
    {
      cout << "No input files so genearated internal random file of size = "<<  localSize  << endl;
      n = localSize;
      cout << "n  = " << n << endl;
      Heap = new int[n+1];
      Heap[0] = n;  // Set zero entry in in heap to n
      for(int i=1; i<n+1 ; i++)  Heap[i] = rand()%100000;
      // Define out put file
       outfile.open("SortedRandomList.dat");
    }
  else
    {
      infile >> n;
      Heap = new int[n+1];
      Heap[0] = n;  // Set zero entry in in heap to n	    
      for(int i=1; i<n+1 ; i++) infile >> Heap[i];
      infile.close();
      // Define out put file 
      outfile.open(strcat(argv[1],"_HeapSorted.dat"));
    }
  
  

   /* Set up Heat */
   
   Heapify(Heap, n);

   CheckHeapOrder(Heap,n);
   
     /* Practive delete and insert */
 
   int ntemp = n;
   int index = 0;
   int value = -1;

   /* 
 You might want to do a Merge Sort and compare to make sure you haven't lost anything and compare with the Merge Sort after Insert/Delete test!
 */
   
# if 1   
   // Try Deleting 5 
   for(int k = 0; k <5; k++)
     {
       index = rand()%n + 1;
       value = DeleteHeap(index,Heap,ntemp); // Also reHeapfies 
       Heap[ntemp] = value;
       ntemp--;
     }
   //Reinsert 5       
   for(int k = 0; k <5; k++)
     {
       value = Heap[ntemp +1];
       InsertHeap(value,Heap, ntemp); // Also reHeapfies
       ntemp++;
     }
      CheckHeapOrder(Heap,n); // Is it still a  Heap?
#endif
      
/* 
 Test and compare  efficiency of Heap Sort  relative to Merge Sort
 */
      
  int* a_tmp = new int[n+1];      
      
  OpCount = 0;
  start = chrono::steady_clock::now();
   mergeSort(Heap, a_tmp,  1, n);
   // REPLACE WITH HEAP SORT //
   // HeapSort(Heap, n);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_seconds_heap_sort = double(difference_in_time.count());
  
  //Begin output file : DO NOT CHANGE  
 
  outfile << Heap[0] << endl;
  for(int i=1; i< Heap[0]+1  ; i++)
    outfile << Heap[i] << endl;

  //End output file

  return 0;
}



/****************************************
Provide funtions below
****************************************/

 void Heapify(int *Heap, int n)
 {
 }

 void  CheckHeapOrder(int *Heap,int n)
  {

  }

int  DeleteHeap(int index,int *Heap,int ntemp)
{
  int save = Heap[index];

  return  save;
}
void InsertHeap(int value ,int *Heap, int ntemp)
{

}
void HeapSort(int *Heap, int n)
{

}
