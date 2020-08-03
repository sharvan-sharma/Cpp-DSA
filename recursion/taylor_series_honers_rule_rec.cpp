#include <iostream>

using namespace std;

//looping method
// int main(){
//     int x,n;
//     cin >> x>>n;
//     int v = 1;
//     while(n >= 1){
//         v = v*((long double)x/n) + 1;
//         n--;
//     }

//     cout << v;
// }
//method 2 using recursion
long double taylor_honer(int x,int n){
    static int v = 1;
    if (n == 0){
        return v;
    }else{
        v =  1 + (long double)x/n*v;
        return taylor_honer(x,n-1);
    }
}

int main(){
    int x,n;
    cin >> x >> n;

    cout << taylor_honer(x,n);
}