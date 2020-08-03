#include <iostream>

using namespace std;

int sumofn(int N){
    int sum = 0;
    if(N > 0){
        sum = N + sumofn(N-1);
    }
    return sum;
}

int main(){
    int N;
    cin >> N;

    cout << sumofn(N);

}