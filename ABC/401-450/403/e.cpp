#include <iostream>
#include<vector>
#include<set>
using namespace std;

struct Trie{
  struct Nodes{
    vector<int> next;
    int cnt;
    bool is_end;
    Nodes():is_end(false),cnt(0),next(26,-1){}
  };
  vector<Nodes> nodes;
  Trie(){
    nodes.emplace_back();
  }
  void insert(const string& s){
    int cur=0;
    nodes[cur].cnt++;
    for(char c : s){
      int idx = c-'a';
      if(nodes[cur].next[idx] ==-1){
        nodes[cur].next[idx] = nodes.size();
        nodes.emplace_back();
      }
      cur = nodes[cur].next[idx];
      nodes[cur].cnt++;
    }
    nodes[cur].is_end = true;
  }

  int traverse(const string& s){
    int cur=0;
    for(char c : s){
      int idx = c - 'a';
      cur = nodes[cur].next[idx];
      if(cur == -1) return -1;
    }
    return cur;
  }

  bool search(const string& s){
    int cur = traverse(s);
    return cur != -1 && nodes[cur].is_end;
  }

  bool starts_with(const string& prefix){
    return traverse(prefix) != -1;
  }
  
  int count_prefix(const string& prefix){
    int cur = traverse(prefix);
    return (cur == -1)? 0 : nodes[cur].cnt;
  }
};


int main(){
  int q;
  cin >> q;
  int ans = 0;
  Trie tt,ss;
  set<string> st;
  while(q--){
    int t;
    string s;
    cin >> t >> s;
    if(t == 1){
      tt.insert(s);
      if(ss.starts_with(s)){
        set<string> er;
        for(string x : st){
          if(x.substr(0,s.size()) == s) er.insert(s);
        } 
        for(string x: er) st.erase(x);
        ans -= er.size();
      }
    }else{
      string now = "";
      bool add = true;
      for(char c : s){
        now += c;
        if(tt.search(now)) add = false;
      }
      if(add){
        ss.insert(s);
        st.insert(s);
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

