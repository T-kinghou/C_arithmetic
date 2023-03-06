#include <stdio.h>
#include<stdlib.h>
int f(int p);
int main()
{
    int indx;
    for(int i=1;i<=12;i++){
        indx = f(i);
        printf("µÚ%dÔÂ:%d \n",i,indx);
    }
    /********** Begin **********/

    /********** End **********/
    system("pause");
    return 0;
}
int f(int p){
    if(p==1){
    return 1;
    }else if(p==2){
    return 1;
    }else
    return f(p-1)+f(p-2);
}