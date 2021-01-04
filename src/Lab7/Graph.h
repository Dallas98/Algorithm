//
// Created by Dallas on 2021/1/3.
//

#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H


#define INFINITY 65500 //代表无穷

//边表节点
struct adjNode {
    int name;   //该弧指向的顶点名称
    int weight; //弧权重
    adjNode *next;  //指向下一个节点
};

//顶点表信息
struct VNode {
    int name;   //顶点名称
    adjNode *next;  //指向第一个边表节点
};

const int MaxVertexCount = 210;//图中允许的顶点最大值

class GraphLinkedTable {
private:
    VNode VERTEX[MaxVertexCount];
    int VertexCount;    //实际顶点数
    int EdgeCount;      //实际边数
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
