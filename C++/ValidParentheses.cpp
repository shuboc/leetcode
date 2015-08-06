class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            char l = s[i];
            if (l == '(' || l == '{' || l == '[')
                st.push(l);
            else {
                if (st.empty())
                    return false;

                char l = st.top(), r = s[i];
                if (l == '(' && r != ')'
                    || l == '[' && r != ']'
                    || l == '{' && r != '}')
                    return false;
                st.pop();
            }
        }
        
        if (!st.empty())
            return false;
        return true;
    }
};