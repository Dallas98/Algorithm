//
// Created by Dallas on 2020/11/18.
//

#include <bits/stdc++.h>

using namespace std;

static int len = 0;

struct LinkNode {
    string id;
    string name;
    int age;
    LinkNode *next;

    LinkNode() {};

    LinkNode(const string &id, const string &name, int age, LinkNode *next) :
            id(id), name(name), age(age), next(next) {}
};

LinkNode *head = new LinkNode();

vector<string> spilt(string s, char ch) {
    s.push_back(ch);
    int start = 0, end = 0, size = s.size();
    vector<string> vs;

    for (int i = 0; i < size; i++) {
        if (s[i] == ch) {
            end = i;
            string temp = s.substr(start, end - start);
            start = i + 1;
            vs.push_back(temp);
        }
    }
    return vs;
}


void readFile() {
    ifstream in("resources/Lab1test.DAT");
    string line;
    head->next = nullptr;
    if (in) {
        while (getline(in, line)) {
            vector<string> v = spilt(line, ',');
            LinkNode *p = new LinkNode(v[0], v[1], stoi(v[2]), head->next);
            head->next = p;
            len++;
        }
    }
}

void print(LinkNode *p) {
    cout << p->id << "," << p->name << "," << p->age << endl;
}

void printLinkList() {
    for (LinkNode *p = head->next; p; p = p->next) {
        cout <<"address:"<< p <<"\tnext_value:"<<p->next<<'\t' ;
        print(p);
    }
}

void printId(int index) {
    if (index < 1 || index > len) {
        cout << "out of range" << endl;
        return;
    }
    LinkNode *p = head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    print(p);
}

void delId(int index) {
    if (index < 1 || index > len) {
        cout << "out of range" << endl;
        return;
    }
    LinkNode *p = head;
    LinkNode *q = nullptr;
    for (int i = 1; i < index; i++) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    delete (q);
    len--;
}

void insert(int index, LinkNode *node) {
    if (index < 1 || index > len + 1) {
        cout << "out of range" << endl;
        return;
    }
    LinkNode *p=head;
    for (int i = 1; i < index; i++) {
        p=p->next;
    }
    node->next=p->next;
    p->next=node;
    len++;
}

void decode(string s) {
    vector<string> v = spilt(s, ',');
    char ch = v[0][0];
    int index = stoi(v[0].substr(1,v[0].length()));
    LinkNode *p;
    switch (ch) {
        case 'P':
            printId(index);
            break;
        case 'D':
            delId(index);
            break;
        case 'I':
            if (v.size() != 4) {
                cout << "command is error" << endl;
                break;
            }
            p = new LinkNode(v[1], v[2], stoi(v[3]), nullptr);
            insert(index, p);
            break;
        default:
            cout << "command is error" << endl;


    }
}

int main() {
    readFile();
    printLinkList();
    string terminal;
    cout << "Enter a command:\n";
    while (cin >> terminal) {
        decode(terminal);
        printLinkList();
        cout << "Enter a command:\n";
    }
    return 0;

}