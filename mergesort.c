#include <stdio.h>

void merge(int A[], int temp[],int left, int mid, int right){
	
	int i,j,k;
	i = left;
	j = mid + 1;
	k = left;
	
	while(i <= mid && j <= right){
		if(A[i] <= A[j]){
			temp[k++] = A[i++];
			
		}else {
			temp[k++] = A[j++];
		}
	}
	
	while(i <= mid){
		temp[k++] = A[i++];
	}
	
	while(j <= right){
		temp[k++] = A[j++];
	}
	
	for (i = left; i<= right; i++) A[i] = temp[i];
	

}

void mergesort(int A[], int temp[],int left, int right){

	if(left < right){
		int mid = (left + right)/2;
		mergesort(A,temp,left,mid);
		mergesort(A,temp,mid+1,right);
		merge(A,temp,left,mid,right);
	}

}

int main(){
	
	int n;
	
	printf("Enter the Number of elements: ");
	scanf("%d", &n);
	
	int A[n], temp[n];
	
	for(int i = 0; i < n; i++){
		printf("Enter element number %d: ", i+1);
		scanf("%d", &A[i]);
	}
	
	printf("\nOriginal Array: ");
	for(int i = 0; i < n; i++){
		printf("%d ", A[i]);
		
	}
	
	mergesort(A, temp, 0, n-1);
	
	printf("\nSorted Array : ");
	for(int i = 0; i < n; i++){
		printf("%d ", A[i]);
		
	}
	
	return 0;
}
