#include <iostream>
using namespace std;

// int power(int n,int p){
//     if(p == 0){
//         return 1;
//     }else{
//         return n * power(n,p-1);
//     }
// }

// int fact(int n){
//     if(n == 0){
//         return 1;
//     }else{
//         return n * fact(n-1);
//     }
// }
//method 1 using power and fact function
// long double taylor_series(int x,int n){
//     static int p,f;
//     if( n == 0 ){
//         return 1;
//     }else{
//         return (long double)power(x,n)/fact(n) + taylor_series(x,n-1);
//     }
// }

//method 2 using static variable
long double taylor_series(int x,int n){
    static int p,f;
    p = 1;f = 1;
    if( n == 0 ){
        return 1;
    }else{
        long double v = taylor_series(x,n-1);
        p = p * x;
        f = f * n;
        return (long double)p/f + v;
    }
}

int main(){
    int x,n;
    cin >> x >> n;

    cout  << taylor_series(x,n);
}