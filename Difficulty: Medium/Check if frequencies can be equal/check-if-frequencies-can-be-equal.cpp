class Solution {
  public:
   bool sameFreq(string& s) {
        // code here
        sort(s.begin(),s.end());
        unordered_map<int,int> m;
        int n=s.size();
        int low=0,high=0;
        while(low<n){
            if(high<n && s[low]==s[high]){
                high++;
            }
            else{
                m[high-low]++;
                low=high;
            }
        }
        if(m.size()>2)return false;
        else if(m.size()==1)return true;
        auto it=m.begin();
           int  firstlen=it->first;
           int  firstfreq=it->second;
            it++;
           int  seclen=it->first;
           int  secfreq=it->second;
            
        
        if(firstfreq!=1 && secfreq!=1)return false;
        if((firstlen==1 && firstfreq==1) || (seclen==1 && secfreq==1) )return true;
        if(abs(firstlen-seclen) >1)return false;
        if((firstlen>seclen && firstfreq==1) || (seclen>firstlen && secfreq==1))return true;
        return false;
   }
};