#include <iostream>
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
		cout << head->data << " ";
		display(head->next);
	}
	cout << "\n";
}

void main() {
	LinkedList LL;
	LL.addNode(1);
	LL.addNode(2);
	LL.addNode(3);
	LL.display(LL.getHead());

	
	LL.addFrontNode(-1);
	LL.display(LL.getHead());

	// 4번째에 0 삽입
	LL.insertNode(LL.getHead()->next->next, 0);
	LL.display(LL.getHead());

	// 3번째값 제거 
	LL.deleteNode(LL.getHead()->next);
	LL.display(LL.getHead());
}
