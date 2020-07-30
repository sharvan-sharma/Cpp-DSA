#include <iostream>

using namespace std;

void reverse(int arr[],int start,int end){
    while(start<end){
       int temp = arr[start];
       arr[start] = arr[end];
       arr[end] = temp;
        start++;
        end--;
    }
}

void reversal(int arr[],int N,int d){
    if (d == 0){
        return;
    }else{
        reverse(arr,0,d-1);
        reverse(arr,d,N-1);
        reverse(arr,0,N-1);
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
        d = d % N;
        reversal(arr,N,d);
        
        for(int i=0;i<N;i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    
	return 0;
}