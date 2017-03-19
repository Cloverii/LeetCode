public class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for(int cur = 0; cur < s.length(); cur++) {
            char c = s.charAt(cur);
            if(st.empty() == false) {
                char top = st.peek();
                int i = transfer(c), j = transfer(top);
                if(j == (i ^ 1)) st.pop();
                else st.push(c);
            } else
                st.push(c);
        }
        return st.empty();
    }
    public int transfer(char c) {
        if(c == '(') return 0;
        else if(c == ')') return 1;
        else if(c == '{') return 2;
        else if(c == '}') return 3;
        else if(c == '[') return 4;
        else return 5;
    }
}
