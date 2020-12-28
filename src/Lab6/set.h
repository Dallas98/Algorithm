//
// Created by 99025 on 2020/12/26.
//

#ifndef ALGORITHM_SET_H
#define ALGORITHM_SET_H

#include "rbtree.h"

typedef RBRoot Set;


Set *init();
//初始化
void set_init(Set *set, int *data,int size);

//插入
int set_insert(Set *set, void *data);

//删除
int set_remove(Set *set, void **data);

//清空
int set_clear(Set *set);

//查找
int set_find(Set *set, void *data);

//交集
int set_intersection(Set *seti, const Set *set1, const Set *set2);

//并集
int set_union(Set *setu, const Set *set1, const Set *set2);

//差集
int set_difference(Set *setd, const Set *set1, const Set *set2);

//打印集合
void set_print(Set *set);
#endif //ALGORITHM_SET_H
