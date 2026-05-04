/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Go through each node in the adjacency list
    // Make a node for each index + 1, and add its neighbours in a queue
    // Traverse through the queue one by one, keeping a visited list, 
    // so that we dont visit the same node twice and do the same for each.
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        mp[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();

            for (Node *neigh: curr->neighbors) {
                // if neighbour not cloned yet
                if (mp.find(neigh) == mp.end()) {
                    mp[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }

                // connect clone of curr to clone of neighbour
                mp[curr]->neighbors.push_back(mp[neigh]);
            }

        }

        return mp[node];

    }
};
