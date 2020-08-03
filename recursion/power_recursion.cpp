#include <iostream>

using namespace std;

int power(int N,int P){
    if( P == 0){
        return 1;
    }else{
        return N * power(N,P-1);
    }
}

int main(){
    int N,P;
    cin >> N >> P;

    cout << power(N,P);
}