class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        vector<string> s;
        while(i < path.size()) {
            if(path[i] == '/') {
                string tmp = "/";
                while(i + 1 < path.size() && path[i + 1] == '/') i++;
                while(++i < path.size() && path[i] != '/') {
                    tmp += path[i];
                }
                if(tmp == "/..") {if(s.size()) s.pop_back();}
                else if(tmp == "/.") continue;
                else if(tmp != "/") {
                    s.push_back(tmp);
                }
            }
        }
        string ans;
        for(auto &tmp: s) ans += tmp;
        if(ans == "") ans += '/';
        return ans;
    }
};
