// 2406. Divide Intervals Into Minimum Number of Groups
//priority_queue
class Solution {
public:
    const static int ARRIVAL = 1;
    const static int DEPARTURE = 2;
    int minGroups(vector<vector<int>>& intervals) {
        auto cmp = [](auto &a, auto &b) {return a>b;};
        priority_queue<int , vector<int>, decltype(cmp)>pq(cmp);
        sort(begin(intervals), end(intervals));
        for(auto v:intervals){
            if(pq.size() and v[0]>pq.top()) pq.pop();
            pq.push(v[1]);
        }
        return pq.size();
    }
};



//sorting
class Solution {
public:
    const static int ARRIVAL = 1;
    const static int DEPARTURE = 2;
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>> A;
        for (auto& v : intervals) {
            A.push_back({v[0], ARRIVAL});
            A.push_back({v[1], DEPARTURE});
        }
        int res = 0, cur = 0;
        sort(A.begin(), A.end());
        for (auto& v : A)
            res = max(res, cur += (v[1] == ARRIVAL ? 1 : -1));
        return res;
    }
};