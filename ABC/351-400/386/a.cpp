#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    set<int> st;
    rep(i,4){
        int a;
        cin >> a;
        st.insert(a);
    }
    if(st.size() == 2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}