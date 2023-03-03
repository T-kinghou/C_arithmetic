#include<stdio.h>
#include<stdlib.h>
//冒泡排序
int main(){
    int num[10] = {1,5,3,7,0,2,3,1,9,5};
    int temp;
    for(int j = 0; j < sizeof(num)/sizeof(num[0]); j++){
        for(int i = 0; i < sizeof(num)/sizeof(num[0])-j-1; i++){
            if(num[i] > num[i+1]){
                temp = num[i+1];
                num[i+1] = num[i];
                num[i] = temp;
            }
        }
    }
    //遍历输出新数组
    for( int i=0; i<sizeof(num)/sizeof(num[0]); i++){
        printf(" %d",num[i]);
    }
    system("pause");
    return 0;
}