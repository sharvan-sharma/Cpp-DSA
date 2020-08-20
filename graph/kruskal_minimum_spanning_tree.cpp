#include <iostream>
using namespace std;

void replace(int minheap[][4],int from,int to){

    int temp[4];
    temp[0] = minheap[from][0]; 
    temp[1] =  minheap[from][1]; 
    temp[2] =  minheap[from][2];
    temp[3] =  minheap[from][3];

    minheap[from][0] = minheap[to][0]; 
    minheap[from][1] = minheap[to][1];
    minheap[from][2] = minheap[to][2];
    minheap[from][3] = minheap[to][3];

    minheap[to][0] = temp[0]; 
    minheap[to][1] = temp[1];
    minheap[to][2] = temp[2];
    minheap[to][3] = temp[3];
}



void heapify(int minheap[][4],int L){
    for (int i = (L-1);i>=0;i--){
        int parent = i;
        int lchild = 2*i + 1;
        int rchild = 2*i + 2;
        while(lchild < L && rchild < L){
            if(minheap[lchild][2] < minheap[rchild][2]){
                if(minheap[lchild][2] < minheap[parent][2]){
                    replace(minheap,lchild,parent); 
                    parent = lchild;
                    lchild = 2*parent + 1;
                    rchild = 2*parent + 2;
                }else{
                    break;
                }
            }else{
                if(minheap[rchild][2] < minheap[parent][2]){
               
                    replace(minheap,rchild,parent); 
                    parent = rchild;
                    lchild = 2*parent + 1;
                    rchild = 2*parent + 2;
                }else{
                    break;
                }
            }
        }
    }
}

void delete_heap_element(int minheap[][4],int L){
    replace(minheap,0,L-1);
    heapify(minheap,L-1);
}

int set_find(int arr[],int v){
    while(arr[v] > 0){
        v = arr[v];
    }
    return v;
}

void set_union(int arr[],int v,int u){
    if(arr[u] < arr[v]){
        arr[u] = arr[u] + arr[v];
        arr[v] = u;
    }else{
        arr[v] = arr[v] + arr[u];
        arr[u] = v;
    }
}

void kruskal_minimum_spanning_tree(int minheap[][4],int V,int E){

    int set_arr[V];
    for(int  i = 0 ;i<V; i++ ) set_arr[i] = -1;

    int tree[V-1][3];
    int tree_length = 0;

    int heap_length = E;

    while(tree_length < (V-1) && heap_length >= 0){

        int u_parent = set_find(set_arr,minheap[0][0]-1);
        int v_parent = set_find(set_arr,minheap[0][1]-1);
        
        if(u_parent != v_parent){
            tree[tree_length][0] = minheap[0][0];
            tree[tree_length][1] = minheap[0][1];
            tree[tree_length][2] = minheap[0][2];
            tree_length++;
            minheap[0][3] = 1;
            set_union(set_arr,u_parent,v_parent);
        }
        delete_heap_element(minheap,heap_length);
        heap_length--;
    }

    cout << endl << "minimum spanning tree" << endl;

    for(int  i = 0;i<tree_length;i++){
        cout << "u: " <<tree[i][0]<< " v: "<< tree[i][1] << " cost: " << tree[i][2] << endl;
    }
}


int main(){
    
    // 4 6
    int E,V;
    cin >> V >> E;

    int min_heap[E][4];
    int zero = 0;

    //edges
    // 1 2 10
    // 1 3 5
    // 1 4 3
    // 2 3 2
    // 2 4 9
    // 3 4 4
    for(int i = 0 ; i < E; i++){
        cin >> min_heap[i][0] >> min_heap[i][1] >> min_heap[i][2];
        min_heap[i][3] = 0;
    }

    heapify(min_heap,E);

    kruskal_minimum_spanning_tree(min_heap,V,E);

}