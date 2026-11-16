class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};


class WordDictionary {
public:
    TrieNode* root = nullptr;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->children[i] == nullptr) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        bool found = false;
        dfs(word,curr,0,found);
        return found;
    }

    void dfs(const string& word, TrieNode* curr, int wordIndex, bool& found) {
        
        if (wordIndex == word.size()) {
            if (curr->endOfWord) {
                found = true;
            }
            return;
        }

        char c = word[wordIndex];
        if (c == '.') {
            // recursivley explore all paths
            for (int i = 0; i < 26; i++) {
                TrieNode* tmp = curr->children[i];
                if (!tmp) continue;
                dfs(word,tmp,wordIndex+1,found);
            }
        }
        else {
            // Just go down
            int i = c - 'a';
            TrieNode* tmp = curr->children[i];
            if (!tmp) return;
            dfs(word,tmp,wordIndex+1,found);
        }
    }



};
