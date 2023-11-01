#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool isOkay(string s){
    int size= s.size();
    if(size == 1){
        return true;
    }
    vector<int> a;
    rep(i,s.size()) a.emplace_back(s[i] - '0');
    rep(i,size-1){
        if(a[i] <= a[i+1]){
            return false;
        }
        if(i+1 == size -1){
            return true;
        }
    }
    return false;
}

int main(){
    int k;
    cin >> k;
    int i = 0;
    int num = 1;
    while(i < k){
        if(isOkay(to_string(num))) i++;
        num++;
    }
    cout << num - 1 << endl;
}