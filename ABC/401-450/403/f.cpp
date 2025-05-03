#include <iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> term(n+1),expr(n+1);
  vector<int> tcnt(n+1,1e9),ecnt(n+1,1e9);
  vector<string> ones = {"1","11","111","1111"};
  for(int i=1;i<=n;i++){
    for(int j=0;j<4;j++) if(to_string(i) == ones[j]){
      term[i] = ones[j];
      tcnt[i] = j+1;
    }
    for(int j=2;j*j<=i;j++){
      if(i%j != 0) continue;
      int a = i/j,b=j;
      if(term[a].size()!=0){
        string s = "";
        for(int k=0;k<4;k++)if(to_string(b) == ones[k]){
          s = ones[k];
          break;
        }
        if(expr[b].size()!=0){
          string ns = "(" + expr[b] + ")";
          if(s.size() == 0 || ns.size() < s.size()) s = ns;
        }
        if(s.size() != 0 && tcnt[a]+1+s.size() < tcnt[i]){
          term[i] = term[a] + "*" + s;
          tcnt[i] = term[i].size();
        }
      }
      if(term[b].size()!=0){
        string s = "";
        for(int k=0;k<4;k++)if(to_string(a) == ones[k]){
          s = ones[k];
          break;
        }
        if(expr[a].size()!=0){
          string ns = "(" + expr[a] + ")";
          if(s.size() == 0 || ns.size() < s.size()) s = ns;
        }
        if(s.size() != 0 && tcnt[b]+1+s.size() < tcnt[i]){
          term[i] = term[b] + "*" + s;
          tcnt[i] = term[i].size();
        }
      }
      if(term[i].size() != 0){
        expr[i] = term[i];
        ecnt[i] = tcnt[i];
      }
      for(int c=1;c<i;c++){
        int d=i-c;
        if(expr[c].size() != 0 && term[d].size() != 0){
          string s = expr[c] + "+" + term[b];
          if(s.size() < ecnt[i]){
            expr[i] = s;
            ecnt[i] = s.size();
          }
        }
      }
      if(expr[i].size() != 0){
        string ns = "(" + expr[i] + ")";
        if(ns.size() < tcnt[i]){
          term[i] = ns;
          tcnt[i] = ns.size();
          if(tcnt[i] < ecnt[i]){
            expr[i] = term[i];
            ecnt[i] = tcnt[i];
          }
        }
      }
    }
  }
  cout << expr[n] << endl;
  return 0;
}

