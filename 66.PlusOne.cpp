class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum =0;
        for (int i=0;i<digits.size();i++) {
            sum = sum*10 + digits[i];
        }
        
        sum ++;
        vector<int> tmp;
        while (sum > 0) {
            tmp.push_back(sum % 10);
            sum = sum / 10;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};