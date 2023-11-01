#include<bits/stdc++.h>
using namespace std;

bool check(string S){
    int count = 0;
    for(int i=0;i<S.size();i++){
        if(S.at(i) == '('){
            count++;
        }
        else if(S.at(i) == ')'){
            count--;
        }
        if(count < 0) return false;
    }
    if(count == 0) return true;
    else return false;
}

int main(){
    string S;
    cin >> S;
    int ans;
    int count = 0;
    for(int i=0;i<S.size();i++){
        if(S.at(i) == '?'){
            S.at(i) = '(';
        }
    }
    
}