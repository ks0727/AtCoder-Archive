#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    int ans;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    for(int i=0;i<N;i++) cin >> A.at(i);
    for(int i=0;i<M;i++) cin >> B.at(i);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<N;i++){
        auto num = lower_bound(B.begin(),B.end(),A.at(i));
        auto buyers = M - num;
        if(i >= buyers){
            ans = A.at(i);
            break;
        }
    }
    cout << ans << endl;
}