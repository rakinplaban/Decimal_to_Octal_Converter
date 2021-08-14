#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    int data;
    struct Node* next;
}*node;
struct Head{
    int count;
    struct Head* top;
}*head;
struct Node* createNode(int data){
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Head* createStack(){
    head = (struct Head*)malloc(sizeof(struct Head));
    head->count = 0;
    head->top = NULL;
    return head;
};
void push(struct Head* head,int data);
void pop(struct Head* head);
void emptyStack(struct Head* head);
void distroyStack(struct Head* head);
int inputTester(char *string);

int main()
{
    struct Head* s = createStack();
    int n,k,m;
    char number[100];
    gets(number);
    n = inputTester(number);
    k = n;
    do{
        m = n%8;
        push(s,m);
        n = n/8;
    }while(n > 0);
    printf("The Octal form of %d is : ",k);
    while(s->count > 0){
        pop(s);
    }
    return 0;
}

void push(struct Head* head,int data){
    createNode(data);
    if(head->count==0){
        head->top = node;
        head->count++;
    }
    else{
        struct Node* temp;
        temp = head->top;
        head->top = node;
        node->next = temp;
        head->count++;
    }
}

void pop(struct Head* head){
    if(head->count == 0)
        printf("Underflow\n");
    else{
        struct Node* temp;
        temp = head->top;
        printf("%d",temp->data);
        head->top = temp->next;
        free(temp);
        head->count--;
    }
}


int inputTester(char *string){
    int i,flag = 0;
    for(i=0;string[i]!='\0';i++){
        if(!(string[i]>='0' && string[i]<='9'))
            flag = 1;
    }
    if(flag==1){
        printf("Invalid input");
        exit(0);
    }
    else
        return atoi(string);
}
