//
// Created by 99025 on 2021/1/3.
//

#include <iostream>
using namespace std;

#include "Graph.h"

int main(){
    GraphLinkedTable *graph =new GraphLinkedTable();
    graph->BuildGraph();
    graph->Dijkstra();
}

