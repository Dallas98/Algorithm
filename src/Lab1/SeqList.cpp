//
// Created by Dallas on 2020/11/18.
//

#include <bits/stdc++.h>

using namespace std;

static int len = 0;
static const int MAX_LENGTH = 20;

struct Node {
    string id;
    string name;
    int age;

    Node() {};
};

Node node[MAX_LENGTH];

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
    int i = 0;
    if (in) {
        while (getline(in, line)) {
            vector<string> v = spilt(line, ',');
            node[i].id = v[0];
            node[i].name = v[1];
            node[i].age = stoi(v[2]);
            i++;
            len++;
        }
    }
}

void print(int i) {
    if (i < 1 || i > len) {
        cout << "cross the border";
    } else {
        cout << node[i - 1].id + "," + node[i - 1].name + "," << node[i - 1].age << endl;
    }

}

bool del(int i) {
    if (len == 0) {
        cout << "the list is emtpy, can't delete" << endl;
        return false;
    } else {
        for (int j = i; j < len; j++) {
            node[j - 1] = node[j];
        }
        len--;
        return true;
    }
}

bool insert(int i, Node n) {
    if (len == MAX_LENGTH) {
        cout << "out of the size, error" << endl;
        return false;
    } else if (i < 1 || i > len) {
        cout << "command error" << endl;
        return false;
    } else {
        for (int j = len; j >= i; j--) {
            node[j] = node[j - 1];
        }
        node[i - 1] = n;
        len++;
        return true;
    }
}


void printList() {
    for (int i = 1; i <= len; i++) {
        cout << "address:" << &node[i] << "\t";
        print(i);
    }
}

void decode(string s) {
    vector<string> v = spilt(s, ',');
    char ch = v[0][0];
    int index = stoi(v[0].substr(1,v[0].length()));
    Node node;
    switch (ch) {
        case 'P':
            print(index);
            break;
        case 'D':
            del(index);
            break;
        case 'I':
            if (v.size() != 4) {
                cout << "command is error" << endl;
                break;
            }
            node.id = v[1];
            node.name = v[2];
            node.age = stoi(v[3]);
            insert(index, node);
            break;
        default:
            cout << "command is error" << endl;

    }
}

int main() {
    readFile();
    printList();
    string terminal;
    cout << "Enter a command:\n";
    while (cin >> terminal) {
        decode(terminal);
        printList();
        cout << "Enter a command:\n";
    }
    return 0;
}



