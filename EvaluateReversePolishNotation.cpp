class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for (string t : tokens) {
            int a, b;
            if (t == "+") {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                s.push(b+a);
            } else if (t == "-") {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                s.push(b-a);
            } else if (t == "*") {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                s.push(b*a);
            } else if (t == "/") {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                s.push(b/a);
            } else {
                s.push(stoi(t));
            }
        }
        
        return s.top();
    }
};