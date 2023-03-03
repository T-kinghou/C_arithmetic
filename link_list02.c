#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node* next;
}Node;

 typedef struct _list{
    Node* head;
    Node* tail;
}List;

void add( List* plist, int number );
void print(List *plist);
void Search(List* plist, int x);
void Dellist(List* plist, int y);
void Delall( List* plist);

int main(){
    int number;
    List list;
    list.head = NULL;
    list.tail = NULL;
    do{
        scanf("%d" ,&number);
        if( number != EOF){
            //add to the new date
            add( &list, number );
        }
    }while(number != EOF);
    //��������
    printf("����������Ҫ����������: ");
    int x;
    scanf("%d" , &x);
    Search( &list, x);
    //�������
    print( &list);
    //ɾ��ָ������
    int y;
    printf("����������Ҫɾ��������: ");
    scanf("%d" ,&y);
    Dellist( &list,  y);
    print( &list);
    //ɾ����������
    Delall( &list );
    system("pause");
    return 0;

}

void add( List* plist, int number){
    Node* p = (Node*)malloc(sizeof(Node));
    p ->value = number;
    p ->next = NULL;
    if(plist->head){
        //��������
       plist->tail->next = p;
       plist->tail = p;
    }else{
        plist->head = p;
        plist->tail = p;
    }
}
void print(List *plist){
    Node* p;
    for(p=plist->head; p; p=p->next){
        printf("%d\t ",p->value);
    }
    printf("\n");
}
void Search(List* plist, int x){
    Node* p;
    int ret=0;
    for( p=plist->head; p; p=p->next){
        if( x==p->value){
            printf("�ҵ��������%d\n",p->value);
            ret =1;
            break;
        }
    }
    if( !ret ){
        printf("û���ҵ������\n");
    }
}
void Dellist(List* plist, int y){
    Node* p,*q;
    int ret=0;
    if( plist->head != plist->tail ){
    for( p=plist->head,q=plist->head->next; q; p=q,q=q->next){
        if(q->value==y){
            p->next = q->next;
            free(q);
            ret = 1;
            break;
        }
    }
    }else{
        p = plist->head;
        if( p->value==y){
            plist->head = NULL;
            free(p);
        }else{
            ret = 1;
        }
    }
    if( ret ){
        printf("�ҵ���������ɾ���ɹ�\n");
    }else{
        printf("û���ҵ��������ɾ��ʧ��\n");
    }
}
void Delall( List* plist){
    Node* p,*q;
    for( p=NULL,q=plist->head; p; p=q,p=p->next){
        free(p);
    }
    printf("���������Ѿ����\n");
}