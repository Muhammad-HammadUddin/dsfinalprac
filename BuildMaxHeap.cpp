#include<iostream>
using namespace std;
void Heapify(int arr[],int index,int n){
	int largest=index;
	int left=2*index+1;
	int right=2*index+2;
	if (left<n&&arr[left]>arr[largest]){
		largest=left;
	}
	if (right<n&&arr[right]>arr[largest]){
		largest=right;
	}
	if(largest!=index){
		swap(arr[largest],arr[index]);
		Heapify(arr,largest,n);
	}
}
void BuildMaxHeap(int arr[],int n){
	for(int i=n/2-1;i>=0;i--){
		Heapify(arr,i,n);
	}
}
void print(int arr[],int n){
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
	}
int main(){
	int arr[]={10,3,8,9,5,13,18,14,11,70};
	BuildMaxHeap(arr,10);
	print(arr,10);
	
	
}
