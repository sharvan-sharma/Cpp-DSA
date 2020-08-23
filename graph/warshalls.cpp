#include <iostream>
using namespace std;

void warshalls(int **adj_matrix,int L){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            for(int k = 0;k<4;k++){
                if(i != j && i != k && j != k){
                    if(adj_matrix[j][i] != -1 && adj_matrix[i][k] != -1){
                        if(adj_matrix[j][k] == -1){
                            adj_matrix[j][k] = adj_matrix[j][i]+adj_matrix[i][k];
                        }else if(adj_matrix[j][k] > adj_matrix[j][i]+adj_matrix[i][k]){
                            adj_matrix[j][k] = adj_matrix[j][i]+adj_matrix[i][k];
                        }
                    }
                }
            }
        }
    }

    for(int j = 0;j<4;j++){
        cout << "distance of other vertex from source vertex " << j+1 << " : ";
            for(int k = 0;k<4;k++){
                cout << adj_matrix[j][k] << " "; 
            }
        cout << endl;
     }
}

int main(){
    int **adj_matrix = new int*[4];
    for(int i = 0;i<4;i++){
        int *pointer = new int[4];
        for(int j =0;j<4;j++){
            if(i == j){
                pointer[j] = 0;
            }else{
                pointer[j] = -1;
            }
        }
        adj_matrix[i] = pointer;
    }

    int edges;
    cin >> edges;
    for(int i=0;i<edges;i++){
        int u,v,distance;
        cin >> u >> v >> distance;
        adj_matrix[u-1][v-1] = distance;
    }

    warshalls(adj_matrix,4);

}