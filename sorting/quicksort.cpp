#include <iostream>
using namespace std;


void quicksort(int arr[],int start,int end){

    

    if(start >= end){
        return;
    }
    
    
    int pivot = arr[start];

    int i = start+1;
    int j = end; 

    while(i < (end+2) && j > start){
        if(i > j){
            int temp = arr[j];
            arr[j] = arr[start];
            arr[start] = temp;
            break;
        }else if(arr[i] <= pivot){
            i++;
        }else if( arr[j] >= pivot){
            j--;
        }else if(arr[i] > pivot && arr[j] < pivot){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    cout << j << " partition point" << endl ;

    quicksort(arr,start,j-1);
    quicksort(arr,j+1,end);
}


int main(){

    int N;
    cin >> N;

    int arr[N];
    for(int i = 0;i<N;i++){
        cin >> arr[i];
    }

    cout << endl << "0 based indexing" << endl;

    quicksort(arr,0,N-1);

    cout << "sorted array - " << endl;

    for(int i = 0 ;i<N;i++) cout << arr[i] << ' ';


}