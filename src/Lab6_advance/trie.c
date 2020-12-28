//
// Created by 99025 on 2020/12/27.
//

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "trie.h"

int main() {
    system("chcp 65001");
    Trie *trie = trieCreate();
    printf("插入单词apple后。\n");
    trieInsert(trie, "apple");
    printf("返回1表示查询成功，0表示查询失败\n");
    printf("是否存在单词apple:\t%d\n", trieSearch(trie, "apple"));
    printf("是否存在单词app:\t%d\n", trieSearch(trie, "app"));
    printf("是否存在前缀app:\t%d\n", trieStartsWith(trie, "app"));
    printf("插入单词app后。\n");
    trieInsert(trie, "app");
    printf("是否存在单词app:\t%d\n", trieSearch(trie, "app"));
}

//创建trie树
Trie *trieCreate() {
    Trie *trie = malloc(sizeof(*trie));
    trie->data = '/';
    for (int i = 0; i < 26; i++) {
        trie->child[i] = NULL;
    }
    trie->end = 0;
    return trie;
}

//插入一个结点
void trieInsert(Trie *obj, char *word) {
    Trie *p = obj;
    int len = strlen(word);
    int i = 0;
    while (i < len) {
        int index = word[i] - 'a';
        if (p->child[index] == NULL) {
            Trie *t = malloc(sizeof(*t));
            t->data = word[i];
            t->end = 0;
            for (int i = 0; i < 26; i++) {
                t->child[i] = NULL;
            }
            p->child[index] = t;
        }
        p = p->child[index];
        i++;
    }
    p->end = 1;
}


//根据word值查找节点是否在节点内
bool trieSearch(Trie *obj, char *word) {
    int i = 0;
    int len = strlen(word);
    Trie *p = obj;
    while (i < len) {
        int index = word[i] - 'a';
        if (p->child[index] == NULL)
            return false;
        else {
            i++;
            p = p->child[index];
        }
    }
    if (p->end)
        return true;
    else
        return false;
}

//根据 prefix 值查找是否存在有prefix前缀的节点
bool trieStartsWith(Trie *obj, char *prefix) {
    int i = 0;
    int len = strlen(prefix);
    Trie *p = obj;
    while (i < len) {
        int index = prefix[i] - 'a';
        if (p->child[index] == NULL)
            return false;
        else {
            i++;
            p = p->child[index];
        }
    }
    return true;
}

//Free内存
void trieFree(Trie *obj) {
    if (obj == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        trieFree(obj->child[i]);
        if (obj->child[i] != NULL) {
            free(obj->child[i]);
        }
    }
}