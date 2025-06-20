class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if(n % k != 0) return false;
        
        multiset <int> ms;
        for(int i = 0; i < n; i++) ms.insert(arr[i]);
        
        while(!ms.empty()){
            int st = *ms.begin();
            int cnt = 0;
            while(cnt < k){
                if(!ms.count(st)) return false;
                else{
                    ms.erase(ms.find(st));
                    st++, cnt++;
                }
            }
        }
        
        return true;
    }
};