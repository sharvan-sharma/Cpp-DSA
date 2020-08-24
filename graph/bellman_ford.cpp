#include <iostream>
using namespace std;

int main(){
    int V,E;
    cin >> V >> E;

    int distance[V+1] = {0};
    int covered[V+1] = {0};

    int edges[E][3];
    for(int i = 0;i < E;i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int source;
    cin >> source;

    covered[source] = 1;
    //Bellman ford implementation
    for(int i = 0;i < (V-1);i++){
        for(int j = 0;j < E;j++){
            if (covered[edges[j][0]] == 1){
                if(covered[edges[j][1]] == 0){
                    distance[edges[j][1]] = distance[edges[j][0]]+edges[j][2];
                    covered[edges[j][1]] = 1;
                }else if(distance[edges[j][0]]+edges[j][2] < distance[edges[j][1]]){
                    distance[edges[j][1]] = distance[edges[j][0]]+edges[j][2];
                }
            }
        }
    }


    cout << endl << "distance of other vertex form source " << source << " using Bellman ford" << endl;
    for(int i = 1;i<(V+1);i++){
        if(i != source){
             cout << "vertex " << i <<": " << distance[i] << endl;
        }
    }
}