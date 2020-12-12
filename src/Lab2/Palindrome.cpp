#include <bits/stdc++.h>
#include "LLAPP.H"
#include "LLGEN.H"

using namespace std;

struct List *L;   /* two different linked lists */
bool checkChar(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void clear() {
    while (L->LCount > 0) {
        DeleteNode(L, L->LHead);
    }
}

bool check() {
    Link begin, end;
    begin = L->LHead;
    end = L->LTail;
    bool flag = true;
    while (begin != end) {
        if (NodeDataCmp1(begin->pdata, end->pdata)) {
            flag = false;
            break;
        }
        begin = begin->next;
        end = end->prev;
    }
    return flag;
}

void a() {

    char word[2];
    word[1] = 0;
    word[0] = 0;
    while (checkChar(word[0] = getchar())) {
        //push
        if (!AddNodeAtHead(L, word))
            fprintf(stderr,
                    "Warning! Error while adding node to L.\n");
        cout << L->LHead->pdata << endl;
    }
    cout << check() << endl;
    clear();
}

int main() {
    L = CreateLList(CreateData1, DeleteData1, DuplicatedNode1, NodeDataCmp1);
    int t = 10;
    if (L == nullptr) {
        fprintf(stderr, "error creating linked list\n");
    }

    while (t-- > 0) {
        a();
    }
}