#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack{
    public:
        int top;
        int size;
        T *p;
        Stack(int size){
            top = -1;
            this->size = size;
            p = new T[size];
        }
        ~Stack(){
            delete []p;
        }
        bool isEmpty();
        bool isFull();
        int push(T v);
        T pop();
};

template <class T>
bool Stack<T>::isEmpty(){
    if (top == -1) return true;
    else return false;
}

template <class T>
bool Stack<T>::isFull(){    
    if (top == (size-1)) return true;
    else return false;
}

template <class T>
int Stack<T>::push(T v){
    if (top == (size-1)){
        return 0;
    }else{
        p[top+1] = v;
        top++;
        return 1;
    }
}

template <class T>
T Stack<T>::pop(){
    if (top == -1){
        string st = "underflow";
        throw st;
    }else{
        T v = p[top];
        top--;
        return v;
    }
}

int main(){
    int N;
    cin >> N;
    Stack<int> st(N);

    cout << st.isEmpty();
    
    int v;
    for (int i = 0 ;i< N;i++){
        cin >> v;
        st.push(v);
    }

    cout << st.isFull();

    for (int i = 0 ;i< N;i++){
        cout << st.pop() << ' ';
    }

    try{
        cout << st.pop() << ' ';
    }catch(string e){
        cout << e;
    }
}
