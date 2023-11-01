#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    int ans = -1;
    bool isBreak = false;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    for(int i=0;i<N;i++) cin >> A.at(i);
    for(int i=0;i<M;i++) cin >> B.at(i);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A.at(i) <= B.at(j)){
                int buyers = M - j;
                if(i >= buyers){
                    ans = A.at(i);
                    isBreak = true;
                    break;
                }
            }
            if(isBreak) break;
        }
        if(ans == -1){
            ans = B.at(M-1) + 1;
        }
    }
    cout << ans << endl;
}