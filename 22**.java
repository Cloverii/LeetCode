public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<String>();
        StringBuilder sb = new StringBuilder("");
        addParentheses(n * 2, 0, 0, sb, ans);
        return ans;
    }
    
    private void addParentheses(int n, int l, int m, StringBuilder sb, List<String> ans) {
        if(l + m >= n) {
            ans.add(sb.toString());
        } else {
            if(l < n / 2) { // < instead of <=
                addParentheses(n, l + 1, m, sb.append('('), ans);
                sb.deleteCharAt(l + m);
            }
            if(m < l) { // have single '('
                addParentheses(n, l, m + 1, sb.append(')'), ans);
                sb.deleteCharAt(l + m);
            }
        }
    }
}
