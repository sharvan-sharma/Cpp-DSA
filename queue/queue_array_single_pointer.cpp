#include <iostream>
#include <string>
using namespace std;

//single pointer queue
template <class T>
class SPTQueue{ 
    public:
        int end;
        int size;
        T *arr;
        SPTQueue(int size){
            this->size = size;
            end = -1;
            arr = new T[size];
        }
        ~SPTQueue(){
            delete []arr;
        }
        int enqueue(T v);
        T dequeue();
        int isEmpty();
        int isFull();
};

template <class T>
int SPTQueue<T>::enqueue(T v){
    if(end == (size - 1)){
        return 0;
    }else{
        end++;
        arr[end] = v;
        return 1;
    }
}

template <class T>
T SPTQueue<T>::dequeue(){
    if(end == -1){
        string error = "Underflow";
        throw error;
    }else{
        T v = arr[0];
        for (int j = 0; j < end ;j++){
            arr[j] = arr[j+1];
        }
        end--;
        return v;
    }
}

template <class T>
int SPTQueue<T>::isEmpty(){
    if(end == -1) return 1;
    else return 0;
}

template <class T>
int SPTQueue<T>::isFull(){
    if(end == (size - 1)) return 1;
    else return 0;
}

int main(){
    SPTQueue<int> sq(5);

    int arr[] = {1,2,3,4,5};

    cout << sq.isEmpty() << endl;

    for (int i = 0 ; i<5;i++){
        sq.enqueue(arr[i]);
    }

    cout  << sq.isFull() << endl;

    for (int i = 0 ; i<5;i++){
        cout << sq.dequeue() << ' ';
    }
}

