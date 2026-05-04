class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;

        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());

        // for (int i = 0; i < pair.size(); i++) {
        //     cout << "pos: " << pair[i].first << " speed: "<< pair[i].second << endl;
        // }

        vector<double> stack;

        for (auto &p: pair) {
            // stack has times in asc order as p.first are in desc order
            stack.push_back(1.0 * (target - p.first) / p.second);

            if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]) {
                stack.pop_back();
            }

        }

        return stack.size();
    }
};
