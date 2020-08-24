#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    int profit[n+1];
    int weight[n+1];
    for(int i = 1;i < n+1;i++) cin >> profit[i];
    for(int i = 1;i < n+1;i++) cin >> weight[i];

    int V[n+1][m+1];

    for(int i = 0;i<(m+1);i++) V[0][i] = 0; 
    for(int i = 1;i<(n+1);i++) V[i][0] = 0;

    // creating data for genearting a set;

    int max_profit_value = 0;
    int max_profit_row = 0;

    for(int i = 1;i<(n+1);i++){
        for(int j = 1;j < (m+1);j++){
            int value1 = V[i-1][j];
            int value2;
            if((j - weight[i]) >= 0){
                value2 = profit[i] + V[i-1][j-weight[i]];
            }else{
                value2 = value1;
            }
            V[i][j] = value1 > value2 ? value1:value2;
           
            if(V[i][j] > max_profit_value){
                max_profit_value = V[i][j];
                max_profit_row = i;
            }
        }
    }
    
    cout << "max profit: " <<max_profit_value <<endl;

    int included_objects[n+1] = {0};

    for(int i = max_profit_row;i >= 1;i--){
        int check = 0;
        for(int j = 1;j<m+1;j++){
            if(max_profit_value == V[i-1][j]){
                check = 1;
                break;
            }
        }
        if (check == 0){
            included_objects[i] = 1;
            max_profit_value -= profit[i];
        }
    }

    cout << "included objects" << endl;
    for(int i = 1;i<(n+1);i++) cout << included_objects[i] << ' ';

}