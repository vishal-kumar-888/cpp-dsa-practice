using namespace std;

// Segment tree: range max update, point query
struct SegTree {
    int n;
    vector<int> tree;
    SegTree(int n_) : n(n_), tree(4 * n_, INT_MIN) {}

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
    }
    void update(int l, int r, int val) {
        if (l > r) return;
        update(1, 0, n - 1, l, r, val);
    }

    int query(int node, int l, int r, int pos) {
        if (l == r) return tree[node];
        int mid = (l + r) / 2;
        int res = tree[node];
        if (pos <= mid) res = max(res, query(2 * node, l, mid, pos));
        else            res = max(res, query(2 * node + 1, mid + 1, r, pos));
        return res;
    }
    int query(int pos) { return query(1, 0, n - 1, pos); }
};

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = (int)arr.size();
        if (n == 0) return 0;
        if (k == 1) return n;

        auto mod = [&](long long x) -> int {
            int r = (int)(x % k);
            if (r < 0) r += k;
            return r;
        };

        // Prefix sums modulo k: pref[0..n]
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = mod((long long)pref[i] + arr[i]);

        // firstOcc[q] = smallest j with pref[j] == q
        // lastOcc[q]  = largest  j with pref[j] == q
        unordered_map<int, int> firstOcc, lastOcc;
        firstOcc.reserve(n * 2 + 5);
        lastOcc.reserve(n * 2 + 5);
        for (int j = 0; j <= n; j++) {
            int q = pref[j];
            if (!firstOcc.count(q)) firstOcc[q] = j;
            lastOcc[q] = j;
        }

        int ans = 0;

        // ---------- Case 1: no negation ----------
        {
            unordered_map<int, int> seen;
            seen.reserve(n * 2 + 5);
            for (int r = 0; r <= n; r++) {
                int q = pref[r];
                auto it = seen.find(q);
                if (it == seen.end()) seen[q] = r;
                else ans = max(ans, r - it->second);
            }
        }

        // ---------- Case 2: negate exactly one element ----------
        // Group indices i by t = 2*arr[i] mod k
        unordered_map<int, vector<int>> groups;
        groups.reserve(n * 2 + 5);
        for (int i = 0; i < n; i++) {
            int t = mod(2LL * arr[i]);
            groups[t].push_back(i);
        }

        // For each distinct t, answer max-value-over-intervals for each i in the group
        for (auto& g : groups) {
            int t = g.first;
            vector<int>& idxs = g.second;

            // Build intervals: for each q in firstOcc, if target exists,
            // interval [L, R] with value = lastOcc[target] - firstOcc[q]
            // where L = firstOcc[q], R = lastOcc[target] - 1
            vector<array<int, 3>> intervals; // {L, R, val}
            intervals.reserve(firstOcc.size());
            for (auto& kv : firstOcc) {
                int q = kv.first;
                int fq = kv.second;
                int target = mod((long long)q + t);
                auto it = lastOcc.find(target);
                if (it == lastOcc.end()) continue;
                int lb = it->second;         // lb >= fq + 1 always? Not necessarily
                int L = fq;
                int R = lb - 1;
                if (R < L) continue;         // no valid i
                intervals.push_back({L, R, lb - fq});
            }

            if (intervals.empty()) continue;

            // We only need to query positions that are in idxs.
            // Use coordinate compression on those positions.
            vector<int> pts = idxs;
            sort(pts.begin(), pts.end());
            pts.erase(unique(pts.begin(), pts.end()), pts.end());
            int m = (int)pts.size();

            // Map original i -> compressed position
            auto getPos = [&](int i) {
                return (int)(lower_bound(pts.begin(), pts.end(), i) - pts.begin());
            };

            SegTree st(m);
            for (auto& iv : intervals) {
                int L = iv[0], R = iv[1], val = iv[2];
                // Find range of pts within [L, R]
                int pl = (int)(lower_bound(pts.begin(), pts.end(), L) - pts.begin());
                int pr = (int)(upper_bound(pts.begin(), pts.end(), R) - pts.begin()) - 1;
                if (pl <= pr) st.update(pl, pr, val);
            }

            for (int i : idxs) {
                int v = st.query(getPos(i));
                if (v != INT_MIN) ans = max(ans, v);
            }
        }

        return ans;
    }
};
