class WordDictionary {
private:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
    bool dfs(string& word, int index, TrieNode* node) {
        if (index == word.size())
            return node->isEnd;
        
        char c = word[index];
        
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] &&
                    dfs(word, index + 1, node->child[i]))
                    return true;
            }
            return false;
        } else {
            int idx = c - 'a';
            if (!node->child[idx]) return false;
            return dfs(word, index + 1, node->child[idx]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->child[idx])
                cur->child[idx] = new TrieNode();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
