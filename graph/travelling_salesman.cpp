#include <iostream>
using namespace std;

int travelling_salesperson(int destination,int source,int **matrix,int remaining[],int L){
    
    int min_cost = -1;
    int cost;


    for(int i = 0;i<L;i++){
        int new_remining[L-1];
        int  k = 0;
        for(int j = 0;j<L;j++){
            if( j != i){
                new_remining[k] = remaining[j];
                k++;
            }
        }
        cost = matrix[source][remaining[i]] + travelling_salesperson(destination,remaining[i],matrix,new_remining,L-1);
        
        if(min_cost == -1){
            min_cost = cost;
        }else if(min_cost > cost){
            min_cost = cost;
        }
    } 
    if(L == 0){
        min_cost = matrix[source][destination];
    }
    return min_cost;
}

int main(){
    int V,source;
    cin >> V >> source;

    int **matrix = new int*[V];
    for (int i = 0;i < V;i++){
        int *pointer = new int[V];
        for(int  j = 0;j<V;j++){
            cin >> pointer[j];
        }
        matrix[i] = pointer;
    }

    int remaining[V-1];
    int i = 0;
    for(int j = 0;j<V;j++){
        if(j != (source-1)){
            remaining[i] = j;
            i++;
        }
    }

    int cost = travelling_salesperson(source-1,source-1,matrix,remaining,V-1);

    cout << "cost - "<< cost;

}
