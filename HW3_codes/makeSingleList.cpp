#include<iostream>
#include<iomanip>
#include <cstdlib> 
#include <time.h>
#include <math.h>
using namespace std;

#define Asize  100

void swap(int* a, int* b);
void insertionsort(int a[], int N);
void mergeSort(int a[], int a_tmp[], int l, int r);

int main()
{
  
  int a[Asize];
  int a_tmp[Asize];

  int i;

for(i = 0;i<Asize;i++)
  a[i] = (rand() +1)%1000000  ;    

// mergeSort(a,  a_tmp, 0, Asize-1);

 cout << Asize << "\n";
 for(i = 0;i<Asize;i++)
     cout << a[i] << "\n";
 

  return 0;
}

void insertionsort(int a[],  int N)
  { 
    int i, j; 
    for (i = 1; i < N; i++)
      for (j = i; (j>0) && (a[j]< a[j-1]); j--)
        swap(&a[j],&a[j-1]);
  }

void mergeSort(int a[], int a_tmp[], int l, int r)
{

    int i, j, k, m;
   
    if (r > l)
      {
        m = (r+l)/2;
        mergeSort(a, a_tmp, l, m);  
        mergeSort(a,a_tmp, m+1, r);
        for (i = m+1; i > l; i--){
          a_tmp[i-1] = a[i-1];
        }
        for (j = m; j < r; j++){
          a_tmp[r+m-j] = a[j+1]; 
        }
        for (k = l; k <= r; k++){
          a[k] = (a_tmp[i] < a_tmp[j]) ? a_tmp[i++] : a_tmp[j--];       
        }
      }
  }


void swap(int* a, int* b)
{ 
    int temp;
    temp = *a; 
    *a = *b; 
    *b = temp; 
}
