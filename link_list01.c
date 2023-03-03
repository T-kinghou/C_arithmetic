#include<stdlib.h>
#include<stdio.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct _list{
    Node* head;
    Node* tail;
}List;

void add(List* pList, int number);
void print(List *pList);

int main(int argc, char *argv[]){
    List list;
    int number;
    list.head = NULL;
    list.tail = NULL;
    do{
        scanf("%d",&number);
        if( number != -1){
            add(&list , number);
        }
    }while ( number != -1);
    print( &list );
    system("pause");
    return 0;
}

void add(List* pList, int number){
    //add to linked-list
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    //find the last
    // Node* last = pList->head;
    // if(last ){
    //     while( last ->next ){
    //         last = last->next;
    //     }
    //     // attach(Á´½Ó)
    //     last->next = p;
    // }else{
    //     pList->head = p;
    // }
    Node* last = pList->tail;
    if(last){
        while( last->next){
            last = last->next;
        }
        last->next = p;
        pList->tail = p;
    }else{
        pList->head = p;
        pList->tail = p;
    }
}

void print(List *pList){
    Node* p;
    for( p=pList->head; p ; p= p->next){
        printf("%d\t ", p->value);
    }
    printf("\n");
}