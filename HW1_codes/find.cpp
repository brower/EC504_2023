#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
using namespace std;

/***********************************************************
Main progam template for find by bisecton and dictonaruy
************************************************************/
// Global Variable -- We will learn more eleganat ways later

int  OpCountBisection = 0;
int   OpCountDictionary = 0;

int findBisection(int key, int *a, int n);
int findDictionary(int key, int *a, int n);

int main(int argc, char *argv[]) 
{
  /* Timeing and IO setup */
  chrono::time_point<chrono::steady_clock> start, stop; 
  chrono::duration<double> difference_in_time;
  double difference_in_seconds_bisection; // Holds the final run time
  double difference_in_seconds_dictionary; // Holds the final run time
  ifstream infile;
  
  /* Local data */
  int n;
  int k;
  int find_index_dictionary = -1;
  int find_index_bisection = -1;
  int NoOfKeys = 10;
  int *key = new int[NoOfKeys];
  
  // Input Data:  DO NOT CHANGE 
  infile.open(argv[1]);
  if(!infile){
    cout << "Error opening file " <<endl;
    return -1;
  }
  
  infile >> n;
  int *A = new int[n];

  for(int i=0; i<n ; i++)
    infile >> A[i];
  infile.close();
  
  /* Select Set of Keys */
  for( k = 0; k < NoOfKeys; k++)
    {
      key[k] = A[rand()%n];
    }

  // Try NoOfkeys 
  
  for( k = 0; k < NoOfKeys; k++)
    {
      
  /* Find Key by Bisection  Search  */

  start = chrono::steady_clock::now();
  find_index_bisection = findBisection(key[k], A,  n);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_seconds_bisection = double(difference_in_time.count());
  
  
  /* Find Key by Dictionary Search  */
  start = chrono::steady_clock::now();
  find_index_dictionary = findDictionary(key[k], A, n);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_seconds_dictionary = double(difference_in_time.count());
; 
  
  // Begin output  
  
  // ofstream outfile(strcat(argv[1],"_out"));

  /* Check against Key by Bisection  */
  cout << "Bisection " << find_index_bisection << " vs Dictionary " <<  find_index_dictionary << endl;
  if(find_index_dictionary !=-1)
    {
      cout << "Value found = "<<A[find_index_dictionary] << " for  key = " <<  key[0]<< endl;
    }
  cout << "Bisection: Time =  " <<  difference_in_seconds_bisection << " OpCount = "  << OpCountBisection <<  endl;
  cout << "Dictionary: Time =  " <<  difference_in_seconds_dictionary << " OpCount =  "  << OpCountDictionary << endl;
  
 //End output 
    }

#if 0   // For extra credit find each input file or even plot as fuction of size
  cout << "\n For = " << NoOfKeys << "keys: Mean values are " << endl;

  cout << "Bisection: Mean Time =  " <<  difference_in_seconds_bisection << " Mean OpCount = "  << OpCountBisection <<  endl;
  cout << "Dictionary: Mean Time =  " <<  difference_in_seconds_dictionary << "Mean  OpCount =  "  << OpCountDictionary << endl;

 #endif
  
  return 0;
}




/****************************************
Provide funtions below
****************************************/

int findBisection(int key, int *a, int N)
{
  int index = -1;
  // while(??) {
  OpCountBisection++;  // counts the number of call to routine
   //}
  
  return index;
}

int findDictionary(int key, int *a, int N)
{
  int index = -1;
  // while(??) {
      OpCountDictionary++;  // counts the number of call to routine
      //}
  return index;
}



