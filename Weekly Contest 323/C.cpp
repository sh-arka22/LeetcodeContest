unordered_map<int, vector<pair<int, int>>> alloc;
map<int, int> avail;
Allocator(int n) { avail.insert({0, n}); }
int allocate(int size, int mID) {
    for (auto it = begin(avail); it != end(avail); ++it) {
        if (it->second >= size) {
            auto [i, i_sz] = *it;
            alloc[mID].push_back({i, size});
            avail.erase(it);
            if (i_sz > size) {
                avail.insert({i + size, i_sz - size});
            }
            return i;
        }
    }
    return -1;
}
int free(int mID) {
    int res = 0;
    if (auto it = alloc.find(mID); it != end(alloc)) {
        for (auto [i, sz] : it->second) {
            auto ita = avail.insert({i, sz}).first;
            if (ita != begin(avail)) {
                if (auto p = prev(ita); p->first + p->second == i) {
                    p->second += sz;
                    avail.erase(ita);
                    ita = p;
                }
            }
            if (next(ita) != end(avail)) {
                if (auto n = next(ita); i + sz == n->first) {
                    ita->second += n->second;
                    avail.erase(n);
                }
            }
            res += sz;
        }
        alloc.erase(it);
    }
    return res;
}