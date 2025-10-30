#include <stdio.h>

void insertionsort(int arr[], int n){
	int i,key,j;
	for(i=1; i < n; i++){
		key = arr[i];
		j = i - 1;
	
	while(j>=0 && arr[j]>key){
		arr[j+1] = arr[j];
		j = j -1;
	}
	arr[j+1] = key;


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
        insertionsort(arr,n);
        printf("\nSorted Array : ");
        for(int i = 0; i < n; i++){
                printf("%d ", arr[i]);

        }


	

	return 0;
}

