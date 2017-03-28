public class Solution {
    String[] strs = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<String>();
        if(digits.length() == 0) return ans;
        StringBuilder sb = new StringBuilder(""); 
        addLetter(sb, digits, 0, ans);
        return ans;
    }
    
    private void addLetter(StringBuilder prefix, String digits, int i, List<String> ans) {
        if(i == digits.length()) {
            ans.add(prefix.toString());
            return;
        } else {
            int id = digits.charAt(i) - '0';
            int len = prefix.length();
            for(char c: strs[id].toCharArray()) {
                addLetter(prefix.append(c), digits, i + 1, ans);
                prefix.	deleteCharAt(len); // not len - 1 !
            }
            return;
        }
    }
}
