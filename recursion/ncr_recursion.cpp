#include <iostream>

using namespace std;

// long double ncr(int n,int r){
//     if(r == 0){
//         return 1;
//     }else{
//         return ncr(n-1,r-1)*(long double)n/r;
//     }
// }
//using pascals triangle

long double ncr(int n,int r){
    if(r == 0){
        return 1;
    }else if (n == r){
        return 1;
    }else{
        return ncr(n-1,r-1) + ncr(n-1,r);
    }
}

int main(){
    int n,r;
    cin >> n >> r;

    cout << ncr(n,r);
}