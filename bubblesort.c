#include <stdio.h>

void bubblesort(int arr[], int n)
{
	int i, j, temp;
	
	for(i = 0; i < n-1; i++){
	
		for(j = 0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			
			
			}		
			
		
		}
	
	
	}


}

void printarray(int arr[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(){
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printarray(arr, n);
    

    printf("Sorted array:\n");
    bubblesort(arr, n);
    printarray(arr, n);
    


   return 0;
	
	
}
