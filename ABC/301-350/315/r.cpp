#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<map<char,int> > rows(h),cols(w);
  vector<string> s(h);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      char c;
      cin >> c;
      rows[i][c]++;
      cols[j][c]++;
      s[i] += c;
    }
  }
  //for(int i=0;i<h;i++) cout << s[i] << endl;
  bool stop = false;
  while(!stop){
    vector<int> rs,cs;
    for(int i=0;i<h;i++) if(rows[i].size() == 1){
      for(char c='a';c<='z';c++){
        if(rows[i][c] != 1  && rows[i][c] != 0) rs.push_back(i);
      }
    }
    for(int j=0;j<w;j++) if(cols[j].size() == 1) {
      for(char c='a';c<='z';c++){
          if(cols[j][c] != 0 && cols[j][c] != 1) cs.push_back(j);
      }
    }
    if(rs.size() == 0 && cs.size() == 0) break;
    for(int r : rs){
     for(char c = 'a'; c<='z'; c++){
       if(rows[r][c] != 0){
         for(int j=0;j<w;j++){
          if(cols[j][c] != 0){
            cols[j][c]--;
            if(cols[j][c] == 0) cols[j].erase(c);
          }
         }
          rows[r].erase(c);
      }
    }
  }
  for(int c : cs){
    for(int ch = 'a'; ch<='z';ch++){
      if(cols[c][ch]!=0){
        for(int i=0;i<h;i++){
          if(rows[i][ch] != 0){
            rows[i][ch]--;
            if(rows[i][ch]==0) rows[i].erase(ch);
          }
      }
        cols[c].erase(ch);
    }
    }
  }
}
int ans = 0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(rows[i][s[i][j]] != 0 && cols[j][s[i][j]] != 0) ans++;
    }
  }  
  cout << ans << endl;  
  return 0;
}

