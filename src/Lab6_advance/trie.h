//
// Created by 99025 on 2020/12/27.
//

#ifndef ALGORITHM_TRIE_H
#define ALGORITHM_TRIE_H

#define MAX_CHILD 26
typedef struct Trie {
    char data;
    struct Trie *child[MAX_CHILD];
    int end;
} Trie;

//创建trie树
Trie *trieCreate();

//插入一个结点
void trieInsert(Trie *obj, char *word);

//根据word值查找节点是否在节点内
_Bool trieSearch(Trie *obj, char *word);

//根据 prefix 值查找是否存在有prefix前缀的节点
_Bool trieStartsWith(Trie *obj, char *prefix);

//Free内存
void trieFree(Trie *obj);

#endif //ALGORITHM_TRIE_H
