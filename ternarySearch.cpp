/*
 * Both function returns the index of peak/vallye not the actual value of peak/valley.
 */

int getPeak(vector<int>& a) {
    int l = 0, r = a.size() - 1;
    int peak = 0;
    while (l <= r) {
        int mid1 = r - (r - l) / 3;
        int mid2 = l + (r - l) / 3;
        int val1 = a[mid1];
        int val2 = a[mid2];
        if (val1 < val2) {
            r = mid1 - 1;
        }
        else {
            peak = mid2;
            l = mid2 + 1;
        }
    }
    return peak;
}

int getValley(vector<int>& a) {
    int l = 0, r = a.size() - 1;
    int valley = 0;
    while (l <= r) {
        int mid1 = r - (r - l) / 3;
        int mid2 = l + (r - l) / 3;
        int val1 = a[mid1];
        int val2 = a[mid2];
        if (val1 > val2) {
            r = mid1 - 1;
        }
        else {
            valley = mid2;
            l = mid2 + 1;
        }
    }
    return valley;
}
