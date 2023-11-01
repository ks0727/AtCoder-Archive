#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s;
    cin >> s;
    int size= s.size();
    if(size == 1){
        cout << "Yes" << endl;
        return 0;
    }
    vector<int> a(size);
    rep(i,s.size()) a[i] = s[i] - '0';
    rep(i,size-1){
        if(a[i] <= a[i+1]){
            cout << "No" << endl;
            return 0;
        }
        if(i+1 == size -1){
            cout << "Yes" << endl;
            return 0;
        }
    }
}