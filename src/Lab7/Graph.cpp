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


//�ַ����ָ��,delimΪģʽ��
vector<string> split(const string &str, const string &delim) {
    vector<string> res;
    if ("" == str) return res;
    //�Ƚ�Ҫ�и���ַ�����string����ת��Ϊchar*����
    char *strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p) {
        string s = p; //�ָ�õ����ַ���ת��Ϊstring����
        res.push_back(s); //����������
        p = strtok(NULL, d);
    }
    return res;
}


//�����ڽӱ�
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
    //�߱�Ϊ�գ�ֱ�ӹ���
    if (!temp) {
        VERTEX[v1].next = end;
        return;
    }
    //�������β�巨
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

    if (in) // �и��ļ�
    {
        cout << "��������ͼ��..." << endl;
        while (getline(in, line)) // line�в�����ÿ�еĻ��з�
        {
            //����ÿ���ַ���������vector��
            vector<string> nums;
            nums = split(line, pattern);
            //����ͼ��
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
        cout << "������ɣ�ͼ�ڵ�����:" << VertexCount << ", ������:" << EdgeCount << endl;
    } else // û�и��ļ�
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

//vs -- ��ʼ����(start vertex)��������"����vs"��������������·����
//prev -- ǰ���������顣����prev[i]��ֵ��"����vs"��"����i"�����·����������ȫ�������У�λ��"����i"֮ǰ���Ǹ����㡣
//dist -- �������顣����dist[i]��"����vs"��"����i"�����·���ĳ��ȡ�
void GraphLinkedTable::Dijkstra() {
    int start;
    cout << "��������ʼ���(1-200):" << endl;
    while (cin >> start) {
        vector<int> dist(VertexCount + 1, INFINITY);
//        vector<int> prev(VertexCount + 1, 0);
        vector<bool> flag(VertexCount + 1, false);

        //��ʼ��dist����
        for (int i = 1; i <= VertexCount; i++) {
            prev[i] = 0;
            flag[i] = false;
            dist[i] = Distance(start, i);
        }

        flag[start] = true;
        dist[start] = 0;

        int k = 0;
        for (int i = 1; i < VertexCount; i++) {
            // Ѱ�ҵ�ǰ��С��·����
            // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
            int min = INFINITY;
            for (int j = 1; j <= VertexCount; j++) {
                if (flag[j] == false && dist[j] < min) {
                    min = dist[j];
                    k = j;
                }
            }
            // ���"����k"Ϊ�Ѿ���ȡ�����·��
            flag[k] = true;

            // ������ǰ���·����ǰ������
            // �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
            for (int j = 1; j <= VertexCount; j++) {
                int tmp = Distance(k, j);
                tmp = (tmp == INFINITY ? INFINITY : (min + tmp)); // ��ֹ���
                if (flag[j] == false && (tmp < dist[j])) {
                    dist[j] = tmp;
                    prev[j] = k;
                }
            }
        }
        for (int i = 1; i <= VertexCount; i++) {
            printf("shortest(%d, %d)=%d \t���·��:%d", start, i, dist[i], start);
            if (start != i) {
                cout << "-->";
                print_path(i);
            }
            cout << endl;
        }
        cout << "��������ʼ���(1-200):" << endl;
    }
}