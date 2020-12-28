#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_

#define RED        0    // ��ɫ�ڵ�
#define BLACK    1    // ��ɫ�ڵ�

typedef int Type;

// ������Ľڵ�
typedef struct RBTreeNode {
    unsigned char color;        // ��ɫ(RED �� BLACK)
    Type key;                    // �ؼ���(��ֵ)
    struct RBTreeNode *left;    // ����
    struct RBTreeNode *right;    // �Һ���
    struct RBTreeNode *parent;    // �����
} Node, *RBTree;

// ������ĸ�
typedef struct rb_root {
    Node *node;
} RBRoot;

// ���������������"������ĸ�"��
RBRoot *create_rbtree();

// ���ٺ����
void destroy_rbtree(RBRoot *root);

// �������뵽������С�����ɹ�������0��ʧ�ܷ���-1��
int insert_rbtree(RBRoot *root, Type key);

// ɾ�����(keyΪ�ڵ��ֵ)
void delete_rbtree(RBRoot *root, Type key);

// ǰ�����"�����"
void preorder_rbtree(RBRoot *root);

// �������"�����"
void inorder_rbtree(RBRoot *root);

// �������"�����"
void postorder_rbtree(RBRoot *root);

// (�ݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ㡣�ҵ��Ļ�������0�����򣬷���-1��
int rbtree_search(RBRoot *root, Type key);

// (�ǵݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ㡣�ҵ��Ļ�������0�����򣬷���-1��
int iterative_rbtree_search(RBRoot *root, Type key);

// ������С����ֵ(��ֵ���浽val��)���ҵ��Ļ�������0�����򷵻�-1��
int rbtree_minimum(RBRoot *root, int *val);

// ����������ֵ(��ֵ���浽val��)���ҵ��Ļ�������0�����򷵻�-1��
int rbtree_maximum(RBRoot *root, int *val);

// ��ӡ�����
void print_rbtree(RBRoot *root);

//��С���
Node* minimum(RBTree tree);

//��̽��
Node* rbtree_successor(RBTree x);

//ǰ�����
static Node* rbtree_predecessor(RBTree x);

//(�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
static Node* search(RBTree x, Type key);

//(�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
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