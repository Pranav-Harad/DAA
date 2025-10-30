#include <stdio.h>

void selectionsort(int arr[], int n){

	for(int i = 0 ; i < n; i++){
		int min_ind = i;
		
		for(int j = i+1; j<n; j++){
			if(arr[j] < arr[min_ind]){
				min_ind = j;
			}
			
			
		}
		
		int temp = arr[i];
		arr[i] = arr[min_ind];
		arr[min_ind] = temp;
		
	
		}	



}

int main(){
        int n,i;
        printf("Enter the number of elements: ");
        scanf("%d",&n);

        int arr[n];

        for(i = 0; i < n ;i++){
                printf("Enter the element no %d: ",i+1);
                scanf("%d", &arr[i]);
        }
        printf("\nOriginal Array: ");
        for(int i = 0; i < n; i++){
                printf("%d ", arr[i]);

        }
        selectionsort(arr,n);
        printf("\nSorted Array : ");
        for(int i = 0; i < n; i++){
                printf("%d ", arr[i]);

        }




        return 0;
}

