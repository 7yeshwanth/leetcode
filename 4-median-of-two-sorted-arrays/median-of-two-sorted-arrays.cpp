class Solution {
public:
    double findMedianSortedArrays(vector<int>& nmo, vector<int>& nms) {
        int no = nmo.size(), ns = nms.size();
        if (no > ns) {
            return findMedianSortedArrays(nms, nmo);
        }
        int n = no + ns;
        int lf = (n + 1) / 2;
        int lo = 0, hi = no;
        while (lo <= hi) {
            int mo = (lo + hi) / 2;
            int ms = lf - mo;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mo - 1 >= 0)
                l1 = nmo[mo - 1];
            if (ms - 1 >= 0)
                l2 = nms[ms - 1];
            if (mo < no)
                r1 = nmo[mo];
            if (ms < ns)
                r2 = nms[ms];
            int lf = max(l1, l2), ri = min(r1, r2);
            if (lf <= ri) {
                if (n % 2)
                    return lf;
                return (lf + ri) / 2.0;
            }
            if (l2 > r1) {
                lo = mo + 1;
            } else {
                hi = mo - 1;
            }
        }
        return 0;
    }
};