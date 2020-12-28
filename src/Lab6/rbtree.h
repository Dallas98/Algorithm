#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_

#define RED        0    // 红色节点
#define BLACK    1    // 黑色节点

typedef int Type;

// 红黑树的节点
typedef struct RBTreeNode {
    unsigned char color;        // 颜色(RED 或 BLACK)
    Type key;                    // 关键字(键值)
    struct RBTreeNode *left;    // 左孩子
    struct RBTreeNode *right;    // 右孩子
    struct RBTreeNode *parent;    // 父结点
} Node, *RBTree;

// 红黑树的根
typedef struct rb_root {
    Node *node;
} RBRoot;

// 创建红黑树，返回"红黑树的根"！
RBRoot *create_rbtree();

// 销毁红黑树
void destroy_rbtree(RBRoot *root);

// 将结点插入到红黑树中。插入成功，返回0；失败返回-1。
int insert_rbtree(RBRoot *root, Type key);

// 删除结点(key为节点的值)
void delete_rbtree(RBRoot *root, Type key);

// 前序遍历"红黑树"
void preorder_rbtree(RBRoot *root);

// 中序遍历"红黑树"
void inorder_rbtree(RBRoot *root);

// 后序遍历"红黑树"
void postorder_rbtree(RBRoot *root);

// (递归实现)查找"红黑树"中键值为key的节点。找到的话，返回0；否则，返回-1。
int rbtree_search(RBRoot *root, Type key);

// (非递归实现)查找"红黑树"中键值为key的节点。找到的话，返回0；否则，返回-1。
int iterative_rbtree_search(RBRoot *root, Type key);

// 返回最小结点的值(将值保存到val中)。找到的话，返回0；否则返回-1。
int rbtree_minimum(RBRoot *root, int *val);

// 返回最大结点的值(将值保存到val中)。找到的话，返回0；否则返回-1。
int rbtree_maximum(RBRoot *root, int *val);

// 打印红黑树
void print_rbtree(RBRoot *root);

//最小结点
Node* minimum(RBTree tree);

//后继结点
Node* rbtree_successor(RBTree x);

//前驱结点
static Node* rbtree_predecessor(RBTree x);

//(递归实现)查找"红黑树x"中键值为key的节点
static Node* search(RBTree x, Type key);

//(非递归实现)查找"红黑树x"中键值为key的节点
static Node* iterative_search(RBTree x, Type key);

#define rb_key(r)   ((r)->key)
#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c)

#endif