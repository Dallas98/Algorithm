#include <bits/stdc++.h>
#include "LLGEN.C"
#include "LLAPP.C"

#include "ELFHASH.C"

#define TABLE_SIZE 10
using namespace std;
Link   *Table;

int CreateTable ( Link **t ) {
    int i;

    *t = (Link *) calloc(TABLE_SIZE, sizeof(Link));
    if (*t == nullptr)
        return (0);

    if (**t != nullptr)      /* is the calloc'd memory == NULL? */
    {
        for (i = 0; i < TABLE_SIZE; i++, t++)
            **t = nullptr;
    }

    return (1);
}
int main() {
    unsigned hash_key;
    struct List *L1;          /* list for hash table entries*/
    CreateTable ( &Table );
    ifstream fin("Lab3test.DAT");
    L1 = CreateLList ( CreateData1,      /* in llapp.c */
                       DeleteData1,      /*     "      */
                       DuplicatedNode1,  /*     "      */
                       NodeDataCmp1 );   /*     "      */
    if ( L1 == nullptr)
    {
        fprintf ( stderr, "Error creating linked list\n" );
        exit ( EXIT_FAILURE );
    }
    char *name,*tele,*age;
    NodeData1 nodeData1{};
    string line;
    string::size_type pos1,pos2;
    while ( getline(fin,line)){
        pos1 = 0;
        pos2 = line.find(',');
        tele = (char *)line.substr(pos1,pos2 - pos1).c_str();
        pos1 = pos2 + 1;
        pos2 = line.find(',',pos1);
        name = (char *)line.substr(pos1,pos2 - pos1).c_str();
        pos1 = pos2 + 1;
        pos2 = line.find(',',pos1);
        age = (char *)line.substr(pos1,pos2 - pos1).c_str();
        nodeData1.age = age;
        nodeData1.name = name;
        nodeData1.tele = tele;
        hash_key = (unsigned int) ElfHash(reinterpret_cast<const unsigned char *>(tele));
        hash_key %= TABLE_SIZE;
        L1->LHead = Table[hash_key];
        Link res = FindNodeAscend(L1,tele);
        if(res== nullptr){
            int add_status = AddNodeAscend(L1,&nodeData1);
            if ( add_status == 0 )      /* an error occurred */
                printf ( "Warning! Error while allocating node.\n" );
        }
        Table[hash_key] = L1->LHead;
    }

    char command;
    char telenum[20];
    cout<<"please input a command(f:find,d:delete,p:print,q:quit):\n";
    while(true){
        cin >> command;
        if(command == 'F' || command == 'f'){
            cin >> telenum;
            telenum[strlen(telenum)] = '\0';
            unsigned pos = ElfHash(reinterpret_cast<const unsigned char *>(telenum));
            pos %= TABLE_SIZE;
            L1->LHead = Table[pos];
            Link res = FindNodeAscend(L1,telenum);
            if(res != nullptr){
                auto* nd1 = (NodeData1*) res->pdata;
                cout << "tele:"<< nd1->tele <<"\tname:" << nd1->name << "\tage:" << nd1->age <<  endl;
            }else{
                cout << "cannot find it!!!" << endl;
            }
        }else if(command == 'D' ||command == 'd'){
            cin >> telenum;
            telenum[strlen(telenum)] = '\0';
            unsigned pos = ElfHash(reinterpret_cast<const unsigned char *>(telenum));
            pos %= TABLE_SIZE;
            L1->LHead = Table[pos];
            Link res = FindNodeAscend(L1,telenum);
            if(res->next== nullptr&&res->prev== nullptr){
                Table[pos] = nullptr;
                cout << "delete it anyway" << endl;
            }
            else if(res){
                DeleteNode(L1,res);
                cout << "delete it anyway" << endl;
            }

        }else if(command=='P' ||command=='p'){
            for(int i = 0;i < TABLE_SIZE;i++){
                L1->LHead = Table[i];
                cout << "Slot : " << i <<endl;
                while(L1->LHead != nullptr){
                    auto* nd1 = (NodeData1*)L1->LHead->pdata;
                    cout << "tele:"<< nd1->tele <<"\tname:" << nd1->name << "\tage:" << nd1->age <<  endl;
                    L1->LHead = L1->LHead->next;
                }
                cout<<endl;
            }
        } else if(command == 'Q' || command=='q'){
            exit(0);

        }
        else{
            cout<<"command is error, please try again"<<endl;
        }
        cout<<"please input a command:\n";
    }
}
