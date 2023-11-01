#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool answer(int n,string x,string y){
    rep(i,n){
        if(x[i] != 'C' && y[i] == 'C') return false;
    }
    queue<string> q;
    q.push(x);
    while(!q.empty()){
        string candidate = q.front();
        q.pop();
        if(candidate == y) return true;
        rep(i,n){
            string copy = candidate;
            if(i != 0 && copy[i-1] == 'A' && copy[i] == 'B'){
                copy[i-1] = 'B'; copy[i] = 'A'; 
                q.push(copy);
                continue;
            }
        }
        rep(i,n){
            string copy = candidate;
            if(copy[i] == 'C'){
                copy[i] = 'A';
                q.push(copy);
                copy[i] = 'B';
                q.push(copy);
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    rep(i,t){
        int n;
        string x,y;
        cin >> n >> x >> y;
        if(answer(n,x,y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}