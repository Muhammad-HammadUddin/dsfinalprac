#include<iostream>
using namespace std;
class Element{
	int value;
	int priority;
};
class PriorityQueue{
	Element* arr;
	int size;
	int capacity;
	public:
		PriorityQueue(int cap){
			capcaity=cap;
			arr=new Element[capacity];
			size=0;
		}
		~PriorityQueue(){
			delete[] arr;
	void insert(int value,int priority){
		if(size==capacity){
			cout<<"Priority Queue is overFlow!\n";
			return;
		}
		Element newElement={value,priority};
		int i=size-1;
		while(i>=0;&&arr[i].priority<newElement.priority){
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=newElement;
		size++;
		cout << "Inserted value " << value << " with priority " << priority << ".\n";

	}
	int removeMax(){
		if(size==0){
			cout<<"priority queue underflow\n";
			return -1;
		}
		int maxValue=arr[0].value;
		for(int i=1;i<size;i++){
			arr[i-1]=arr[i];
		}
		size--;
	cout << "Removed value " << maxValue << " with the highest priority.\n";
    return maxValue;
	}
	
    
    int getMax() {
        if (size == 0) {
            cout << "Priority queue is empty.\n";
            return -1;
        }
        return arr[0].value; // The highest-priority element is at the front
    }
    
    void display() {
        if (size == 0) {
            cout << "Priority queue is empty.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << "Value: " << arr[i].value << ", Priority: " << arr[i].priority << "\n";
        }
    }
};
int main(){
	
}
