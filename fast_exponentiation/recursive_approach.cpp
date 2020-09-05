#include <iostream>
using namespace std;

#define ll long long int

ll power_mod(ll x,ll n,ll d){
    if (n == 0){
        return 1;
    }else if(n%2 != 0){
        ll v1 = x%d;
        ll v2 = power_mod(x,n-1,d);
        return (v1*v2)%d;
    }else{
        ll v = power_mod(x,n/2,d);
        return (v*v)%d;
    }
}

//find (x^n)%d  time complexity o(log(n)) and space complexity o(log(n))
int main(){

    // input 71045970 41535484 64735492

    ll x,n,d;
    cin >> x >> n >> d;

    x = x%d;
    if (x == 0){
        cout << 0;
    }

    // output 20805472
    cout << power_mod(x,n,d);

}