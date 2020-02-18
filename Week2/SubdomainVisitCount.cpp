class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
                                
            if(cpdomains.empty()) return {};            
            unordered_map<string,int> dc;            
            
            for(auto s : cpdomains)
            {                    
                    int loc = (int)s.find(' ');
                    int count = stoi(s.substr(0,loc));                                                                   
                    while(loc != string::npos)
                    {
                            s = s.substr(loc+1);  
                            dc[s]+=count;                            
                            loc = s.find('.');
                    }                    
            }
            
            vector<string> visit;
            for( auto m : dc)
                visit.push_back(to_string(m.second) + " " + m.first);            
            
            return visit;
    }
};