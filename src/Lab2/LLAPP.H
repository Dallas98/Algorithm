/*--- llapp.h ----------------------------- Listing 2-4a -------
 *  Application-specific data for linked list in lldriver.c (2-5)
 *  Used in conjunction with llapp.c (Listing 2-4b).
 * 在lldriver.c中针对链表的特定应用程序数据(2-5)
 * 与llapp.c一起使用(清单2-4b)。
 *-------------------------------------------------------------*/
#include "llgen.h"
#ifndef LLAPP_H
#define LLAPP_H 1

/*
 *  Our first list's nodes consist of a pointer to
 *  a word and a count of occurrences.
 */

struct NodeData1 {
    char *word;
    unsigned int u;
};

typedef struct NodeData1 * pND1;

extern void * CreateData1 ( void * );
extern int    DeleteData1 ( void * );
extern int    DuplicatedNode1 ( Link, Link );
extern int    NodeDataCmp1 ( void *, void * );


/*
 *  Our second list's nodes consist of a
 *  pointer to a word.
 */

struct NodeData2 {
    char *word;
};

typedef struct NodeData2 * pND2;

extern void * CreateData2 ( void * );
extern int    DeleteData2 ( void * );
extern int    DuplicatedNode2 ( Link, Link );
extern int    NodeDataCmp2 ( void *, void * );

#endif
