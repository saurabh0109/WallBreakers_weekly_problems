class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
            vector<string> s;
            if(n == 0) return s;
            
            map<int,string> fizzbuzzDict { {3,"Fizz"} , {5,"Buzz"}};
            int i=1;
            while(i<=n)
            {
                    string str="";
                    for(auto k : fizzbuzzDict)                    
                           if(i%k.first == 0) str+=k.second;                   
                    if(str.empty()) str+=to_string(i);
                    i++;
                    s.push_back(str);
            }
            
            return s;
            
    }
};