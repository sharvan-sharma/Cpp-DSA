#include <iostream>
using namespace std;


void nqueens(int n){
   
    int flag[n];
    for(int i=0;i<n;i++) flag[i] = 0;

    int stack[n];
    int top = -1;
    int t = 1;
    while(top < (n-1)){
        int check = 0;
        for(int i=t;i<=n;i++){
            if((top == -1) || (flag[i-1] == 0 && ((stack[top]-i) > 1 || (stack[top]-i) < -1))){
                flag[i-1] = 1;
                top++;
                stack[top] = i;
                check++;
                break;
            }
        }
        if(check == 0){
            flag[stack[top]-1] = 0;
            t = stack[top] + 1;
            top--;
        }else{
            t = 1;
        }
       
    }

    cout << "position of each queen column wise" << endl;

    for(int  i = 0;i<n;i++){
        cout<<stack[i]<<" ";
    }

}

int main(){
    int n;
    cin >> n;

    nqueens(n);
}