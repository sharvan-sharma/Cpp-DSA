# include <iostream>
# include <vector>

using namespace std;
void addEdge(vector<int> arr[],int v,int u){
    arr[v].push_back(u); // adding 0,1
    arr[u].push_back(v); // adding 1,0
}

void printGraph(vector<int> arr[], int  V){
    for(int i = 0;i < V ;i++){
        int l  = arr[i].size();
        for(int  j = 0 ;j < l ;j++){
            cout << i << ' ' << arr[i][j] << endl;
        }
    }
}

int main(){
    int V = 6; //number of vertices

    vector<int> vadjl[V];
    //addEdge (adj list,v,u)
    addEdge(vadjl,0,1);
    addEdge(vadjl,0,2);
    addEdge(vadjl,0,3);
    addEdge(vadjl,0,4);
    addEdge(vadjl,1,2);
    addEdge(vadjl,3,4);
    addEdge(vadjl,4,2);
    addEdge(vadjl,2,4);
    printGraph(vadjl,V);
    return 0;
}