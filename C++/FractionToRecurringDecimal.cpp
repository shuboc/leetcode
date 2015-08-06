class Solution {
public:
    string fractionToDecimal(int num, int dem ) {
        string ret;

        long numerator = num;
        long denominator = dem;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            ret.append("-");
            
        numerator = abs(numerator);
        denominator = abs(denominator);

        long i = numerator / denominator;
        ret += to_string(i);
        unordered_map<long, long> remainder;
        
        string tmp;
        long left = numerator - denominator * i;
        bool repeat = false;
        int start = 0, end = 0;
        while (left > 0) {
            if (remainder.find(left) == remainder.end()) {
                
                remainder[left] = end++;
                left *= 10;
                i = left / denominator;
                tmp.append(to_string(i));
                left %= denominator;
                
            } else {
                repeat = true;
                start = remainder[left];
                break;
            }
        }
        
        if (repeat) {
            tmp.insert(start, "(");
            tmp.insert(end+1, ")");
        }
        
        if (tmp.size())
            ret.append("." + tmp);
            
        return ret;
    }
};