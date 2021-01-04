//
// Created by 99025 on 2021/1/3.
//

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <list>
#include "Graph.h"

using namespace std;


//字符串分割函数,delim为模式串
vector<string> split(const string &str, const string &delim) {
    vector<string> res;
    if ("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }
    return res;
}


//开辟邻接表
GraphLinkedTable::GraphLinkedTable() {
    VertexCount = 0;
    EdgeCount = 0;
    for (int i = 1; i < MaxVertexCount; i++) {
        VERTEX[i].name = i;
        VERTEX[i].next = nullptr;
    }
}

void GraphLinkedTable::InsertEdge(int v1, int v2, int w) {
    adjNode *end = new adjNode;
    end->name = v2;
    end->weight = w;
    end->next = nullptr;
    adjNode *temp = VERTEX[v1].next;
    //边表为空，直接挂上
    if (!temp) {
        VERTEX[v1].next = end;
        return;
    }
    //否则采用尾插法
    adjNode *tempbefore = temp;
    while (temp) {
        tempbefore = temp;
        temp = temp->next;
    }
    tempbefore->next = end;
}

void GraphLinkedTable::BuildGraph() {
    ifstream in("resources/data.txt");
    string line;
    string pattern = ", \t";

    if (in) // 有该文件
    {
        cout << "构造无向图中..." << endl;
        while (getline(in, line)) // line中不包括每行的换行符
        {
            //解析每行字符串保存在vector中
            vector<string> nums;
            nums = split(line, pattern);
            //插入图中
            if (nums.size() % 2 != 1) {
                cout << "Error, incorrect number of digits" << endl;
            } else {
                int v1 = stoi(nums[0]);
                for (int i = 2; i < nums.size(); i = i + 2) {
                    InsertEdge(v1, stoi(nums[i - 1]), stoi(nums[i]));
                    EdgeCount++;
                }
                VertexCount++;
            }
        }
        EdgeCount = EdgeCount / 2;
        cout << "构造完成，图节点总数:" << VertexCount << ", 边总数:" << EdgeCount << endl;
    } else // 没有该文件
    {
        cout << "no such file" << endl;
    }
}


int GraphLinkedTable::Distance(int v1, int v2) {
    adjNode *temp = VERTEX[v1].next;
    while (temp) {
        if (temp->name == v2) {
            return temp->weight;
        } else {
            temp = temp->next;
        }
    }
    return INFINITY;
}

void GraphLinkedTable::print_path(int end) {
    if (prev[end] != 0) {
        print_path(prev[end]);
        cout << "-->";
    }
    cout << end;
}

//vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
//prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
//dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
void GraphLinkedTable::Dijkstra() {
    int start;
    cout << "请输入起始起点(1-200):" << endl;
    while (cin >> start) {
        vector<int> dist(VertexCount + 1, INFINITY);
//        vector<int> prev(VertexCount + 1, 0);
        vector<bool> flag(VertexCount + 1, false);

        //初始化dist数组
        for (int i = 1; i <= VertexCount; i++) {
            prev[i] = 0;
            flag[i] = false;
            dist[i] = Distance(start, i);
        }

        flag[start] = true;
        dist[start] = 0;

        int k = 0;
        for (int i = 1; i < VertexCount; i++) {
            // 寻找当前最小的路径；
            // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
            int min = INFINITY;
            for (int j = 1; j <= VertexCount; j++) {
                if (flag[j] == false && dist[j] < min) {
                    min = dist[j];
                    k = j;
                }
            }
            // 标记"顶点k"为已经获取到最短路径
            flag[k] = true;

            // 修正当前最短路径和前驱顶点
            // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
            for (int j = 1; j <= VertexCount; j++) {
                int tmp = Distance(k, j);
                tmp = (tmp == INFINITY ? INFINITY : (min + tmp)); // 防止溢出
                if (flag[j] == false && (tmp < dist[j])) {
                    dist[j] = tmp;
                    prev[j] = k;
                }
            }
        }
        for (int i = 1; i <= VertexCount; i++) {
            printf("shortest(%d, %d)=%d \t最短路径:%d", start, i, dist[i], start);
            if (start != i) {
                cout << "-->";
                print_path(i);
            }
            cout << endl;
        }
        cout << "请输入起始起点(1-200):" << endl;
    }
}