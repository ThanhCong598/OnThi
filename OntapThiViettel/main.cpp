
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 0;
int* a = NULL;
int* b = NULL;


void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 


int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1);  

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
			swap(&a[i], &a[j]);
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	swap(&a[i + 1], &a[high]);
	return (i + 1); 
} 


void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		
		int pi = partition(arr, low, high); 

	
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 



void printArray() 
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("a= %d; b= %d \n", a[i],b[i]); 
    printf("\n"); 
} 


void printMaxActivities(int s[], int f[], int n) 
{ 
    int i, j; 
  
    printf ("Following activities are selected n"); 
  
    // The first activity always gets selected 
    i = 0; 
    printf("%d ", i); 
  
    // Consider rest of the activities 
    for (j = 1; j < n; j++) 
    { 
      
      if (s[j] >= f[i]) 
      { 
          printf ("(a= %d,b= %d)    ", s[j],f[j]); 
          i = j; 
      } 
    } 
} 

int generateNumberInRange(int min, int max)
{
    int r = min + rand() % (max + 1 - min);
    return r;
}

int main(int argc, char** argv)
{

    srand(time(0));
    n = generateNumberInRange(10, 1000);
//    printf("%d \n", n);
    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    float rate = -999;
    do {
    	
        int hasNegativeNumber = 0;
        int i = n - 1;

        while (i >= 0) {
            int check = 0;
            do {
                int signA = generateNumberInRange(0, 1);
                int signB = generateNumberInRange(0, 1);

                if (signA == 0)
                    signA = -1;
                if (signB == 0)
                    signB = -1;

                a[i] = signA * rand();
                b[i] = signB * rand();

                if (a[i] < b[i])
                    check = 1;

            } while (check == 0);

            if ((a[i] < 0) || (b[i] < 0))
                hasNegativeNumber++;
//            printf("%d %d : %d \n", i, a[i], b[i]);

            i = i - 1;
        }
        
//        printf("%d\n",hasNegativeNumber);
        rate = (hasNegativeNumber- n *0.3);
//        printf("%f\n",rate);

    } while ((rate < 0));


    //printArray();

    quickSort(b, 0, n-1);
    
    printMaxActivities(a,b,n);
    return 0;
}


