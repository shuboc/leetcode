class Solution {
public:
    string intToRoman(int num) {
        string ret;
        int thousand = num / 1000;
        for (int i=0; i<thousand; i++) ret.append("M");
        
        int hundred = (num % 1000) / 100;
        ret.append(digitToRoman(hundred, "M", "D", "C"));
        
        int ten = num % 100 / 10;
        ret.append(digitToRoman(ten, "C", "L", "X"));
        
        int one = num % 10;
        ret.append(digitToRoman(one, "X", "V", "I"));
        
        return ret;
    }
    
    string digitToRoman(int num, string ten, string five, string one) {
        string ret;
        switch (num) {
            case 9:
                ret.append(one);
                ret.append(ten);
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                ret.append(five);
                for (int i=5; i<num; ++i) ret.append(one);
                break;
            case 4:
                ret.append(one);
                ret.append(five);
                break;
            case 3:
            case 2:
            case 1:
                for (int i=0; i<num; ++i) ret.append(one);
                break;
            default:
                break;
        }
        
        return ret;
    }
};