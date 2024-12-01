#include<iostream>
using namespace std;

// Structure for Linked List Node
struct Node {
    int value;     // The actual value of the element
    int priority;  // The priority of the element
    Node* next;    // Pointer to the next node in the list
};

// PriorityQueue class
class PriorityQueue {
    Node* head;  // Head pointer of the linked list

public:
    // Constructor
    PriorityQueue() {
        head = nullptr;  // Initialize an empty list
    }

    // Insert an element with its priority
    void insert(int value, int priority) {
        // Create a new node with given value and priority
        Node* newNode = new Node;
        newNode->value = value;
        newNode->priority = priority;
        newNode->next = nullptr;

        // If the list is empty or new node has higher priority than the head
        if (head == nullptr || head->priority < priority) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted value " << value << " with priority " << priority << ".\n";
            return;
        }

        // Traverse the list to find the correct position for the new node
        Node* temp = head;
        while (temp->next != nullptr && temp->next->priority >= priority) {
            temp = temp->next;
        }

        // Insert the new node at the correct position
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted value " << value << " with priority " << priority << ".\n";
    }

    // Remove and return the element with the highest priority
    int removeMax() {
        if (head == nullptr) {
            cout << "Priority queue underflow!\n";
            return -1; // Indicate that the queue is empty
        }

        // The highest priority element is at the head
        Node* temp = head;
        int maxValue = head->value;

        // Move the head pointer to the next element
        head = head->next;

        // Delete the old head node
        delete temp;
        cout << "Removed value " << maxValue << " with the highest priority.\n";
        return maxValue;
    }

    // Get the element with the highest priority without removing it
    int getMax() {
        if (head == nullptr) {
            cout << "Priority queue is empty.\n";
            return -1;
        }
        return head->value; // The highest priority element is at the head
    }

    // Display all elements in the priority queue
    void display() {
        if (head == nullptr) {
            cout << "Priority queue is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Value: " << temp->value << ", Priority: " << temp->priority << "\n";
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~PriorityQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Create a priority queue
    PriorityQueue pq;

    // Insert elements with their priorities
    pq.insert(10, 2);  // Value: 10, Priority: 2
    pq.insert(30, 5);  // Value: 30, Priority: 5
    pq.insert(20, 3);  // Value: 20, Priority: 3
    pq.insert(5, 1);   // Value: 5, Priority: 1

    // Display the priority queue
    cout << "Priority Queue:\n";
    pq.display();

    // Get the maximum priority element
    cout << "\nElement with the highest priority: " << pq.getMax() << "\n";

    // Remove the maximum priority element
    pq.removeMax();

    // Display the priority queue after removal
    cout << "\nPriority Queue after removing the highest priority element:\n";
    pq.display();

    return 0;
}

