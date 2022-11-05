class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        unordered_map<string, long long> mp;
        unordered_map<string, pair<int, string>> imp;
        long long mx = -1;
        for(int i = 0; i < creators.size(); ++i){
            long long v = views[i];
            if(mp.find(creators[i]) == mp.end()) mp[creators[i]] = v; 
            else mp[creators[i]] += v;
            if(mx < mp[creators[i]]) mx = mp[creators[i]];
            
            if(imp.find(creators[i]) == imp.end())   imp[creators[i]] = {views[i], ids[i]};
            else{                                                           //Evaluate max view for each creator
                if( imp[creators[i]].first < views[i])  imp[creators[i]] = {views[i], ids[i]};
                else if(imp[creators[i]].first == views[i] && imp[creators[i]].second > ids[i]){
                    imp[creators[i]] = {views[i], ids[i]};
                }
            }
        }
        
        vector<vector<string>> ans;
        for(auto m: mp){                         //scan for the creators with view equal to max
            if(mx == m.second){
                ans.push_back({m.first, imp[m.first].second});
            }
        }
        return ans;
    }
};