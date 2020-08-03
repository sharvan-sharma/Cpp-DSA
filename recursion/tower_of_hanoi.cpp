#include <iostream>
using namespace std;

void tower_of_hanoi(int n,int a,int b,int c){
    if( n > 0){
        tower_of_hanoi(n-1,a,c,b);
        cout << a << ' ' << c << endl;
        tower_of_hanoi(n-1,b,a,c);
    }
}

int main(){
    int n;
    cin >> n;

    tower_of_hanoi(n,1,2,3);
}