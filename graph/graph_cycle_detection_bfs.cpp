#include <iostream>
#include <vector>
#include <list>

using namespace std;

//detect cycle in a directed  graph

void addedge(vector<int> adjl[],int v,int u){
    adjl[v].push_back(u);//directed graph
}

int detect_cycle(vector<int> adjl[],int V){

    int flagArr[V]; // creating flag array for each vertex [0,0,0,0]
    for (int i = 0;i < V; i++){
        flagArr[i] = 0;
    }

    list<int> queue;

    for(int k = 0;k < V;k++){ //this loop is used because of disconnected graph

        if(flagArr[k] == 0){
            
            queue.push_back(k);
            flagArr[k] = 1;

            while(!queue.empty()){
            
                int parent_vertex = *(queue.begin());
                queue.pop_front();
                int s = adjl[parent_vertex].size();

                for(int i = 0 ; i < s ; i++){
                    int child_vertex = adjl[parent_vertex][i];
                    
                    if(child_vertex != parent_vertex and flagArr[child_vertex] == 1){
                        return 1;
                    }else{
                        flagArr[child_vertex] = 1;
                    }
                    queue.push_back(child_vertex);
                }
            }
        }
    }

    return 0;

}


int main(){

    int V = 6;

    vector<int> adjl[V];

    //disconnected graph   0(alone vertex)  1->2 2->3 3->4 4->5 5->1

    addedge(adjl,1,2);
    addedge(adjl,2,3);
    addedge(adjl,3,4);
    addedge(adjl,4,5);
    addedge(adjl,5,1);

    int cyclic = detect_cycle(adjl,V);

    if(cyclic){
        cout << "cycle exist";
    }else{
        cout << "no cycle exist";
    }

    return 0;
}
