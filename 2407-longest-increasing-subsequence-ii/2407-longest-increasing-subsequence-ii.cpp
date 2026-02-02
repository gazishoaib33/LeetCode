class Solution {
public:
    int seg[400005]; // segment tree
    
    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return seg[node];
        
        int mid = (l + r) / 2;
        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }
    
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = max(seg[node], val);
            return;
        }
        
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);
        
        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int ans = 0;
        int MAXV = 100000;
        
        for (int x : nums) {
            int left = max(1, x - k);
            int right = x - 1;
            
            int best = 0;
            if (left <= right)
                best = query(1, 1, MAXV, left, right);
            
            int curr = best + 1;
            update(1, 1, MAXV, x, curr);
            
            ans = max(ans, curr);
        }
        return ans;
    }
};
