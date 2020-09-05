#include <iostream>
#include <math.h>
using namespace std;


class Node{
    public:
        int value;
        int start;
        int end;
};

class SegmentTree{
    public:
        Node *tree;
        Node *lazy;
        int end;
        void create(int N,int arr[]);
        int read(int parent,int start,int end);
        void update(int parent,int initial,int final,int value);
};

void SegmentTree::create(int N,int arr[]){
    double logN = log2((double)N);
    double logN_ceil = ceil(logN);

    int L,start;
    L = pow(2.0,logN_ceil+1) - 1; //2^4
    start = pow(2.0,logN_ceil) - 1;
    this->tree = new Node[L];
    this->lazy = new Node[L];
    for(int i = 0;i<(start+N);i++){
        if(i >= start){
            this->tree[i].value = arr[i-start];
            this->tree[i].start = i-start;
            this->tree[i].end  = i-start;
            this->lazy[i].value = 0;
            this->lazy[i].start = i-start;
            this->lazy[i].end  = i-start;
            
        }else{
            this->tree[i].value = -1;
        }
    }

    this->end = start+N-1;
    int parent,rchild,lchild;
    for(int  i = (start-1);i>=0;i--){
        parent = i;
        lchild = 2*i + 1;
        rchild = 2*i + 2;
        if(lchild <= end ){
            if(rchild <= end){
                int greater = this->tree[lchild].value > this->tree[rchild].value ? lchild:rchild;
                this->tree[parent].value  = this->tree[greater].value;
                this->tree[parent].start = this->tree[lchild].start;
                this->tree[parent].end = this->tree[rchild].end;
            }else{
                this->tree[parent].value  = this->tree[lchild].value;
                this->tree[parent].start = this->tree[lchild].start;
                this->tree[parent].end = this->tree[lchild].end;
            }
        }
        this->lazy[parent].value = 0;
        this->lazy[parent].start = this->tree[parent].start;
        this->lazy[parent].end = this->tree[parent].end;
    }


}

int larger(int a,int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int SegmentTree::read(int parent,int start,int final){
    if(parent <= this->end){
        //nooverlap
        if(start > this->tree[parent].end || end < this->tree[parent].start){
            return -1;
        //partial overlap
        }else{
            //full overlap
            if(start <= this->tree[parent].start && final >= this->tree[parent].end){
                this->tree[parent].value = this->tree[parent].value + this->lazy[parent].value;
                this->lazy[parent].value = 0;
                return this->tree[parent].value;
            }else{
                int lchild,rchild;
                lchild = (2*parent)+1;
                rchild = (2*parent)+2;
                if (lchild <= this->end){
                    this->lazy[lchild].value = this->lazy[lchild].value + this->lazy[parent].value;
                    if(rchild <= this->end){
                        this->lazy[rchild].value = this->lazy[rchild].value + this->lazy[parent].value;
                    }
                }
                this->tree[parent].value = this->tree[parent].value + this->lazy[parent].value;
                this->lazy[parent].value = 0;
                return larger(this->read(lchild,start,final),this->read(rchild,start,final));
            }
        }
    }else{
        return -1;
    }
}

void SegmentTree::update(int parent,int initial,int final,int value){
if(parent <= this->end){
    if(initial > this->lazy[parent].end || final < this->lazy[parent].start){
        return;
    }else{
        int  lchild,rchild;
        lchild = (2*parent)+1;
        rchild = (2*parent)+2;
        if(initial <= this->lazy[parent].start && final >= this->lazy[parent].end){
            this->tree[parent].value = this->tree[parent].value + value;
            if (lchild <= this->end){
                this->lazy[lchild].value = this->lazy[lchild].value + value;
                if(rchild <= this->end){
                    this->lazy[rchild].value = this->lazy[rchild].value + value;
                }
            }
        }else{
            if (lchild <= this->end){
                this->update(lchild,initial,final,value);
                if(rchild <= this->end){
                    this->update(rchild,initial,final,value);
                    this->tree[parent].value = larger(this->tree[rchild].value,this->tree[lchild].value);
                }else{
                    this->tree[parent].value = this->tree[lchild].value;
                }
            }
        }
    }
}
}

// implementing max_range query
int main(){
    
    int N; cin >> N;
    // arr = 4,5,6,72,3,44,38,52
    int arr[N];
    for(int i = 0;i<N;i++){
        cin >> arr[i];
    }

    SegmentTree *sgTree = new SegmentTree;
    sgTree->create(N,arr);

    cout << "segment Tree -> " << endl;
    for(int  i = 0;i <= sgTree->end;i++){
        cout << sgTree->tree[i].value << ' ';
    }


    cout << endl << "-------------------------"<<endl;


    cout << "lazy tree -> initial" << endl;
    for(int  i = 0;i <= sgTree->end;i++){
        cout << sgTree->lazy[i].value << ' ';
    }

    cout << endl << "Enter the Number of Queries" << endl;
    //7
    int M ;cin >> M;
    cout << "Enter read queries in format :read a b Note:a <= b" << endl;
    cout << "Enter update queries in format :update a b v Note:a <= b" << endl;
    //read 0 4  ::result 72
    //read 2 5  ::result 72
    //read 4 6  ::result 44
    //update 1 5 4 
    //update 2 4 3
    //read 2 5  ::result 79
    //read 4 4  ::result 10
    for(int i = 0;i< M;i++){
        cout << "Enter Query : ";
        char query_type[10]; cin >> query_type;
         
        if(query_type[0] == 'r'){
            int a,b; cin >> a >> b;
            cout << "Result for Query " << a << ' ' << b << " is :" << sgTree->read(0,a,b) << endl;
        }else{
            int a,b,v; cin >> a >> b >> v;
            sgTree->update(0,a,b,v);
        }
    }

    cout << endl << "lazy tree -> final" << endl;
    for(int  i = 0;i <= sgTree->end;i++){
        cout << sgTree->lazy[i].value << ' ';
    }


}