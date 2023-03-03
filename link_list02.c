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
    //搜索链表
    printf("请输入你需要搜索的数据: ");
    int x;
    scanf("%d" , &x);
    Search( &list, x);
    //输出链表
    print( &list);
    //删除指定链表
    int y;
    printf("请输入你需要删除的数据: ");
    scanf("%d" ,&y);
    Dellist( &list,  y);
    print( &list);
    //删除整个链表
    Delall( &list );
    system("pause");
    return 0;

}

void add( List* plist, int number){
    Node* p = (Node*)malloc(sizeof(Node));
    p ->value = number;
    p ->next = NULL;
    if(plist->head){
        //连接链表
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
            printf("找到了这个数%d\n",p->value);
            ret =1;
            break;
        }
    }
    if( !ret ){
        printf("没有找到这个数\n");
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
        printf("找到该数，并删除成功\n");
    }else{
        printf("没有找到这个数，删除失败\n");
    }
}
void Delall( List* plist){
    Node* p,*q;
    for( p=NULL,q=plist->head; p; p=q,p=p->next){
        free(p);
    }
    printf("整个链表已经清空\n");
}