#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,x;
    cin >> n >> x;
    set<int> st;
    rep(i,n){
        int value;
        cin >> value;
        st.insert(value);
    }
    for(int value : st){
        int target = value - x;
        if(st.count(target)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}