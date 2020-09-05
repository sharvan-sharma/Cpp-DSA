#include <iostream>
using namespace std;


//find (x^n)%d  time complexity o(log(n)) and space complexity o(1)
int main(){

    // input 71045970 41535484 64735492

    long long int x,n,d;
    cin >> x >> n >> d;

    x = x%d;
    if (x == 0){
        cout << 0;
    }

    long long int res = 1;

    while(n > 0){
        if(n&1){
            res = (res*x)%d;
        }
        x = (x*x)%d;
        n = n >> 1;
    }

    // output 20805472
    cout << res;

}