#include <iostream>
#include <vector>

using namespace std;

void addedge(vector<int> adjl[],int u,int v){
    adjl[u].push_back(v);
}

void topological_sort(vector<int> adjl[],int flag[],int v,vector<int> & stack){
    int s = adjl[v].size();
    flag[v] = 1;
    for (int i = 0; i < s ; i++){

        if( flag[adjl[v][i]] == 0){
            topological_sort(adjl,flag,adjl[v][i],stack);
        }
    }

    stack.push_back(v);
}


int main(){
    int V = 7;

    vector<int> adjl[V];

    addedge(adjl,0,1);
    addedge(adjl,0,2);
    addedge(adjl,1,3);
    addedge(adjl,3,4);
    addedge(adjl,2,5);
    addedge(adjl,5,4);
    addedge(adjl,4,6);

    int flag[V];
    for (int i=0; i < V;i++){
        flag[i] = 0;
    } 

    vector<int> final_stack;
    topological_sort(adjl,flag,0,final_stack);

    int l = final_stack.size();

    for(int i = 0;i < l ;i++){
        cout << final_stack.back() << ' ' << endl;
        final_stack.pop_back();
    }

}