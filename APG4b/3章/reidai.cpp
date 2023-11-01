#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    bool ans = false;
    for(int i=0;i<N;i++) cin >> A.at(i);
    for(int temp=0;temp < (1 << N);temp++){
        bitset<20> s(temp);
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += A.at(i) * s.test(i);
            if(sum == K){
                ans = true;
                break;
            }
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
