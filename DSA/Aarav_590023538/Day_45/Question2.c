java
class Solution {
    public long countInv(int[] a) {
        int[] tmp = new int[a.length];
        return sort(a, tmp, 0, a.length - 1);
    }
    
    private long sort(int[] a, int[] tmp, int l, int r) {
        long cnt = 0;
        
        if (l < r) {
            int m = l + (r - l) / 2;
            
            cnt += sort(a, tmp, l, m);
            cnt += sort(a, tmp, m + 1, r);
            cnt += merge(a, tmp, l, m, r);
        }
        
        return cnt;
    }
    
    private long merge(int[] a, int[] tmp, int l, int m, int r) {
        int i = l, j = m + 1, k = l;
        long cnt = 0;
        
        while (i <= m && j <= r) {
            if (a[i] <= a[j]) {
                tmp[k++] = a[i++];
            } else {
                tmp[k++] = a[j++];
                cnt += (m - i + 1);
            }
        }
        
        while (i <= m) tmp[k++] = a[i++];
        while (j <= r) tmp[k++] = a[j++];
        
        for (i = l; i <= r; i++) a[i] = tmp[i];
        
        return cnt;
    }
    
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.countInv(new int[]{2, 4, 1, 3, 5})); // 3
        System.out.println(s.countInv(new int[]{5, 4, 3, 2, 1})); // 10
        System.out.println(s.countInv(new int[]{1, 2, 3, 4, 5})); // 0
    }
}
