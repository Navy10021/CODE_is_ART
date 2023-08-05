#include<bits/stdc++.h>
using namespace std;

// Linked List Node 
struct Node {
	int data;
	struct Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	void print() {
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data) {
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}

	void reverse(){
		Node* curr = head;
		Node* prev = NULL;
		Node* temp = NULL;

		while(curr != NULL){
			temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		head = prev;
	}
};


int main() {
	LinkedList LL;
	LL.push(1);
	LL.push(2);
	LL.push(3);
	LL.push(4);
	LL.push(5);

	LL.print();
	cout << "\n";
	LL.reverse();
	LL.print();
}
