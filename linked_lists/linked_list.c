//this is a static linked list with only 5 values
//there is a memory pool from where a node is created and also returned after deletion
#include <stdio.h>
struct Student{
    int id;
    int maths;
    int science;
    struct Student *next;
};

struct Student s[5];
struct Student *freenode= NULL;

void initPool(){
    for(int i=0;i<4;i++){
        s[i].next = &s[i+1];
    }
    s[4].next = NULL;
    freenode = &s[0];
}


struct Student *getNode(){
    if(freenode == NULL){
        return NULL;
    }
    struct Student *temp = freenode;
    freenode = freenode->next;
    temp->next = NULL;
    
    return temp;
}

void returnNode(struct Student *node){
    node->next = freenode;
    freenode = node;
}
void insertAfter(struct Student **head,int t_id, int id, int m, int s){
    
    struct Student *newNode = getNode();
    if(!(newNode)){
        printf("\nMemory full");
        return;
    }
    newNode->id = id;
    newNode->maths = m;
    newNode->science = s;
    if(*head == NULL){
        *head = newNode;
        newNode->next = NULL;
        return;
    }
    struct  Student *temp = *head;
    while(temp != NULL && temp->id != t_id){
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("\nID not found");
        return ;
    }
    
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(struct Student **head,int t_id, int id, int m, int s){
    
    struct  Student *temp = *head;
    struct  Student *prev = NULL;
    struct Student *newNode = getNode();
    if(!(newNode)){
        printf("\nMemory full");
        return;
    }
    newNode->id = id;
    newNode->maths = m;
    newNode->science = s;
    if(*head == NULL){
        *head = newNode;
        newNode->next = NULL;
        return;
    }
    while(temp != NULL && temp->id != t_id){
        
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("\nID not found");
        return;
    }
    if(prev == NULL){
        newNode->next = *head;
        *head = newNode;
    }
    else{
        newNode->next = temp;
        prev->next = newNode;
    }
}

void deleteNode(struct Student **head, int id){
    struct Student *temp = *head;
    struct Student *prev = NULL;
    while(temp!=NULL && temp->id != id){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("\n ID not found");
        return;
    }
    if(prev == NULL){
        *head = temp->next;
        returnNode(temp);
    }
    else{
        prev->next = temp->next;
        returnNode(temp);
    }
}
void display(struct Student *head);


int main()
{
    initPool();
    int c,id,m,s,t_id,b,d_id;
    struct Student *head = NULL;
    while(1){
        printf("\n1. to insert\n2. to display\n3. Delete\n4. Exit\nEnter choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("\nEnter id\t Maths\t Science");
            scanf("%d %d %d", &id, &m, &s);
            printf("\nEnter target id");
            scanf("%d",&t_id);
            printf("\n1. Before\n2. After\n");
            scanf("%d",&b);
            switch(b){
                case 1:
                insertBefore(&head,t_id,id,m,s);
                break;
                case 2:
                insertAfter(&head,t_id,id,m,s);
                break;
            }
            break;
            case 2:
            display(head);
            break;
            case 3:
            printf("Enter ID to be deleted");
            scanf("%d",&d_id);
            deleteNode(&head,d_id);
            break;
            case 4:
            return 0;
            default:
            printf("\n wrong choice");
        }
    }
    return 0;
}

void display(struct Student *head){
    struct Student *temp = head;
    printf("\nID\tMaths\tScience");
    while(temp!= NULL){
        printf("\n%d\t%d\t%d",temp->id,temp->maths,temp->science);
        temp = temp->next;
    }
}
