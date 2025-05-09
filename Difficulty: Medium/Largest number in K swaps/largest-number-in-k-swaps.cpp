//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
     string maxNum;

    // function to explore all swap possibilities


    void solve(string &s, int k, int idx) {
        if (k == 0 || idx == s.length()) {
            if (s > maxNum) maxNum = s;
            return;
        }

        char maxDigit = s[idx];
        for (int i = idx + 1; i < s.length(); i++) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        }

        // If current digit is already max, find next without using a swap


        if (maxDigit == s[idx]) {
            solve(s, k, idx + 1);
        } else {
            for (int i = s.length() - 1; i > idx; i--) {
                if (s[i] == maxDigit) {
                    swap(s[i], s[idx]);
                    solve(s, k - 1, idx + 1);
                    swap(s[i], s[idx]); // backtrack
                }
            }
        }
    }

    
    string findMaximumNum(string s, int k) {
        maxNum = s;
        solve(s, k, 0);
        return maxNum;
    }
};



//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends