class Solution {
public:
	string multiply(string num1, string num2) {
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string res(num1.size() + num2.size(), '0');
		
		for (int i = 0; i < num1.size(); ++i) {
			// Carry from the result of previous digit
		    int carry = 0;
			for (int j = 0; j < num2.size(); ++j) {
			    char ch1 = num1.at(i), ch2 = num2.at(j);
				int num = (num1[i] - '0') * (num2[j] - '0') + (res[i + j] - '0') + carry;
				res[i + j] = (num % 10) + '0';
				carry = num / 10;
			}

			if (carry > 0) {
			    res[num2.size() + i] = carry + '0';
			}
		}
		
		int i = res.size() - 1;
		while (i > 0 && res[i] == '0') --i;
		res.erase(i+1);

		reverse(res.begin(), res.end());
		return res;
	}
};