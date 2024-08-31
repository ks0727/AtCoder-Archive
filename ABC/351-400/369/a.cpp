#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int a,b;
    cin >> a >> b;
    int dif = abs(a-b);
    set<int> st;
    st.insert(a-dif);
    st.insert(b+dif);
    if(dif%2 == 0) st.insert(a+dif/2);
    cout << st.size() << endl;
    return 0;
}