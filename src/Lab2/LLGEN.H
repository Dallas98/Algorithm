/*--- llgen.h ----------------------------- Listing 2-2 ---------
 *  Declarations for generic doubly linked lists.通用双链表的声明
 *  Used in conjunction with llgen.c (Listing 2-3).与...结合使用
 *-------------------------------------------------------------*/
#ifndef LLGEN_H       /* make sure it's included only once */
#define LLGEN_H    1


struct Node {
    struct Node     *prev;  /* link to previous node */
    struct Node     *next;  /* link to next node */
    void            *pdata; /* generic pointer to data 数据的通用指针*/
};

typedef struct Node *Link;

/* a linked list data structure */
struct List {
    Link            LHead;
    Link            LTail;
    unsigned int    LCount;
    void * ( * LCreateData )     ( void * );
    int    ( * LDeleteData )     ( void * );
    int    ( * LDuplicatedNode ) ( Link, Link );
    int    ( * LNodeDataCmp )    ( void *, void * );
};

/* The four functions specific to an individual linked list are:
    特定于单个链表的四个函数是
   LCreateData:  is passed a pointer to an application-defined
                 object and is expected to return a pointer to
                 whatever is to be stored in the linked list.
    LCreateData传递了一个指向应用程序定义的对象的指针，并期望返回一个指向要存储在链表中的指针

   LDeleteData:  is passed a pointer to the object an application
                 has stored in a linked list. LDeleteData must
                 destroy the object.
                 LDeleteData传递一个指向应用程序存储在链表中的对象的指针。LDeleteData必须销毁对象。

   LDuplicatedNode: is passed two pointers. The first pointer is
                    to a node that you would like to add to a
                    linked list and the second is to a node that
                    is already in the list but is a duplicate of
                    the first pointer.
                    LDuplicatedNode returns:
                            0 -> do nothing to list
                            1 -> destroy duplicate
                            2 -> add duplicate to list
                    向LDuplicatedNode传递两个指针。第一个指针指向要添加到链表中的节点，
                    第二个指针指向已经在链表中的节点，但是第一个指针的副本。
                    LDuplicatedNode回报:
                    0>什么都不做的列表
                    1 ->销毁副本
                    2 ->添加重复列表

   LNodeDataCmp: is passed pointers to two application data
                 objects and must compare them, returning a
                 number that is < 0, zero, or > 0, depending on
                 the relationship between the first and second
                 objects.

                 LNodeDataCmp是传递给两个应用程序数据对象的指针，必须对它们进行比较，
                 返回一个< 0、0或>0的数字，具体取决于第一个和第二个对象之间的关系。
*/

/*--- generic linked-list primitives 通用链表元素---*/
int  AddNodeAscend  ( struct List *, void * ); //ascend 上升、回溯
int  AddNodeAtHead  ( struct List *, void * );
struct List * CreateLList (
                void * ( * ) ( void * ),       /* create data */
                int    ( * ) ( void * ),       /* delete data */
                int    ( * ) ( Link, Link ),   /* duplicate  复制 */
                int    ( * )  ( void *, void * )); /* compare */
Link CreateNode     ( struct List * , void * );
int  DeleteNode     ( struct List *, Link );
Link FindNode       ( struct List *, void * );
Link FindNodeAscend ( struct List *, void * );
Link GotoNext       ( struct List *, Link );
Link GotoPrev       ( struct List *, Link );
#endif
