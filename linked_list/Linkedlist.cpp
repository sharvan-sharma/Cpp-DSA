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
};

template <class T>
class LinkedList{
    public:
        Node<T> *head;
        Node<T> *end;
        LinkedList(){
            end = NULL;
           head = NULL;
        }
        ~LinkedList(){
            delete head;
            delete end;
        }
        void Display();
        void Append(T v);
};

template <class T>
void LinkedList<T>::Display(){
            //initialise p with head
            Node<T> *p = head;
            
            //condition to stop when encounter with NULL
            while(p){
                cout << p->data << ' ';
                
                //update p pointing toward the next node
                p = p->next;
            }
        }

template <class T>
void LinkedList<T>::Append(T v){
    // create new node pointer to Node in heap
    Node<T> *npt = new Node<T>;
    //add data to that Node using the pointer npt(stored in stack)
    npt->data = v;

    //if end is not NULL than add npt to Node's next which is pointed by end 
    //and update the end pointer to npt
    if(end){
        end->next = npt;
        end = npt;
    //update the head and end pointing toward the npt 
    }else{
        head = npt;
        end = npt;
    }
}

int main(){

    LinkedList<int> l;
    l.Append(2);
    l.Append(3);
    l.Append(4);
    l.Append(45);
    l.Display();

}
