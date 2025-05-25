class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(auto &it:arr)it *= it;
        sort(arr.begin(), arr.end());
        for(int i=n-1; i>1; i--){
            int l=0, h = i-1;
            if(i<n-1 && arr[i]==arr[i+1])continue;
            while(l<h){
                int sum = arr[l] + arr[h];
                if(sum==arr[i])return true;
                else if(sum<arr[i])l++;
                else h--;
            }
        }
        return false;
    }
};