#include <iostream>

using namespace std;

//method 1 Problem : excessive recursion
// int fib(int N){
//     if(N == 0 | N == 1){
//         return N;
//     }else{
//         return fib(N-1) + fib(N-2);
//     }
// }

//Method 2 use of memoization (storing result of previous function calls)

void fib(int N, int arr[]){
    if(N == 0 | N == 1){
        arr[N] = N;
    }else{
        fib(N-1,arr);
        fib(N-2,arr);
        arr[N] = arr[N-1] + arr[N-2];
    }
}

int main(){
    int N;
    cin >> N;
    
    int arr[N+1];
    for(int i = 0;i<=N;i++) arr[i]=-1;

    fib(N,arr);

    for(int i = 0;i<=N;i++) cout << arr[i] << endl;
}