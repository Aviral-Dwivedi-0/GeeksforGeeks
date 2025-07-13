#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark present letters
        for (const auto &word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Build the graph
        int N = words.size();
        for (int i = 0; i < N - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    indegree[w2[j] - 'a']++;
                    found = true;
                    break;
                }
            }
            if (!found && w1.size() > w2.size()) {
                // Prefix case: invalid
                return "";
            }
        }

        // Topological Sort using Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans += (char)(u + 'a');
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If cycle exists: not all present letters are in the result
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) count++;
        }

        if (ans.size() != count) return "";

        return ans;
    }
};
