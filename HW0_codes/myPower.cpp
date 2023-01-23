#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
#include <math.h>
using namespace std;

/***********************************************************
Main progam template for practice exercise HomeworkZero
************************************************************/

double slowPower(double x, long int N);
double fastPower(double x, long int N);
double cPower(double x, long int N);
double veryfastPower(double x, long int N);


int main() 
{
  //default values
  unsigned long int N; // Max 4,294,967,295
  double x =  1.000001;   // Max 1.79769e+308]
  // N   = 3141592653;
  N = 1;
  FILE * outfile;
  outfile = fopen("CompareTiming.txt", "w");

    fprintf(outfile,"# log10(N)                 cPower                         slowPower                       fastPower                veryfast Power \n");
  for(int digits = 1; digits < 8 ;digits++)
{
  N = 10*N;
     
  /* Timeing and IO setup */
  chrono::time_point<chrono::steady_clock> start, stop; 
  chrono::duration<double> difference_in_time;
  double difference_in_sec_slow; // Holds the final run time
  double difference_in_sec_fast; // Holds the final run time
  double difference_in_sec_c; // Holds the final run time
  double difference_in_sec_veryfast; // final run time  

 
  start = chrono::steady_clock::now();
  double power_c = cPower(x,N);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_sec_c= double(difference_in_time.count());
  
  start = chrono::steady_clock::now();
  double power_slow = slowPower(x,N);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_sec_slow= double(difference_in_time.count());
  
  start = chrono::steady_clock::now();
  double power_fast = fastPower(x,N);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_sec_fast= double(difference_in_time.count());

  start = chrono::steady_clock::now();
  double power_veryfast = veryfastPower(x,N);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_sec_veryfast= double(difference_in_time.count());
  
  cout << endl << " For N = " << N <<endl;
  cout << "powerC =    " << power_c   << "  Time = " <<  difference_in_sec_c << endl;
  cout << "powerSlow = " << power_slow <<"  Time = " <<  difference_in_sec_slow << endl;
  cout << "powerFast = " << power_fast <<"  Time = " <<  difference_in_sec_fast << endl;
  cout << "powerveryFast = " << power_veryfast <<"  Time = " <<  difference_in_sec_veryfast << endl;

 
  fprintf(outfile," %20d   %25.20e   %25.20e    %25.20e   %25.20e \n",digits, difference_in_sec_c,   difference_in_sec_slow,  difference_in_sec_fast, difference_in_sec_veryfast );

  // outfile <<  difference_in_sec_c <<"  "<<  difference_in_sec_slow <<"  "<< difference_in_sec_fast <<"  "<< difference_in_sec_veryfast << endl;
 }
  
  fprintf(outfile,"\n");
 fclose(outfile);
  
  return 0;
}

/****************************************
Funtions provided below
****************************************/

double cPower(double x, long int N)
{
  return pow(x, (double)N);
}

double slowPower(double x, long int N)
{
  double pow = 1.0;
  int i;
  for( i = 0;  i < N; i++)
    {
  pow = x*pow;
     }
  // if(i < N)   cout <<"Slow Failed with iteration stop at i = " << i << endl;
  return pow ;
}
//This function needs to be fixed!
double  fastPower(double x, long int N)
{
  double factor = x; // holds x , x^2 , x^4, x^16 etc
  double pow = 1.0;
  while(N > 0)
    { 
      if(N%2) pow = factor*pow ; // Update pow 
      N = N/2;
      // Update factor by squaring to give the correct result incriment
    }
  return pow;
}

double veryfastPower(double x, long int N)
{
    double pow = 1.0;
    for (;;)
    {
      if (N & 1)  //Copies a bit to the result if it exists in both operands.
            pow *= x;
      N >>= 1;  //Binary Right Shift Operator. 
      if (!N)  // Check for zero
            break;
        x = x*x;
    }

    return pow;
}


