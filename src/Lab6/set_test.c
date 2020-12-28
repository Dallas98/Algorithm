//
// Created by 99025 on 2020/12/27.
// set_test.c
//
#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#define LENGTH(a) sizeof(a)/sizeof(a[0])

int main(){
    system("chcp 65001");
    Set *set1 = init(),*set2=init();
    Set *set3 = init();
    Set *set4 = init();
    Set *set5 = init();
    int a[]={1,2,3,4,4,5};
    int b[]={3,4,5,5,6,6,7};
    int num = 8;
    set_init(set1,a,LENGTH(a));
    set_init(set2,b,LENGTH(b));

    printf("打印待插入set1的数组a：\t");
    for(int i=0;i<LENGTH(a);i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("打印待插入set1的数组b：\t");
    for(int i=0;i<LENGTH(b);i++){
        printf("%d ",b[i]);
    }
    printf("\n");

    printf("打印set1：\t");
    set_print(set1);
    printf("打印set2：\t");
    set_print(set2);

    set_remove(set1,&a[0]);
    printf("删除元素1后，打印set1：\t");
    set_print(set1);

    set_insert(set2,num);
    printf("插入元素8后，打印set2：\t");
    set_print(set2);

    printf("set2中查找是否存在8（0表示存在，-1表示不存在）：\t%d\n",set_find(set2,8));
    printf("set2中查找是否存在9（0表示存在，-1表示不存在）：\t%d\n",set_find(set2,9));

    set_intersection(set3,set1,set2);
    printf("打印set1和set2交集：");
    set_print(set3);

    //set_clear(set3);
    printf("打印set1和set2并集：");
    set_union(set4,set1,set2);
    set_print(set4);

    //set_clear(set3);
    printf("打印set1和set2差集：");
    set_difference(set5,set1,set2);
    set_print(set5);

    return 0;
}