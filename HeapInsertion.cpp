#include<iostream>
using namespace std;
class MaxHeap{
	int *arr;
	int size;
	int totalSize;
	public:
	MaxHeap(int t){
		size=0;
		totalSize=t;
		arr=new int[totalSize];
	}
	void insert(int value){
		if(size==totalSize){
			cout<<"Heap OverFlow";
			return;
		}
		arr[size]=value;
		int index=size;
		size++;
		
		while(index>0&&arr[(index-1)/2]<arr[index]){
			swap(arr[index],arr[(index-1)/2]);
			index=(index-1)/2;
		}
		cout<<arr[index]<<"is inerted into the heap\n";
	}
	
	void print(){
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
	}
	void Delete(){
		if(size==0){
			cout<<"Heap UnderFlow\n";
			return;
			
		}
		cout<<arr[0]<<" deleted from the Heap";
		arr[0]=arr[size-1];
		size--;
		if(size==0)
			return;
			Heapify(0);
		
	}
	void Heapify(int index){
		int Largest=index;
		int left=2*i+1;
		int right=2*i+2;
		int 
		if(left<size && arr[left]>arr[largest])
		largest=left;
		if(right<size && arr[right]>arr[largest])
		largest=right;
		if(largest!=index)
		swap(arr[index],arr[largest]);
		Heapify(largest); 
		
	}
	
	
};
int main(){
	MaxHeap H1(6);
	H1.insert(4);
	H1.insert(14);
	H1.insert(11);
	H1.print();
}
