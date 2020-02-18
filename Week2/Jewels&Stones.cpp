class Solution {
public:
    int numJewelsInStones(string J, string S) {
            
            int arr[60] = {0};            
            for(auto c : J)            
                    arr[c - 'A'] = 1;
            
            int count = 0;
            for(auto s : S)
                if(arr[s - 'A'] == 1) count++;
            
           
            return count;
    }
};