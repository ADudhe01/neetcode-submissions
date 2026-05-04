class PrefixTree {
private:
    unordered_map<string, int> prefCount;
    set<string> words;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        string pref = "";
        for (char c: word) {
            pref += c;
            prefCount[pref]++;
        }

        words.insert(word);
    }
    
    bool search(string word) {
        return words.contains(word);
    }
    
    bool startsWith(string prefix) {
        return prefCount.contains(prefix);
    }
};
