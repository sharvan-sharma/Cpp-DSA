#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node{
    public:
        char value;
        int exist_count;
        vector<Node *> children;
        Node(){
            exist_count = 0;
        }
};

class Trie{
    public:
        Node *root;
        Trie(){
            root = new Node;
            root->value = '-';
        }
        void addNode(string st);
        bool find(string query);
        void deleteNode(string query);
};

void Trie::deleteNode(string query){
    int length = query.length();
    int stack[length];
    vector<Node *> pointer_stack;
    int top = -1;
    Node *pointer = root;
    for(int i = 0;i<length;i++){
        int size = pointer->children.size();
        int check = 0;
        for(int j = 0;j<size;j++){
            if(pointer->children[j]->value == (char)query[i]){
                pointer_stack.push_back(pointer);
                top++;
                stack[top] = j;
                pointer = pointer->children[j];
                check = 1;
                break;
            }
        }
        if(check == 0){
            return;   
        }
    }
    
    if(pointer->exist_count > 1){
        pointer->exist_count--;
        return;
    }else if(pointer->exist_count == 1){
        pointer->exist_count--;
        int children_size = pointer->children.size();
        while(children_size == 0 && pointer->exist_count == 0 && top != -1){
            // cout << "exist_count " << pointer->value <<' '<< pointer->exist_count << endl;
            pointer = pointer_stack.back();
            pointer->children.erase(pointer->children.begin()+stack[top]);
            top--;
            pointer_stack.pop_back();
            children_size = pointer->children.size();
        }
    }
}

bool Trie::find(string query){
    int length = query.length();
    Node *pointer = root;
    for(int i = 0 ;i<length;i++){
        int size = pointer->children.size();
        int check = 0;
        for(int j = 0;j<size;j++){
            if(pointer->children[j]->value == (char)query[i]){
                pointer = pointer->children[j];
                check = 1;
                break;
            }
        }
        if(check == 0){
            return false;   
        }
    }
    if(pointer->exist_count > 0){
        return true;
    }else{
        return false;
    }
}

void Trie::addNode(string st){
    int length = st.length();

    Node *pointer = root;

    for(int i = 0 ;i<length;i++){
        int size = pointer->children.size();
        int check = 0;
        for(int j = 0;j<size;j++){
            if(pointer->children[j]->value == (char)st[i]){
                pointer = pointer->children[j];
                check = 1;
                break;
            }
        }

        if (check == 0){
            Node *node = new Node;
            node->value = (char)st[i];
            pointer->children.push_back(node);
            pointer = node;
        }
    }

    pointer->exist_count++;
}

int main(){
    // {'ppsst','prst','stdi','nprq'}
    // search prst ,prs, td and delete ppsst and again search for ppsst

    //new Trie
    Trie *trie = new Trie;

    int N; cin >> N;

    for (int i = 0;i < N;i++){
        string st; cin >> st;
        trie->addNode(st);
    }

    int M;cin >> M;
    string array[M];

    for(int i = 0;i < M;i++){
        string query; cin >> query;
        array[i] = query;
    }

    cout.setf(ios::boolalpha);
    cout << endl << "Search Results" <<endl;
    for(int i = 0;i < M;i++){
        cout << "search query '" << array[i] << "' exists : " << (bool)trie->find(array[i]) << ' ';
    }

    cout << endl;

    cout << endl << "deleting 'ppsst'" << endl;
    string del_query = "ppsst";
    trie->deleteNode(del_query);
    
    cout << endl << "searching for ppsst"<< endl;
    cout << "search query '" << del_query << "' exists : " << (bool)trie->find(del_query);

}