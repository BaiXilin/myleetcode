struct node {
    bool endWord = false;
    node *next[26] = {nullptr};
};

class WordDictionary {
public:
    WordDictionary() {
        root = new node();
    }
    
    // add word to the trie
    void addWord(string word) {
        node *iter = root;
        for(unsigned i = 0; i < word.length(); i++) {
            // make sure a node exists for the next char
            if(!iter->next[word[i] - 'a'])
                iter->next[word[i] - 'a'] = new node();
            // move the iterator to the next level
            iter = iter->next[word[i] - 'a'];
        }
        // at the end of a word, mark the node flag
        iter->endWord = true;
    }
    
    // found if word exists in the trie
    bool search(string word) {
        return search_recur(word, root);
    }

    // recursively called when there is a dot.
    bool search_recur(string word, node *root) {
        // base case: word is empty
        if(word.empty())
            // a word is found if iter is a end-of-word node
            return word.empty() && root->endWord;

        // iterate the trie using letters in word
        node *iter = root;
        for(unsigned i = 0; i < word.length(); i++) {
            if(word[i] == '.') {
                // dot may represent any letter
                bool found = false;
                // iterate through the 26 letters, any non-null next node can be a candidate of word
                for(unsigned j = 0; j < 26; j++) {
                    // sub-node empty at index j, skip
                    if(!iter->next[j])
                        continue;
                    // search the next trie level for the remainder of word after dot
                    // sub-node acts as root for the remainder of word
                    found = search_recur(word.substr(i + 1), iter->next[j]);
                    // one candidate is our search target, no need to search the rest
                    if(found) return true;
                }
                // none of the candidates are search target, search failed
                if(!found) return false;
            } else if(!iter->next[word[i] - 'a']) {
                // not dot. So iteratively search down the trie
                // next char not found in the node, so search failed
                return false;
            } else {
                // continue to the next node in trie
                iter = iter->next[word[i] - 'a'];
            }
        }
        // all letters are searched
        // if we happen to be at an end-of-word node, then the word is found
        if(iter->endWord)
            return true;
        // current is not an end-of-word node, search failed
        return false;

    }
private:
    // the root of the trie
    node *root = nullptr;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
