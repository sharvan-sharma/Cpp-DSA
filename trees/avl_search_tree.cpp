#include <iostream>
using namespace std;

template <class T>
class Node{
    public:
        T value;
        Node *rchild,*lchild;
        int height;
        Node(){
            rchild = lchild = NULL;
            height = 1;
        }
};

template <class T>
class AVL{
    public:
        Node<T> *root;
        AVL(){
            root = NULL;
        }
        void add_node(Node<T> *parent,Node<T> *node_pointer);
        void delete_node(T query);
};

template <class T>
int NodeHeight(Node<T> *pointer){
    int hl,hr;

    hl = pointer && pointer->lchild?pointer->lchild->height:0;
    hr = pointer && pointer->rchild?pointer->rchild->height:0;

    return hl > hr ? hl+1:hr+1;
}

template <class T>
int BalanceFactor(Node<T> *pointer){
    int hl,hr;

    hl = pointer && pointer->lchild?pointer->lchild->height:0;
    hr = pointer && pointer->rchild?pointer->rchild->height:0;

    return hl-hr;
}

template <class T>
void LLRotation(Node<T> *p){
    Node<T> *temp = new Node<T>;
    temp->value = p->value;
    temp->rchild = p->rchild;

    p->value = p->lchild->value;
    temp->lchild = p->lchild->rchild;
    p->lchild = p->lchild->lchild;

    p->rchild = temp;

}

template <class T>
void LRRotation(Node<T> *p){

    Node<T> *temp = new Node<T>;
    temp->value = p->value;
    temp->rchild = p->rchild;

    p->value = p->lchild->rchild->value;
    temp->lchild = p->lchild->rchild->rchild;
    p->lchild->rchild = p->lchild->rchild->lchild;

    p->rchild = temp;

}

template <class T>
void RRRotation(Node<T> *p){

    Node<T> *temp = new Node<T>;
    temp->value = p->value;
    temp->lchild = p->lchild;

    p->value = p->rchild->value;
    temp->rchild = p->rchild->lchild;
    p->rchild = p->rchild->rchild;

    p->lchild = temp;

}

template <class T>
void RLRotation(Node<T> *p){
    Node<T> *temp = new Node<T>;
    temp->value = p->value;
    temp->lchild = p->lchild;

    p->value = p->rchild->lchild->value;
    temp->rchild = p->rchild->lchild->lchild;
    p->rchild->lchild = p->rchild->lchild->rchild;

    p->lchild = temp;

}

template <class T>
void AVL<T>::add_node(Node<T> *parent,Node<T> *node_pointer){

    if(parent){

        if(parent->value > node_pointer->value){
            if(parent->lchild){
                this->add_node(parent->lchild,node_pointer);
            }else{
                parent->lchild = node_pointer;
            }
        }else if(parent->value < node_pointer->value){
            if(parent->rchild){
                this->add_node(parent->rchild,node_pointer);
            }else{
                parent->rchild = node_pointer;
            }
        }else{
            return;
        }

        parent->height = NodeHeight(parent);

        if(BalanceFactor(parent) == 2 && BalanceFactor(parent->lchild) == 1){
            LLRotation(parent);
        }else if(BalanceFactor(parent) == 2 && BalanceFactor(parent->lchild) == -1){
            LRRotation(parent);
        }else if(BalanceFactor(parent) == -2 && BalanceFactor(parent->rchild) == -1){
            RRRotation(parent);
        }else if(BalanceFactor(parent) == -2 && BalanceFactor(parent->rchild) == 1){
            RLRotation(parent);
        }

        return;

    }else{
        root = node_pointer;
    }

}


// left nearest neighbor of node
template <class T>
Node<T> * find_left_nearest(Node<T> * pointer){
    while(pointer->rchild){
        pointer = pointer->rchild;
    }
    return pointer;
}

// right nearest neighbor of node
template <class T>
Node<T> * find_right_nearest(Node<T> * pointer){
    while(pointer->lchild){
        pointer = pointer->lchild;
    }
    return pointer;
}

template <class T>
void AVL<T>::delete_node(T query){
        Node<T> *pointer,*tail_pointer;
        pointer = root;
        tail_pointer = NULL;
        while(pointer){
            if(pointer->value > query){
                tail_pointer = pointer;
                pointer = pointer->lchild;
            }else if(pointer->value < query){
                tail_pointer = pointer;
                pointer = pointer->rchild;
            }else{
                if(pointer->lchild){
                    Node<T> *left_nearest = find_left_nearest(pointer->lchild);
                    this->delete_node(left_nearest->value);
                    pointer->value = left_nearest->value;
                    pointer->height = NodeHeight(pointer);
                    return;
                }else if(pointer->rchild){
                    Node<T> *right_nearest = find_right_nearest(pointer->rchild);
                    this->delete_node(right_nearest->value);
                    pointer->value = right_nearest->value;
                    pointer->height = NodeHeight(pointer);
                    return;
                }else{
                    if(tail_pointer){
                        if(pointer == (tail_pointer->lchild)){
                            tail_pointer->lchild = NULL;
                        }else{
                            tail_pointer->rchild = NULL;
                        }
                    }else{
                        root = NULL;
                        return;
                    }

                    tail_pointer->height = NodeHeight(tail_pointer);

                    if(BalanceFactor(tail_pointer) == 2 && BalanceFactor(tail_pointer->lchild) == 1){
                        cout<<"L 1" <<endl;
                        LLRotation(tail_pointer);
                    }else if(BalanceFactor(tail_pointer) == 2 && BalanceFactor(tail_pointer->lchild) == -1){
                        cout<<"L -1" <<endl;
                        LRRotation(tail_pointer);
                    }else if(BalanceFactor(tail_pointer) == 2 && BalanceFactor(tail_pointer->lchild) == 0){
                        cout<<"L 0" <<endl;
                        LLRotation(tail_pointer);
                    }else if(BalanceFactor(tail_pointer) == -2 && BalanceFactor(tail_pointer->rchild) == -1){
                        cout<<"R 1" <<endl;
                        RRRotation(tail_pointer);
                    }else if(BalanceFactor(tail_pointer) == -2 && BalanceFactor(tail_pointer->rchild) == 1){
                        cout<<"R -1" <<endl;
                        RLRotation(tail_pointer);
                    }else if(BalanceFactor(tail_pointer) == -2 && BalanceFactor(tail_pointer->rchild) == 0){
                        cout<<"R 0" <<endl;
                        RRRotation(tail_pointer);
                    }

                    return;

                }
            }
        }
}

template <class T>
void inorder(Node<T> *node_pointer){
    if(node_pointer){
        inorder(node_pointer->lchild);
        cout << node_pointer->value << " ";
        inorder(node_pointer->rchild);
    }
}

int main(){

    AVL<int> *tree = new AVL<int>;

    int N;
    cin >> N;

    //adding nodes 30,35,37,28,18,25,33 in this order
    while(N--){
        Node<int> *node_pointer = new Node<int>;

        int value;
        cin >> value;

        node_pointer->value = value;

        tree->add_node(tree->root,node_pointer);
    }

    cout << endl << "tree root value " << tree->root->value << endl;

    cout << endl << "inorder traversal" << endl;
    inorder(tree->root);

    cout.setf(ios::boolalpha);
    cout << endl << "deleting node with value 40" << endl;
    tree->delete_node(40);
    cout << endl << "inorder traversal after deleteing node 40" << endl;
    inorder(tree->root);

}