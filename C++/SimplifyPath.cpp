class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        string tok;
        path.append("/"); // Handle the case where path does not end with "/"

        for (int i = 0; i < path.size(); ++i) {
            string ch(1, path[i]);
            if (ch == "/") {
                if (tok.empty()) continue; // Consecutive slashes
                if (tok == "..") {
                    if (tokens.size() > 0) tokens.pop_back();
                } else if (tok != ".") {
                    tokens.push_back(tok);
                }
                tok = "";
            } else {
                tok.append(ch);
            }
        }

        string ret;
        for (string tok : tokens) {
            ret.append("/" + tok);
        }
        if (ret.empty()) return "/";
        return ret;
    }
};