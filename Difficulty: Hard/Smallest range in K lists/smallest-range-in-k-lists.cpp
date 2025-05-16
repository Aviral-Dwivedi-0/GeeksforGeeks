//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        // priority queue + consumer queue
        // The approach is to get the min element each time from the priority queue and add it to a consumer queue.
        // Now we will increment the frequency map counter for that row by 1.

        // We start polling the elements from the consumer queue until the frequency map has all rows present.
        // Start and end elements difference when we have frequence map == n then that will store the range
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        unordered_map<int, int> mp;
        queue<pair<int, int>> q;
        int ans = INT_MAX;
        vector<int> v = {-1, -1};
        
        int row = arr.size();
        int col = arr[0].size();
        for (int i = 0; i < row; i++){
            pq.push({arr[i][0], {i, 0}});
        }
        
        while (!pq.empty()){
            int min_val = pq.top().first;
            int min_index_row = pq.top().second.first;
            int min_index_col = pq.top().second.second;
            
            pq.pop();
            if (min_index_col + 1 < col) {
                pq.push({arr[min_index_row][min_index_col + 1], {min_index_row, min_index_col + 1}});
            }
            
            q.push({min_val, min_index_row});
            mp[min_index_row]++;
            // frequency added only incase when we are adding the data in the consumer cases
            while (mp.size() == row){
                if (ans > (q.back().first - q.front().first)){
                    v = {q.front().first, q.back().first};
                    ans = q.back().first - q.front().first;
                }
                
                int start = q.front().first;
                int index_row = q.front().second;
                q.pop();
                mp[index_row]--;
                if (mp[index_row] == 0) {
                    mp.erase(index_row);
                }
            }
        }
        
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends