class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    
    TrieNode() {
        isEnd = false;
    }

    void addWord(string &word) {
        TrieNode* node = this;
        for (char c: word) {
            if (!node->children[c]) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
private:
public:
    unordered_set<string> res;
    vector<vector<bool>> visited;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();

        for (string &s: words) {
            root->addWord(s);
        }

        int m = board.size();
        int n = board[0].size();
        visited.assign(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                backtrack(board, i, j, root, "");
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void backtrack(vector<vector<char>>& board, int r, int c, TrieNode *node, string word) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] || !node->children.count(board[r][c])) {
            return;
        }

        visited[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];

        if (node->isEnd) {
            res.insert(word);
        }

        backtrack(board, r + 1, c, node, word);
        backtrack(board, r - 1, c, node, word); 
        backtrack(board, r, c + 1, node, word);
        backtrack(board, r, c - 1, node, word);

        visited[r][c] = false;
    }
};
