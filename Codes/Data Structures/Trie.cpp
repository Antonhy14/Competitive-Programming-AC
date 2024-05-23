struct Trie {
  struct Node : map<char, int> {
    int cont = 0;
    bool isWord = false;
  };

  vector<Node> trie;
  
  Trie() {
    newNode();
  }

  int newNode() {
    trie.pb({});
    return trie.size() - 1;
  }

  void insert(string& s, int u = 0) {
    for (char c : s) {
      if (!trie[u].count(c))
        trie[u][c] = newNode();

      trie[u].cont++;
      u = trie[u][c];
    }
    trie[u].isWord = true;
  }

  int find(string& s, int u = 0) {
    int sum = 0;
    for (char c : s) {
      if (!trie[u].count(c))
        return sum;
      u = trie[u][c];
      sum+= trie[u].isWord;
    }
    return sum;
  }

  void del(string& s, int u = 0) {
     for (char c : s) {
      if (!trie[u].count(c))
        return;
      u = trie[u][c];
      trie[u].cont--;
    }
    trie[u].isWord = false;
  }

  void print() {
    string currentWord;
    dfs(trie[0], currentWord);
  }

  void dfs(Node node, string& currentWord) {
        if(node.isWord) 
            cout << currentWord << nl;

        for(auto& par: node) {
            currentWord.pb(par.first);
            dfs(trie[par.second], currentWord);
            currentWord.pop_back();
        }
  }
};
