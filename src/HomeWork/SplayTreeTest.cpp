//
// Created by 99025 on 2020/12/3.
//

#include <cstdlib>
#include <iostream>
#include "SplayTree.h"
using namespace std;

static int arr[]= {1,2,3,4,5,6,7,8,9,10};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    system("chcp 65001");
    int i,ilen;
    SplayTree<int>* tree=new SplayTree<int>();


    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << "== 依次添加: ";
        cout << arr[i] <<" \n";
        tree->insert(arr[i]);
//        cout << "== 树的详细信息: " << endl;
//        tree->print();
//        cout<<endl;
    }

    cout << "\n== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();

//    i = 3;
//    cout << "\n== 旋转节点(" << i << ")为根节点";
//    tree->splay(i);
//    cout << "\n== 树的详细信息: " << endl;
//    tree->print();

    tree->remove(5);
    tree->print();
    // 销毁二叉树
    tree->destroy();

    return 0;
}