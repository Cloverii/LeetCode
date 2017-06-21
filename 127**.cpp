class Solution {
private:
    bool __check(const string &s, const string &t) {
        int dif = 0;
        for(int i = 0; i < s.size(); i++)
            dif += s[i] != t[i];
        return dif == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int>> edge;
        edge.resize(wordList.size() + 1);
        vector<int> dis(wordList.size() + 1, INT_MAX);
        int st = wordList.size(), ed = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) ed = i;
            if(__check(wordList[i], beginWord)) edge[wordList.size()].push_back(i);
            for(int j = i + 1; j < wordList.size(); j++) {
                if(__check(wordList[i], wordList[j])) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        queue<int> q; q.push(st);
        dis[st] = 0;
        while(q.size()) {
            int u = q.front(); q.pop();
            if(u == ed) return dis[u] + 1;
            for(auto v: edge[u]) {
                if(dis[v] < INT_MAX) continue;
                q.push(v);
                dis[v] = min(dis[v], dis[u] + 1);
            }
        }
        return 0;
    }
};
