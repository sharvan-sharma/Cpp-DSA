#include  <iostream>

using namespace std;

//Binary Search
template <class T>
int binary_search(T* p,int l,T v){

    int first = 0;
    int last = (l-1);
    int mid = (int)(first + last)/2;

    while(first <= last and first >= 0 and last <= (l-1)){
    
        if (*(p+mid) == v){
            return mid;
        }else if(*(p+mid) > v){
            last = mid - 1;
            mid = (int )(first + last)/2 ;
        }else{
            first = mid + 1;
            mid = (int )(first + last)/2 ;
        }
    }
    return  -1;
}


int main(){
    int N, M;
    cin >> N;

    int arr[N];

    for(int  i = 0;i<N;i++){
        cin >> arr[i];
    }

    cin >> M;

    int index = binary_search(arr,N,M);

    cout << index ;

}