#include <iostream>
using namespace std;

void reverse(int arr[],int N,int d){
    while(d--){
        for(int i = 0;i<(N-1);i++){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

int main() {
    
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0;i < N;i++){
            int v;
            cin >> v;
            arr[i] = v;
        }
        int d;
        cin >>  d;
        d= d% N;
        reverse(arr,N,d);
        
        for(int i=0;i<N;i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    
	return 0;
}