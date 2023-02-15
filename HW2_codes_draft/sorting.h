#ifndef SORT_H
#define SORT_H

static int swapCount = 0;

void swap(int* a, int* b)
{
    swapCount++;
    int temp;
    temp = *a; 
    *a = *b; 
    *b = temp; 
}

/* Returns a random integer 0 <= uniform(m) <= m-1 with uniform distribution */
int  uniform(int  m)
{
  return rand() % m;
}  

/* See Knuth's shuffles https://en.wikipedia.org/wiki/Random_permutation */

void initialize_and_permute(int permutation[], int n)
{
  
    for (int i = 0; i <= n-2; i++) {
        int  j = i+uniform(n-i); /* A random integer such that i ≤ j < n */
        swap(&permutation[i], &permutation[j]);   /* Swap the randomly picked element with permutation[i] */
    }
}
//order O(N^2) sorting routines

void insertionsort(int a[],  int N)
  { 
    int i, j; 
    for (i = 1; i < N; i++)
      for (j = i; (j>0) && (a[j]< a[j-1]); j--)
        swap(&a[j],&a[j-1]);
  }

void bubblesort(int a[], int N)
{
  int i, j;
  for (i = 0; i < N-1; i++)
    for (j = N-1; j > i; j--)
      if (a[j] < a[j-1]) 
     swap(&a[j], &a[j-1]);
}


void selectionsort(int a[], int N)
{ 
  int i, j, min;
   
  for (i = 0; i < N-1; i++)
    { 
      min = i;
      for (j = N-1; j > i; j--) 
        if (a[j] < a[min]) 
          min = j; 
      swap(&a[i], &a[min]);
    } 
  
}

// Order Theta(NlogN) sorting


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
	   swapCount++;
          a[k] = (a_tmp[i] < a_tmp[j]) ? a_tmp[i++] : a_tmp[j--];       
        }
      }
  }


// Order O(NlogN) sorting

void quicksort(int a[], int l, int r)
  { 
    int i, j, v;

    if (r > l)
      { 
        v = a[r]; i = l-1; j = r;
        for (;;)
          { 
            while (a[++i] < v) ;
            while (a[--j] > v) ;
            if (i >= j) break;
            swap(&a[i], &a[j]);
          }
        swap(&a[i], &a[r]);
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
      } 
  }


// Order O(N\gamma) for gamma = sorting

void shellsort(int a[], int N)
  { 
    int i, j, h , v;
    for (h = 1; h <= N/9; h = 3*h+1){};
    for ( ; h > 0; h /= 3)
      for (i = h; i < N; i++)
        { 
          v = a[i];  
          for( j = i; (j>=h) && (a[j-h] > v); j -= h){
             a[j] = a[j-h];
	      swapCount++;
          }
          a[j] = v;  
        } 
  }


#endif 
