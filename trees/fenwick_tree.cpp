#include <iostream>
#include <math.h>
using namespace std;

//sum in range queies

  
unsigned int onesComplement(unsigned int n) 
{  
   int number_of_bits = floor(log2(n))+1; 
   return ((1 << number_of_bits) - 1) ^ n; 
} 

int getNext(int num){
    int s1 = onesComplement(num);
    int s2 = s1+1;
    int and_num = s2 & num;
    return and_num + num;
}

int getParent(int num){
    int s1 = onesComplement(num);
    int s2 = s1+1;
    int and_num = s2 & num;
    return num - and_num;
}

class FenwickTree{
    public:
        int *pointer;
        int length;
        FenwickTree(int N){
            pointer = new int[N+1];
            length = N+1;
            for(int  i = 0;i<length;i++){
                pointer[i] = 0;
            }
        }
        void insert(int index,int value);
        void update(int value,int start,int end);
        int read(int start,int end);
};

void FenwickTree::insert(int index,int value){
    int next = index;
    while(next < this->length && next > 0){
        this->pointer[next] = this->pointer[next] + value;
        next = getNext(next);
    }

}

void FenwickTree::update(int start,int end,int value){
    for (int i = start ;i<=end;i++){
        int next = i;
        while(next > 0 && next < this->length){
            this->pointer[next] = this->pointer[next] + value;
            next = getNext(next);
        }
    }
}

int FenwickTree::read(int start,int end){
    int parent = start-1;
    int sum1 = 0;
    while(parent > 0 && parent < this->length){
        sum1 = sum1 + this->pointer[parent];
        parent = getParent(parent);
    }

    parent = end;
    int sum2 = 0;
    while(parent > 0 && parent < this->length){
        sum2 = sum2 + this->pointer[parent];
        parent = getParent(parent);
    }

    return sum2 - sum1;
}

int main(){

    int N,M;cin >> N >> M;
    
    FenwickTree *tree = new FenwickTree(N);
    //N = 10 
    //arr = 3 2 -1 6 5 4 -3 3 7 2 3
    for(int i = 0; i < N ;i++){
        int value;cin >> value;
        tree->insert(i+1,value);
    }


    //M = 4
    // 0 5
    // 0 9
    // 0 7
    // 5 7
    for(int i = 0;i < M;i++){
        char q_type[10];
        cin >> q_type;
        if(q_type[0] == 'r'){
            int start,end;
            cin >> start >> end;
            cout << tree->read(start,end)<<endl;
        }else{
            int start,end,value;
            cin >> start >> end >> value;
            tree->update(start,end,value);
        }
    }

    //tree after all queries
    cout << "tree after all queries" << endl;
    for(int i = 0;i< tree->length;i++){
        cout << tree->pointer[i] << ' ';
    }

}