#include <iostream>
using namespace std;

template <class T>
class Node{
    public:
        T value;
        Node *rchild,*lchild;
        char color;
        Node(){
            rchild = lchild = NULL;
            color = 'R';
        }
};

template <class T>
class RedBlackTree{
    public:
        Node<T> *root;
        RedBlackTree(){
            root = NULL;
        }
        void add_node(Node<T> *grand_parent,Node<T> *parent,Node<T> *node_pointer);
        void delete_node(T query);
};


template <class T>
void zig_zig_rotation(Node<T> *pointer,char direction){

    if(direction == 'R'){
        cout << " zig zig RR" << endl; 
        Node<T> *temp = new Node<T>;
        temp->value = pointer->value;
        temp->lchild = pointer->lchild;
        temp->rchild = pointer->rchild->lchild;

        pointer->value = pointer->rchild->value;
        pointer->rchild = pointer->rchild->rchild;
        pointer->lchild = temp;


    }else{
        cout << " zig zig LL" << endl; 
        Node<T> *temp = new Node<T>;
        temp->value = pointer->value;
        temp->rchild = pointer->rchild;
        temp->lchild = pointer->lchild->rchild;

        pointer->value = pointer->lchild->value;
        pointer->lchild = pointer->lchild->lchild;
        pointer->rchild = temp;
    }

}

template <class T>
void zig_zag_rotation(Node<T> *pointer,char direction){
    if(direction == 'R'){
        cout << " zig zag RL" << endl; 
        Node<T> *temp = new Node<T>;
        temp->value = pointer->value;
        temp->lchild = pointer->lchild;
        temp->rchild = pointer->rchild->lchild->lchild;

        pointer->value = pointer->rchild->lchild->value;
        pointer->rchild->lchild = pointer->rchild->lchild->rchild;
        pointer->lchild = temp;


    }else{
        cout << " zig zig LR" << endl; 
        Node<T> *temp = new Node<T>;
        temp->value = pointer->value;
        temp->rchild = pointer->rchild;
        temp->lchild = pointer->lchild->rchild->rchild;

        pointer->value = pointer->lchild->rchild->value;
        pointer->lchild->rchild = pointer->lchild->rchild->lchild;
        pointer->rchild = temp;
    }
}

template <class T>
void RedBlackTree<T>::add_node(Node<T> *grand_parent,Node<T> *parent,Node<T> *node_pointer){


    if(parent){
        if(parent->value > node_pointer->value){
            if(parent->lchild){
                this->add_node(parent,parent->lchild,node_pointer);
            }else{
                parent->lchild = node_pointer;
            }
        }else if(parent->value < node_pointer->value){
            if(parent->rchild){
                this->add_node(parent,parent->rchild,node_pointer);
            }else{
                parent->rchild = node_pointer;
            }
        }else{
            return;   
        }

        if(grand_parent){
            Node<T> *uncle = grand_parent->rchild == parent? grand_parent->lchild:grand_parent->rchild;

            char parent_flag = grand_parent->rchild == parent? 'R':'L';
            char child_flag = parent->value > node_pointer->value? 'L':'R';

            if(uncle && uncle->color == 'R' && parent->color == 'R'){
                cout << "coloring" << endl;
                uncle->color = 'B';
                parent->color = 'B';
                if(grand_parent != root){
                    grand_parent->color = 'R';
                }

            }else if((!uncle || (uncle->color == 'B')) && parent->color == 'R'){
                //rotation
                if(parent_flag == child_flag){
                    zig_zig_rotation(grand_parent,parent_flag);
                }else{
                    zig_zag_rotation(grand_parent,parent_flag);
                }
            }
        }

    }else{
         node_pointer->color = 'B';
         root = node_pointer;
    }
}

template <class T>
void delete_node(T query){
 return;   
}

template <class T>
void inorder(Node<T> *pointer){
    if(pointer){
        inorder(pointer->lchild);
        cout << pointer->value << " ";
        inorder(pointer->rchild);   
    }
}

int main(){

    RedBlackTree<int> *tree = new RedBlackTree<int>;

    int N;
    cin >> N;

    //adding 10 keys 10,20,30,50,40,60,70,80,4,8
    while(N--){
        Node<int> *node_pointer = new Node<int>;
        int value;
        cin >> value;
        node_pointer->value = value;

        tree->add_node(NULL,tree->root,node_pointer);
    }

    cout << endl << "inorder traversal of tree" << endl;
    inorder(tree->root);
}

