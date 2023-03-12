class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    bool isReachable(int x, int y) {
        if (mp[x][y])
            return mp[x][y];
        bool flag = (x == 1 && y == 1) ||
                    (x % 2 == 0 && isReachable(x / 2, y)) ||
                    (y % 2 == 0 && isReachable(x, y / 2)) ||
                    (x > y && isReachable(x - y, y)) ||
                    (y > x && isReachable(x, y - x));
        return mp[x][y] = flag;
    }
};


class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int g = __gcd(targetX, targetY);
        return (g & (g - 1)) == 0; // check g is power of 2
    }
};
