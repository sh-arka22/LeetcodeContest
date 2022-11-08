// 2434. Using a Robot to Print the Lexicographically Smallest String
class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        // smaller char to the right
        vector<char>v(n);
        v[n-1]=s.back();
        for(int i=n-2;i>=0;i--)
            if(s[i]<v[i+1]) v[i]=s[i];
            else v[i]=v[i+1];
        
        string p="",t="";
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            
            // if there are not any mini char in s to right of i than t's last
            while(t.size()>0 and v[i]>=t.back()){
                p+=t.back() ;    // write last char on paper
                t.pop_back(); 
            }
    
            t+=c;
        }
        
        while(t.size()) {
            p+=t.back() ; 
            t.pop_back();
        }
        return p;
    }
};