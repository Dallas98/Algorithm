//
// Created by 99025 on 2020/12/27.
//
#include <stdio.h>
#include "set.h"
#define LENGTH(a) sizeof(a)/sizeof(a[0])

int main(){
//    int a[]={1,2,3,4,5};
//    int size = sizeof(a)/ sizeof(int);
//    printf("%d",size);

    Set *set1 = init(),*set2=init();
    Set *set3 = init();
    Set *set4 = init();
    Set *set5 = init();
    int a[]={4,2,7,3,4,5,8,1,4};
    int b[]={3,2,9,5,6,7,5,3,0,9};
    set_init(set1,a,LENGTH(a));
    set_init(set2,b,LENGTH(b));
    set_print(set1);
    set_remove(set1,&a[6]);
    set_print(set1);
    set_print(set2);

    set_intersection(set3,set1,set2);
    set_print(set3);

    //set_clear(set3);
    set_union(set4,set1,set2);
    set_print(set4);

    //set_clear(set3);
    set_difference(set5,set1,set2);
    set_print(set5);

    return 0;
}