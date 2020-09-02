#include <iostream>
#include <math.h>
using namespace std;

class TreeNode{
    public:
        int value;
        int start;
        int end;
};

// implementing max_range query
int main(){
    
    int N; cin >> N;
    double logN = log2((double)N);
    double logN_ceil = ceil(logN);

    int L,start;
    L = pow(2.0,logN_ceil+1) - 1; //2^4
    start = pow(2.0,logN_ceil) - 1;
    

    TreeNode *tree = new TreeNode[L];
    for(int i = 0;i<N;i++){
        cin >> tree[start+i].value;
    }

}