// 2375. Construct Smallest Number From DI String
class Solution {
public:
    string smallestNumber(string pattern) {
        char num = '1';
        string res = "";
        string curr = "";
        for(char c:pattern){
            if(c == 'I'){
                curr.push_back(num);
                while(size(curr)){
                    res.push_back(curr.back());
                    curr.pop_back();
                }
                num++;
            }
            else{
                curr.push_back(num);
                num++;
            }
        }
        curr.push_back(num);
        while(size(curr)){
            res.push_back(curr.back());
            curr.pop_back();
        }
        return res;
    }
};