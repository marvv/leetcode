class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size()-1;
        while (end >=0) {
            if (s[end] != ' ') break;
            end --;
        }
        if (end <0) return 0;
        if (end == 0) {
            if (s[end] == ' ') return 0;
            else return 1;
        }
        
        int begin = end ;
        while (begin >= 0) {
            if (s[begin] == ' ') break;
            begin --;
        }
        if (begin <0) begin=0;
        if (s[begin] ==  ' ') return end - begin;
        else return end - begin + 1;
    }
};