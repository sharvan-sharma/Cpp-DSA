#include <iostream>
using namespace std;

void merge(int arr[],int start,int mid,int end){

    cout << "merge call - start:" << start << " mid " << mid <<  " end " << end << endl;

    int i = start;
    int j = mid+1;

    int auxarr[end-start+1];
    int k = 0;

    while(i <= mid || j <= end){
        if(i > mid){
            auxarr[k] = arr[j];
            j++;
        }else if(j > end){
            auxarr[k] = arr[i];
            i++;
        }else if(arr[i] < arr[j]){
            auxarr[k] = arr[i];
            i++;
        }else{
            auxarr[k] = arr[j];
            j++;
        }
        k++;
    }

    for(int i = 0; i < k;i++){
        arr[start+i] = auxarr[i];
    }
}

void mergesort(int arr[],int start,int end){

        cout << "mmerge sort call - start: " << start << " end: " << end << endl;

        if((end-start) <= 0){
            return;
        }

        int mid = int((end-start)/2);
        cout <<"mid " << mid << endl;

        mergesort(arr,start,start+mid);
        mergesort(arr,start+mid+1,end);
        merge(arr,start,start+mid,end);

}

int main(){

    int N;
    cin >> N;

    int arr[N];
    for(int i = 0;i<N;i++){
        cin >> arr[i];
    }

    cout << endl << "0 based indexing" << endl;

    mergesort(arr,0,N-1);

    cout << endl << "sorted array - " << endl;

    for(int i = 0 ;i<N;i++) cout << arr[i] << ' ';


}