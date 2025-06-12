class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        vector<int> ans;
        int n = arr.size();
        int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
        int right = left + 1;

        while (k > 0) {
            if (left >= 0 && (right >= n || abs(arr[left] - x) < abs(arr[right] - x))) {
                if (arr[left] != x) {
                    ans.push_back(arr[left]);
                    k--;
                }
                left--;
            } else {
                if (right < n && arr[right] != x) {
                    ans.push_back(arr[right]);
                    k--;
                }
                right++;
            }
        }

        return ans;
    }
};