#include <iostream>
#include <string>
using namespace std;

template <class T>
class CircularQueue{
    public:
        int front;
        int rear;
        int size;
        T *arr;
        CircularQueue(int size){
            arr = new T[size];
            this->size = size;
            front = -1;
            rear = -1;
        } 
        ~CircularQueue(){
            delete []arr;
        }
        int enqueue(T v);
        T dequeue();
};

template <class T>
int CircularQueue<T>::enqueue(T v){
    if (rear == -1 && front == -1){
        rear++;
        arr[rear] = v; 
        return 1;
    }else if(((rear+1)%size) != (front%size)){
        rear++;
        rear = rear%size;
        arr[rear] = v;
        return 1;
    }else{
        return 0;
    }
}

template <class T>
T CircularQueue<T>::dequeue(){
    if((front%size) == (rear%size)){
        string error = "underflow";
        throw error;
    }else{
        front++;
        front = front%size;
        return arr[front];
    }
}

int main(){

    CircularQueue<int> cq(5);

    //add 0,1,2,3,4 in queue

    for(int i = 0;i<5;i++){
        cq.enqueue(i);
    };

    //remove first two _,_,2,3,4;

    for (int i =0;i<2;i++){
        cout << cq.dequeue() << ' ';
    }

    //add 7,8; queue became 7,_,2,3,4;
    cq.enqueue(7);
    // 8 is not added because we make one vacant space to differentiate between empty and full condition
    int e = cq.enqueue(8);
    cout << endl << "8 is added:" << e << endl;

    //remove all
    for(int i = 0;i<4;i++){
        cout << cq.dequeue() << ' ';
    }
}