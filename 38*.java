public class Solution {
    public String countAndSay(int n) {
        StringBuilder sb = new StringBuilder("1");
        for(int i = 0; i < n - 1; i++) {
            sb = trans(sb);
        }
        return sb.toString();
    }
    
    private StringBuilder trans(StringBuilder sb) {
        if(sb.length() == 0) return sb;
        StringBuilder ret = new StringBuilder();
        char pre = sb.charAt(0), cur = sb.charAt(0);
        for(int i = 0; i < sb.length(); i++) {
            int cnt = 1;
            while(i + 1 < sb.length() && sb.charAt(i) == sb.charAt(i + 1)) {
                cnt++;
                i++;
            }
            ret.append(Integer.toString(cnt));
            ret.append(sb.charAt(i));

        }
        return ret;
    }
}
