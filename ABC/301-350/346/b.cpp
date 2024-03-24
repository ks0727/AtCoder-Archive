#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;
int main(){
    int w,b;
    cin >> w >> b;
    set<P> st;
    st.emplace(1,0);
    st.emplace(1,1);
    st.emplace(2,0);
    st.emplace(2,2);
    st.emplace(3,2);
    st.emplace(4,2);
    st.emplace(4,3);
    st.emplace(5,3);
    st.emplace(5,4);
    st.emplace(6,4);
    st.emplace(6,5);
    st.emplace(7,5);
    int nw = w/7;
    int nb = b/5;
    int p = min(nw,nb);
    w -= p*7;
    b -= p*5;
    if(st.count(P(w,b))){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}