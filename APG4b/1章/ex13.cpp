#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> A(N);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    int mean;
    int sum;
    sum = accumulate(A.begin(),A.end(),0);
    mean = sum / N;
    for(int i=0;i<N;i++){
        cout << abs(A.at(i) - mean) << endl;
    }
}
