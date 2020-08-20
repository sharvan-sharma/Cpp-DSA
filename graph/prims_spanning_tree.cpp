#include <iostream>
using namespace std;


int search(int arr[],int l,int v){
    for(int i = 0;i<l;i++){
        if(arr[i] == v){
            return 1;
        }
    }
    return 0;
}

void prims_minimum_spanning_tree(int arr[][4],int V,int E){

    int resarr[V-1][3];
    int resarr_length = 0;

    int vertex[V];
    int vertex_length = 0;

    
    int u = -1;
    int v = -1;
    int min_val = -1;
    int index = -1;

    while(resarr_length < V){
        for(int i = 0;i<E; i++){
            if(u == -1  && v == -1){
                if(arr[i][3] == 0){
                    min_val = arr[i][2];
                    u = arr[i][0];
                    v = arr[i][1];
                    index = i;
                }
            }else{
                if(vertex_length == 0){
                    if(arr[i][2] < min_val){
                        min_val = arr[i][2];
                        u = arr[i][0];
                        v = arr[i][1];
                        index = i;
                    }
                }else{
                    if(arr[i][3] == 0){
                        if(search(vertex,vertex_length,arr[i][0]) || search(vertex,vertex_length,arr[i][1])){
                            if(arr[i][2] < min_val){
                                min_val = arr[i][2];
                                u = arr[i][0];
                                v = arr[i][1];
                                index = i;
                            }
                        }
                    }
                }
            }
        }

        if(u == -1 && v == -1){
            break;
        }

        if(!search(vertex,vertex_length,u)){
            vertex[vertex_length] = u;
            vertex_length++;
        }

        if(!search(vertex,vertex_length,v)){
            vertex[vertex_length] = v;
            vertex_length++;
        }

        arr[index][3] = 1;

        resarr[resarr_length][0] = u;
        resarr[resarr_length][1] = v;
        resarr[resarr_length][2] = min_val;
        resarr_length++;

        u = -1;
        v = -1;
        min_val = -1;
        index = -1;

    }

    cout << endl << "minimum spanning tree edges" << endl;

    // printing minimum spanning tree
    for(int i = 0;i < V-1;i++){
        cout << "u: "<< resarr[i][0] << " v: " << resarr[i][1] << " cost: " << resarr[i][2] << endl;
    }
}

int main(){
    
    // 4 6
    int E,V;
    cin >> V >> E;

    int arr[E][4];

    //edges
    // 1 2 10
    // 1 3 5
    // 1 4 3
    // 2 3 2
    // 2 4 9
    // 3 4 4
    for(int i = 0 ; i < E; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][3] = 0;
    }

    prims_minimum_spanning_tree(arr,V,E);

}