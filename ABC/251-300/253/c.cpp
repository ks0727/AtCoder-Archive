#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
    int q;
    cin >> q;
    multiset<int> st;

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x; 
            cin >> x;
            st.insert(x);
        }
        if(type == 2){
            int x,c;
            cin >> x >> c;
            while(c){
                if(!st.count(x)) break;
                c--;
                st.erase(st.find(x));
            }
        }
        if(type == 3){
            cout << *st.rbegin() - *st.begin() << endl;
        }
    }
    return 0;
}