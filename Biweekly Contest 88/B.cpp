// 2424. Longest Uploaded Prefix
class LUPrefix {
public:
    int maxi = 0;
    map<int,int>mp;
    LUPrefix(int n) {
        maxi = 0;
    }
    
    void upload(int video) {
        mp[video] = 1;
        while(mp[maxi + 1] == 1)
            maxi++;
    }
    
    int longest() {
        return maxi;
    }
};