#include <iostream>
#include<stdc++.h>
using namespace std;

// Node Struct 구현 
struct node {
	int data;	// Node : 데이터값을 가지는 공간 
	node* next; // next : 다음 데이터의 주소를 저장하는 공간 
};

// Linked List 생성 
class LinkedList {
private:
	node* head;
	node* tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	void addFrontNode(int n);	// 처음에 추가
	void addNode(int n);		// 마지막에 추가
	void insertNode(node* preNode, int n);	// 특정 인덱스에 추가 
	void deleteNode(node* preNode);
	// 첫번째 노드 가져오기 
	node* getHead() {
		return head;
	}
	void display(node* head);
	void getCount(node* head);
	void Reverse(node* head);
};


void LinkedList::addFrontNode(int n) {
	node* temp = new node;
	temp->data = n;

	// Linked List가 비어있으면 
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	// Linked List 데이터가 있으면 
	else {
		temp->next = head;
		head = temp;
	}
}

void LinkedList::addNode(int n) {
	node* temp = new node;
	temp->data = n;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

void LinkedList::insertNode(node* prevNode, int n) {
	node* temp = new node;
	temp->data = n;

	// 1. temp의 next를 저장 
	temp->next = prevNode->next;
	// 2. preNode의 next를 저장 
	prevNode->next = temp;
}

void LinkedList::deleteNode(node* preNode) {
	// 1. 삭제할 노드를 temp에 저장 
	node* temp = preNode->next;
	// 2. 삭제할 노드를 제외(prevNOde next에 next를 저장)
	preNode->next = temp->next;
	// 3. temp 삭제 
	delete temp;
}

void LinkedList::display(node* head) {
	if (head == NULL) {
		cout << '\n';
	}
	else {
		/*
		cout << head->data << " ";
		display(head->next);*/
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	cout << "\n";
}

void LinkedList::getCount(node* head) {
	int cnt = 0;
	node* cur = head;
	while (cur != NULL) {
		cnt++;
		cur = cur->next;
	}
	cout << "len of linked list : " << cnt << '\n';
}

void LinkedList::Reverse(node* head) {
	node* curr = head;
	node* prev = NULL;
	node* temp = NULL;

	while (curr != NULL) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
}


void main() {
	LinkedList LL;
	LL.addNode(1);
	LL.addNode(2);
	LL.addNode(3);
	LL.addNode(4);
	LL.display(LL.getHead());

	// reverse 
	LL.Reverse(LL.getHead());
	LL.display(LL.getHead());
}
