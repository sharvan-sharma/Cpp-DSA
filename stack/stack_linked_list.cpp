#include <iostream>
using namespace std;

template <class T>
class Node{
    public:
        Node *next;
        T data;
        Node(){
            next = NULL;
        }
        Node(T data){
            next = NULL;
            this->data = data;
        }
};

template <class T>
class Stack{
    public:
        Node<T> *top;
        Stack(){
            top = NULL;
        }
        ~Stack(){
            delete top;
        }
        bool isEmpty();
        bool isFull();
        int push(T v);
        T pop();
};

template <class T>
bool Stack<T>::isEmpty(){
    if(top == NULL){ return true;}
    else { return false;}
}

template <class T>
bool Stack<T>::isFull(){
    Node<T> *pt  = new Node<T>;
    if(pt){
        delete pt;
        return false;
    }else{
        return true;
    }
}

template <class T>
int Stack<T>::push(T v){
    Node<T> *pt  = new Node<T>;
    if(pt){
        pt->data = v;
        if(top){
            pt->next = top;
            top = pt;
        }else{
            top = pt;
        }
        return 1;
    }else{
        return 0;
    }
}

template <class T>
T Stack<T>::pop(){
    if(top){
        Node<T> *pt = top;
        top = top->next;
        T data_pt = pt->data;
        delete pt;
        return data_pt;
    }else{
        string st = "underflow";
        throw st;
    }
}

int main(){
    Stack<int> st;

    cout << st.isEmpty() << endl;

    for (int i = 0;i<10;i++){
        st.push(i);
    }

    cout << st.isFull() << endl;

    for (int i = 0;i<10;i++){
        cout << st.pop() << endl;
    }
}