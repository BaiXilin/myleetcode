struct node {
    bool end = false;
    unordered_map<char, node *> next;

    node() {};
};

class Trie {
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* iter = root;
        for(auto ch = word.begin(); ch != word.end(); ch++) {
            if(iter->next.find(*ch) == iter->next.end())
                // current char in the string not found in this node
                // so insert a new node
                iter->next[*ch] = new node();
            // update trie iterator
            iter = iter->next[*ch];

            // if at the last char of the string, set end flag to true
            if(ch == prev(word.end()))
                iter->end = true;
        }
    }
    
    bool search(string word) {
        node *iter = root;
        for(auto ch : word) {
            // if the next char is not found, the word is not in the trie
            if(iter->next.find(ch) == iter->next.end())
                return false;
            // move to the next node
            iter = iter->next[ch];
        }

        // if not at the end of a word, that word is not in the trie
        return iter->end;
    }
    
    bool startsWith(string prefix) {
        node *iter = root;
        for(auto ch : prefix) {
            if(iter->next.find(ch) == iter->next.end())
                return false;
            iter = iter->next[ch];
        }
        return true;
    }

private:
    node* root = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
