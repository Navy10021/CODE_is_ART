/*
Queue : 선입선출(FIFO) : enqueue(추가) / dequeue(제거) / front(제거없이 가져오기)
      : isEmpty(비어있는지 확인) / size(큐의 크기)
*/
#include <iostream>

template <typename T>
class Queue{
    private:
        struct Node{
            T data;
            Node* next;
            Node(const T& value) : data(value), next(nullptr) {}
        };
        
        Node* frontNode; // 머리노드
        Node* rearNode;  // 꼬리노드
        size_t queueSize;
    
    public:
        Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

        void enqueue(const T& item){
            Node* newNode = new Node(item);
            if (isEmpty()) {
                frontNode = rearNode = newNode;
            }
            else {
                rearNode->next = newNode;
                rearNode = newNode;
            }
            queueSize++;
        }

        void dequeue(){
            if (!isEmpty()){
                Node* temp = frontNode;
                frontNode = frontNode->next;
                delete temp;
                queueSize--;
            }
            else{
                std::cout << "Queue is empty.";
                exit(EXIT_FAILURE);
            }
        }

        T front() const {
        if (!isEmpty()) {
            return frontNode->data;
        } else {
            std::cerr << "Queue is empty. Cannot get front element.\n";
            exit(EXIT_FAILURE);
        }
    }
        
        bool isEmpty() const {
            return queueSize == 0;
        }

        size_t size() const{
            return queueSize;
        }

        ~Queue(){
            while (!isEmpty()){
                dequeue();
            }
        }
};

int main(){
    Queue<int> myQ;
    myQ.enqueue(0);
    myQ.enqueue(10);
    myQ.enqueue(100);

    std::cout << myQ.front() << "\n";
    std::cout << myQ.size() << "\n";

    while (!myQ.isEmpty()){
        std::cout << "TOP : " << myQ.front() << "\n";
        myQ.dequeue();
    }
}
