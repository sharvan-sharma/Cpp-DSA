#include <iostream>
#include <string>
using namespace std;

template <class T>
class DPTQueue{
    public:
        int start;
        int end;
        int size;
        T *arr;
        DPTQueue(int size){
            this->size = size;
            start = end = -1;
            arr = new T[size];
        }
        ~DPTQueue(){
            delete []arr;
        }
        int isFull(){
            if(end == (size-1)) return 1;
            else return 0;
        }
        int isEmpty(){
            if(start == -1) return 1;
            else return 0;
        }
        int enqueue(T v);
        T dequeue();
};

template <class T>
int DPTQueue<T>::enqueue(T v){
    if(end == (size-1)){
        return 0;
    }else{
        end++;
        arr[end] = v;
        return 1;
    }
}

template <class T>
T DPTQueue<T>::dequeue(){
    if(end == -1 || end == start){
        string error = "Underflow";
        throw error;
    }else{
        start++;
        T v = arr[start];
        return v;
    }
}

int main(){
    DPTQueue<int> dq(5);

    int arr[] = {1,2,3,4,5};

    cout << dq.isEmpty() << endl;

    for(int i = 0;i<5;i++){
        dq.enqueue(arr[i]);
    }

    cout << dq.isFull() << endl;

    for(int i = 0;i < 5;i++){
        cout << dq.dequeue() << ' ';
    }
}