#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    int count = 1;
    int max_count = 1;
    int max_index = -1;
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    if(N == 1) cout << A.at(0) << " " << 1 << endl;
    else{
        for(int i=0; i< N-1;i++){
        if(A.at(i) == A.at(i+1)) count++;
        else count = 0;
        if(max_count <= count){
            max_count = count;
            max_index = i;
        }
    }
    cout << A.at(max_index) << " " << max_count + 1 << endl;
    }
    
}