#include <iostream>
#include <stack>

class Node {
    public:
        int data;
        Node* next; 
        // value를 data로 입력
        Node(int value) : data(value), next(nullptr) {}
};

class LinkedList{
    private:
        // head라는 포인터 변수 선언. 초기화.
        Node* head;
    
    public:
        LinkedList() : head(nullptr) {}

        // Linked list 출력
        void display(){
            // curr 포인터 변수 선언. 초기화. Linked List의 Head를 가르킴.
            Node* curr = head;
            while(curr){
                std::cout << curr->data << " -> ";
                curr = curr->next;
            }
            std::cout << "\n";
        }
        // 기존 Linked List 모두 지우기
        void clear(){
            Node* curr = head;
            while(curr){
                Node*temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = nullptr;
        }

        // array to Linked List
        void fromArray(int arr[], int size){
            clear();    // clear the exisiting list 

            for (int i=0; i<size; ++i){
                insertBack(arr[i]);
            }
        }

        // Value를 리스트 앞에 삽입
        void insertFront(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
        
        // Value를 리스트 뒤에 삽입
        void insertBack(int value){
            Node* newNode = new Node(value);
            if (!head){
                head = newNode;
            }
            else{
                Node* curr = head;
                while (curr->next){
                    curr = curr->next;
                }
                curr->next = newNode;
            }
        }

        // Value값을 선형 탐색
        Node* search(int value){
            Node* curr = head;
            while (curr) {
                if (curr->data == value){
                    std::cout << value << " is in Linked List."  << "\n";
                    return curr;
                }
                curr = curr->next;
            }
            std::cout << value << " is not founded." << "\n";
            return nullptr; // 없는 경우 nullptr 리턴 
        }

        // Value값 삭제 
        void deleteNode(int value){
            if (!head){
                std::cout << "Noting to delete.";
                return;
            }
            // 삭제할 노드가 Head인 경우 : 1. 삭제값을 temp에 저장한다.  2.head->next를 Head로 만든다.  3. 삭제
            if (head->data == value){
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            // 그외의 경우 : 1. Value값 탐색한다. 2. 삭제값(curr->next)을 저장한다. 3. 삭제값->next(curr->next->next)를 삭제값(curr->next)으로 만든다. 4.삭제
            Node* curr = head;
            while (curr->next){
                if (curr->next->data == value){
                    Node* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                }
            }
            
        }

        // 리스트 뒤집기.
        void reverse(){
            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;

            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }

        // 리스트 정렬 
        void sort(){
            if (!head || !head->next){
                return;     // element가 0~1개인 경우 정렬 불필요
            }
            // Bubble sort
            bool swaped;
            Node* curr;
            Node* last = nullptr;

            while (true){
                swaped = false;
                curr = head;
                // 정렬되지 않은 부분을 한 요소씩 줄이면서(last=curr), 큰값을 뒤로 보냄. 
                while (curr->next != last) {
                    if (curr->data > curr->next->data){
                        std::swap(curr->data, curr->next->data);
                        swaped = true;
                    }
                    curr = curr->next;
                }
                if (!swaped){
                    break; // 만약 스왑이 이뤄지지 않으면 정렬이 완료.
                }
                last = curr;
            }          
        }

        // 팰린드롬
        bool isPalindrome(){
            if (!head || !head->next){
                return true;
            }
            // 스택을 사용하여 LinkedList의 절반을 저장. 뒤->앞으로 Traversal 하며, 나머지 절반과 비교
            std::stack<int> Stack;
            Node* slow = head;
            Node* fast = head;

            // 1. Stack에 LinkedList의 절반을 저장
            while (fast && fast->next){
                Stack.push(slow->data);
                slow = slow->next;
                fast = fast->next->next;
            }
            // 만약 리스트의 길이가 홀수(fast 존재)이면, Middle Node는 건너뜀.
            if (fast){
                slow = slow->next;
            }
            // 2. 나머지 절반을 탐색하면서, stack.top(list back element)과 비교
            while (slow){
                if (slow->data != Stack.top()){
                    std::cout << "This list is NOT palindrome" << "\n";
                    return false;
                }
                Stack.pop();
                slow = slow->next;
            }
            std::cout << "This list is Palindrome." << "\n";
            return true;
        }

        // 부분리스트 확인
        bool isSublist(LinkedList& otherList){
            Node* curr = head;
            Node* otherCurr = otherList.head;

            // 매인 리스트를 탐색하면서, 메인 리스트 현재노드(curr)와 다른 리스트의 현재노드가 일치하면,
            while (curr){
                if(curr->data == otherCurr->data){
                    // 다른 리스트의 남은 노드들과 일치하는지 확인
                    Node* tempCurr = curr;
                    while (tempCurr && otherCurr && tempCurr->data == otherCurr->data){
                        tempCurr = tempCurr->next;
                        otherCurr = otherCurr->next;
                    }
                    // 다른 리스트 전체가 일치(!otherCurr)하면 True
                    if (!otherCurr){
                        std::cout << "is SubList." <<"\n";
                        return true;
                    }
                    // else {다른 리스트의 현재노드를 초기화}
                    otherCurr = otherList.head;
                }
                curr = curr->next;
            }
            std::cout << "is NOT Sublist." << "\n";
            return false;
        }

};

int main(){
    LinkedList linked_list;
    linked_list.insertBack(5);
    linked_list.insertBack(3);
    linked_list.insertBack(4);
    linked_list.insertFront(5);
    linked_list.insertFront(2);
    linked_list.display();

    linked_list.search(5);
    linked_list.search(7);

    linked_list.deleteNode(2);
    linked_list.display();
    linked_list.deleteNode(5);
    linked_list.display();

    linked_list.reverse();
    linked_list.display();
    linked_list.sort();
    linked_list.display();

    linked_list.insertBack(5);
    linked_list.insertBack(4);
    linked_list.insertBack(3);
    linked_list.isPalindrome();
    linked_list.display();
    linked_list.insertBack(7);
    linked_list.isPalindrome();
    linked_list.display();
    linked_list.insertBack(1);


    std::cout << "==============================" << "\n";
    LinkedList list1;
    LinkedList list2;
    int arr_1[] = {1,3,5,3,1};
    int arr_2[] = {3,5,3};

    list1.fromArray(arr_1, sizeof(arr_1)/sizeof(arr_1[0]));
    list2.fromArray(arr_2, sizeof(arr_2)/sizeof(arr_2[0]));
    list1.display();
    list2.display();

    list1.isPalindrome();
    list1.isSublist(list2);

}
