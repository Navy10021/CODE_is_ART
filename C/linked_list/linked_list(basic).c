#include <stdio.h>
#include <stdlib.h>

// Sturcture for a single node 
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push_front(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    
    newNode->next = *head;
    *head = newNode;
}

void push_back(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    
    if (*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
}

void display(struct Node* head){
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int search(struct Node* head, int target){
    struct Node* curr = head;
    int position = 0;
    while (curr != NULL){
        if (curr->data == target){
            return position;
        }
        curr = curr->next;
        position++;
    }
    return -1;  // element not found;
}

// Bubble sort
void sorted(struct Node** head){
    struct Node* curr;
    //struct Node* temp;
    int temp_data;

    if (*head == NULL){
        return;
    }
    int swapped;    // swap 했는지 여부
    do {
        swapped = 0;
        curr = *head;

        while (curr->next != NULL){
            if (curr->data > curr->next->data){
                // Swap data
                temp_data = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp_data;
                swapped = 1;
            }
            curr = curr->next;
        }
    } while (swapped);
}

void reverse(struct Node** head){
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next_node;

    while(curr != NULL){
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    *head = prev;
}

void erase(struct Node** head, int target){
    struct Node* curr = *head;
    struct Node* prev = NULL;

    while(curr != NULL && curr->data != target){
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL){
        return;     // target is not in Linked list
    }

    if (prev == NULL){
        *head = curr->next;
    }
    else{
        prev->next = curr->next;
    }
    free(curr); //memory out -> erase
}

void erase_duplicates(struct Node* head){
    struct Node* curr = head;
    struct Node* runner;    // 현재 노드 보다 다음 블록을 나아가며 중복 확인
    while(curr != NULL){
        runner = curr;
        while (runner->next != NULL){
            if(curr->data == runner->next->data){
                struct Node* duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            }
            else{
                runner = runner->next;
            }
        }
        curr = curr->next;
    }    
}



int main(){
    struct Node* head = NULL;   // creat head Node;
    // Enter the elements(array)
    int N, num;
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d", &num);
        push_back(&head, num);
    }
    printf("Original list : ");
    display(head);
    
    // Search (target)
    printf("%d", search(head, 3));
    printf("\n");
    printf("%d", search(head, 7));
    printf("\n");
    
    // Sorting
    sorted(&head);
    printf("After sorting : ");
    display(head);

    // reverse
    reverse(&head);
    printf("After reverse : ");
    display(head);

    // erase
    erase(&head, 3);
    display(head);

    // erase duplicate
    erase_duplicates(head);
    printf("After erase duplicates : ");
    display(head);
}

