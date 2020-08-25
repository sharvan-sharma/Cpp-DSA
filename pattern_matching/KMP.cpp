#include <iostream>
#include <string>
using namespace std;

void KMP(string text,string pattern){

    //lps[] preprocessing
    int length = pattern.length();
    int lps[length];
    for(int i = 0; i < length;i++){
        int count = i;
        for(int j = (i-1),k = 1;j >= 0 && k <= i;j--,k++){
            int check = 0;
            for(int  t = 0;t <= j;t++){
                if(pattern[t] != pattern[k+t]){
                    check = 1;
                    break;
                }
            }
            if (check == 0){
                break;
            }else{
                count -= 1;
            }
        }
        lps[i] = count;
    }

    // pattern matching

    int text_length = text.length();
    int j = 0;
    for(int i = 0;i<text_length;){
        if(j == length && j > 0){ //if j == length of pattern
            cout << "pattern found at index : " << i-j << endl;
            j = lps[j-1];
        }else if(pattern[j] == text[i]){ // if pattern[j]  character matches text[i]
            i++;
            j++;
        }else{
            if(j > 0){ // if pattern[j]  character doesn't matches text[i] an j > 0 then shift it to lps[j-1] 
                j = lps[j-1];
            }else{// if pattern[j]  character doesn't matches text[i] an j == 0 then increment i
                i++;
            }
        }
    }
    //for pattren found at last length
    if(j == length && j > 0){
            cout << "pattern found at index : " << text_length-j << endl;
            j = lps[j-1];
    }

}


int main(){

    string text,pattern;

    getline(cin,text);
    getline(cin,pattern);

    KMP(text,pattern);

}