public class Solution {
    public int strStr(String haystack, String needle) {
        int l1 = haystack.length(), l2 = needle.length();
        for(int i = 0; i <= l1 - l2; i++) {
            if(match(haystack, needle, i) == 0)
                return i;
            
        }
        return -1;
    }
    
    private int match(String str, String sub, int i) {
        for(int j = 0; j < sub.length(); j++) {
            if(str.charAt(i++) != sub.charAt(j))
                return -1;
        }
        return 0;
    }
}
