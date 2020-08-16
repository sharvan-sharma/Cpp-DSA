#include <iostream>
using namespace std;


// node class

template <class T>
class Node{
    public:
        T value;
        Node *rchild;
        Node *lchild;
        Node(){
            rchild = NULL;
            lchild = NULL;
        }
};

// BST class

template <class T>
class BST{
    public:
        Node<T> *root;
        BST(){
            root = NULL;
        }
        void add_node(Node<T> *pt);
        bool search(T query);
        void delete_node(T query);
    
};

//Insertion in BST
template <class T>
void BST<T>::add_node(Node<T> *node_pointer){

    if(!root){
        root = node_pointer;
    }else{
        Node<T> *pointer,*tail_pointer;
        tail_pointer = NULL;
        pointer = root;

        while(pointer){
            if(pointer->value < node_pointer->value){
                tail_pointer = pointer;
                pointer = pointer->rchild;
                if(!pointer){
                    tail_pointer->rchild = node_pointer;
                    return;
                }
            }else if(pointer->value > node_pointer->value){
                tail_pointer = pointer;
                pointer = pointer->lchild;
                if(!pointer){
                    tail_pointer->lchild = node_pointer;
                    return;
                }
            }else{
                return;
            }
        }
    }

}

//Search in BST
template <class T>
bool BST<T>::search(T query){
    Node<T> *pointer;
    pointer = root;
    while(pointer){
        if(pointer->value == query){
            return true;
        }else{
            pointer = ((pointer->value) > query) ? pointer->lchild : pointer->rchild;
        }
    }
    return false;
}

// left nearest neighbor of node
template <class T>
Node<T> * find_left_closest(Node<T> * pointer){
    while(pointer->rchild){
        pointer = pointer->rchild;
    }
    return pointer;
}

// right nearest neighbor of node
template <class T>
Node<T> * find_right_closest(Node<T> * pointer){
    while(pointer->lchild){
        pointer = pointer->lchild;
    }
    return pointer;
}

//delete node
template <class T>
void BST<T>::delete_node(T query){
    Node<T> *pointer,*tail_pointer;
    tail_pointer = NULL;
    pointer = root;
    
    while(pointer){

        if(pointer->value == query){
            if(!pointer->lchild && !pointer->rchild){
                if(!tail_pointer){
                    root = NULL;
                }else{
                    if(tail_pointer->lchild == pointer){
                        tail_pointer->lchild = NULL;
                    }else{
                        tail_pointer->rchild = NULL;
                    }
                }
                return;
            }else if(pointer->lchild){
                Node<T> *left_closest = find_left_closest(pointer->lchild);
                this->delete_node(left_closest->value);
                pointer->value = left_closest->value;
                return;
            }else{
                Node<T> *right_closest = find_right_closest(pointer->rchild);
                this->delete_node(right_closest->value);
                pointer->value = right_closest->value;
                return;
            }
        }else{
            tail_pointer = pointer;
            pointer = ((pointer->value) > query) ? pointer->lchild : pointer->rchild;
        }
    }
}

// preorder
template <class T>
void preorder(Node<T> *node_pointer){
    if(node_pointer){
        cout << node_pointer->value << " ";
        preorder(node_pointer->lchild);
        preorder(node_pointer->rchild);
    }
}

// inorder
template <class T>
void inorder(Node<T> *node_pointer){
    if(node_pointer){
        inorder(node_pointer->lchild);
        cout << node_pointer->value << " ";
        inorder(node_pointer->rchild);
    }
}

// postorder
template <class T>
void postorder(Node<T> *node_pointer){
    if(node_pointer){
        postorder(node_pointer->lchild);
        postorder(node_pointer->rchild);
        cout << node_pointer->value << " ";
    }
}


int main(){

    //tree in heap
    BST<int> *tree = new BST<int>;

    //number of nodes
    int N;
    cin >> N;

    // adding nodes one by one 30,25,35,18,28,33,37
    while(N--){
        Node<int> *node_pointer = new Node<int>;

        int value;
        cin >> value;
        node_pointer->value = value;

        // add node
        tree->add_node(node_pointer);
    }

    //traversal
    cout << "preorder -"<< endl;
    preorder(tree->root);
    cout << endl << "inorder -"<< endl;
    inorder(tree->root);
    cout  << endl << "postorder -"<< endl;
    postorder(tree->root);
    
    //serach
    cout.setf(ios::boolalpha);
    cout << endl << "search 43 " << tree->search(43) << endl;

    //deleteion of node
    tree->delete_node(25);
    cout << endl << "inorder after deleteing node with value 25" << endl;
    inorder(tree->root);

}