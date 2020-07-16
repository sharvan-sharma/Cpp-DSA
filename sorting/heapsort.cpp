#include <iostream>

using namespace std;

template <class T>
void heapify(T* p,int l){
   while(l > 1){ 
    if( (l-1)%2 == 0 ){ // for even length

        int maxl = ( *(p+l-1) > *(p+l-2))? l-1 : l-2;
        int parent = ((int)(l-1)/2)-1;
    
        if(*(p+parent) < *(p+maxl) ){
            T temp = *(p+maxl);
            *(p+maxl) = *(p+parent);
            *(p+parent) = temp;
        }

        l = l - 2;

    }else{//for odd length

        int parent = (int)(l-1)/2;

        if(*(p+parent) < *(p+l-1) ){
            T temp = *(p+l-1);
            *(p+l-1) = *(p+parent);
            *(p+parent) = temp;
        }

        l = l - 1;

    }
   }

}

template <class T>
void heapsort(T* p,int l){
    int newl = l;
    while(newl > 1){
        heapify(p,newl);
        T temp = *p;
        *p = *(p+newl-1);
        *(p+newl-1) = temp;

        newl -= 1;
    }
}

int main(){
    int N;
    cout << "Enter the length of Array" << endl;

    cin >> N;
    int arr[N];

    cout << "Enter the elements space seperated" << endl;

    for(int i =0 ; i<N ;i++){
        cin >> arr[i];
    }

    heapsort(arr,N);

    cout << "Sorted Array"<<endl;
    for(int i =0 ; i<N ;i++){
        cout << arr[i] << ' ';
    }
}