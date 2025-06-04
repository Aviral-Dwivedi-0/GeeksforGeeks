// User function template for C++
class Solution {
  public:
    // #define ll long long
    int countStrings(int n) {
        // code here
        int zero_ending=1;
        int one_ending=1;
        int sum=zero_ending+one_ending;
        if(n==1) return sum;
        int i=2;
        while(i<=n){
            one_ending=zero_ending;
            zero_ending=sum;
            sum=one_ending+zero_ending;
            i++;
        }
        return sum;
    }
};