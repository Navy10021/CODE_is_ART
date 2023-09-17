# include<iostream>

class Node {
    public:
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
};


void printList(Node* head){
    while (head != nullptr){
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

void swapNode(Node* &a, Node* &b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void generatePermutation(Node* head, Node* curr){
    if (curr == nullptr){
        printList(head);
        return;
    }

    for (Node* temp = curr; temp != nullptr; temp=temp->next){
        swapNode(curr, temp);
        generatePermutation(head, curr->next);
        swapNode(curr, temp); // backtracking
    }
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    generatePermutation(head, head);

    // clean up memory
    while(head != nullptr){
        Node* tmep = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
