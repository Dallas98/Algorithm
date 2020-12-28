//
// Created by 99025 on 2020/12/26.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "set.h"

//构建Set
Set *init(){
    Set *set = (Set*)malloc(sizeof(Set));
    set = create_rbtree();
    return set;
}

//初始化集合
void set_init(Set *set, int data[],int size) {
    //set = create_rbtree();
    for (int i = 0; i < size; i++) {
        set_insert(set, data[i]);
    }
}

//插入数据
int set_insert(Set *set, void *data) {
    if (set_find(set, data) == 0) {
        return 0;
    }
    return insert_rbtree(set, (Type) data);
}

//删除数据
int set_remove(Set *set, void **data) {
    if (iterative_rbtree_search(set, (Type) *data) == 0) {
        delete_rbtree(set, (Type) *data);
        return 0;
    }
    return -1;
}

//清空数据
int set_clear(Set *set) {
    destroy_rbtree(set);
    return 0;
}

//查找
int set_find(Set *set, void *data) {
    return rbtree_search(set, data);
}

//交集
int set_intersection(Set *seti, const Set *set1, const Set *set2) {
    //找到两个集合的最小节点
    Node *min1 = minimum(set1->node);
    Node *min2 = minimum(set2->node);

    //如果某个集合为空，直接返回
    if (min1 == NULL || min2 == NULL)
        return 0;
    int compare = 0;

    while (min1 && min2) {
        compare = rb_key(min1) - rb_key(min2);
        if (compare == 0) {
            set_insert(seti, rb_key(min1));
            min1 = rbtree_successor(min1);
            min2 = rbtree_successor(min2);
        } else if (compare < 0) {
            min1 = rbtree_successor(min1);
        } else {
            min2 = rbtree_successor(min2);
        }
    }
    return 0;
}


//并集
int set_union(Set *setu, const Set *set1, const Set *set2) {
    //找到两个集合的最小节点
    Node *min1 = minimum(set1->node);
    Node *min2 = minimum(set2->node);

    //如果某个集合为空，直接返回
    if (min1 == NULL || min2 == NULL)
        return 0;
    int compare = 0;

    while (min1 && min2) {
        compare = rb_key(min1) - rb_key(min2);
        if (compare == 0) {
            set_insert(setu, rb_key(min1));
            min1 = rbtree_successor(min1);
            min2 = rbtree_successor(min2);
        } else if (compare < 0) {
            set_insert(setu,rb_key(min1));
            min1 = rbtree_successor(min1);
        } else {
            set_insert(setu,rb_key(min2));
            min2 = rbtree_successor(min2);
        }
    }
    if(min1==NULL){
        while(min2){
            set_insert(setu,rb_key(min2));
            min2 = rbtree_successor(min2);
        }
    }
    else{
        while(min1){
            set_insert(setu,rb_key(min1));
            min1 = rbtree_successor(min1);
        }
    }
    return 0;
}

//差集
int set_difference(Set *setd, const Set *set1, const Set *set2) {
    //找到两个集合的最小节点
    Node *min1 = minimum(set1->node);
    Node *min2 = minimum(set2->node);

    //如果某个集合为空，直接返回
    if (min1 == NULL || min2 == NULL)
        return 0;
    int compare = 0;

    while (min1 && min2) {
        compare = rb_key(min1) - rb_key(min2);
        if (compare == 0) {
            min1 = rbtree_successor(min1);
            min2 = rbtree_successor(min2);
        } else if (compare < 0) {
            set_insert(setd,rb_key(min1));
            min1 = rbtree_successor(min1);
        } else {
            set_insert(setd,rb_key(min2));
            min2 = rbtree_successor(min2);
        }
    }
    if(min1==NULL){
        while(min2){
            set_insert(setd,rb_key(min2));
            min2 = rbtree_successor(min2);
        }
    }
    else{
        while(min1){
            set_insert(setd,&rb_key(min1));
            min1 = rbtree_successor(min1);
        }
    }
    return 0;
}

//打印集合
void set_print(Set *set){
    inorder_rbtree(set);
}