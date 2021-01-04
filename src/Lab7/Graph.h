//
// Created by Dallas on 2021/1/3.
//

#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H


#define INFINITY 65500 //��������

//�߱�ڵ�
struct adjNode {
    int name;   //�û�ָ��Ķ�������
    int weight; //��Ȩ��
    adjNode *next;  //ָ����һ���ڵ�
};

//�������Ϣ
struct VNode {
    int name;   //��������
    adjNode *next;  //ָ���һ���߱�ڵ�
};

const int MaxVertexCount = 210;//ͼ������Ķ������ֵ

class GraphLinkedTable {
private:
    VNode VERTEX[MaxVertexCount];
    int VertexCount;    //ʵ�ʶ�����
    int EdgeCount;      //ʵ�ʱ���
    int prev[210];
public:
    GraphLinkedTable();

    ~GraphLinkedTable() {}

    void InsertEdge(int v1, int v2, int w);

    void BuildGraph();

    void print_path(int end_vertex);

    void Dijkstra();

    int Distance(int v1,int v2);
};

#endif //ALGORITHM_GRAPH_H
