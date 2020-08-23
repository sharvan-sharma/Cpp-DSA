#include <iostream>
#include <vector>
using namespace std;

struct Int2{
  int array[2];
};

void single_source_shortest_path(vector<Int2> adjl[],int source,int V){

    int selected[V];
    int distance[V];
    for(int i = 0;i<V;i++){
        selected[i] = 0;
        if (i == (source-1)){
            distance[i] = 0;
        }else{
            distance[i] = -1;
        }
    }

    while(true){
        int minvertex = -1;
        for(int i=0;i<V;i++){
            if(distance[i] != -1 && selected[i] == 0){
                if(minvertex == -1){
                    minvertex = i;
                }else{
                    if(distance[minvertex] > distance[i]){
                        minvertex = i;
                    }
                }
            }
        }

        if(minvertex == -1){
            break;
        }

        int size = adjl[minvertex].size();
        for(int i=0;i<size;i++){
            int vertex_i = adjl[minvertex][i].array[0];
            if(distance[vertex_i] == -1){
                distance[vertex_i] = distance[minvertex]+adjl[minvertex][i].array[1];
            }else{
                if(distance[vertex_i] > (distance[minvertex]+adjl[minvertex][i].array[1])){
                    distance[vertex_i] = distance[minvertex]+adjl[minvertex][i].array[1];
                }
            }
        }

        selected[minvertex] = 1;

    }

    cout << "distance array from source " << source << endl;
    for (int i = 0;i<V;i++){
        if(i != (source-1)){
            cout << "vertex " << i+1 <<": "<< distance[i] << endl;
        }
    }
    cout << "-1 denotes no path  from source to vertex" ;

}

void addNode(vector<Int2> adjl[],int u,int v,int distance){
    Int2 obj;
    obj.array[0] = v-1;
    obj.array[1] = distance;
    adjl[u-1].push_back(obj);
}


int main(){

    vector<Int2> adjl[6];

    addNode(adjl,1,2,2);
    addNode(adjl,1,3,4);
    addNode(adjl,2,3,1);
    addNode(adjl,3,5,3);
    addNode(adjl,2,4,7);
    addNode(adjl,5,4,2);
    addNode(adjl,5,6,5);
    addNode(adjl,4,6,1);


    single_source_shortest_path(adjl,1,6);

}