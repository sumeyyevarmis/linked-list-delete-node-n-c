#include <stdio.h>
#include <stdlib.h>

// linked list düğümü
struct Node{
   int data;
   struct Node* next;
};

// linked list düğüm ekleme
void push(struct Node** head_ref,int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// linked list düğüm silme
void deleteNode(struct Node** head_ref,int key){
    struct  Node *temp = *head_ref,*prev;
    // Eğer ilk düğüm silinecek olan key'i tutuyorsa
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // silinecek olan düğüm aranır
    while (temp != NULL && temp->data != key){
        prev=temp;
        temp=temp->next;
    }
    // Eğer linked list'de key yoksa
    if (temp == NULL){
        return;
    }
    // düğümün linked list'teki bağlantısını kaldır
    prev->next = temp->next;
    free(temp); // free memory
}

void printList(struct Node* node){
    while (node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
}
int main() {
    // boş linked list başlatılır
    struct Node* head = NULL;
    //linked list'e düğüm eklenir
    push(&head,3);
    push(&head,6);
    push(&head,4);
    push(&head,2);
    printf("Linked list:\n ");
    printList(head);
    // linked list'ten düğüm silinir
    deleteNode(&head,4);
    printf("\n4 silindikten sonra linked list: \n");
    printList(head);
    return 0;
}
