class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        size_t i = 0;
        int negative = 1;
        char tmp;
        while (i < str.size())
        {
            tmp = str[i++];
            if (tmp == ' ') continue;
            
            if (tmp == '+')
            {
                break;
            }
            else if (tmp == '-')
            {
                negative = -1;
                break;
            }
            
            if (tmp <= '9' && tmp >= '0') 
            {
                i --;
                break;
            }
            
            return 0;
        }
        
        for (; i<str.size(); i++)
        {
            tmp = str[i];
            if (tmp == ' ') break;
                        
            if (tmp <= '9' && tmp >= '0')
            {
                result = result * 10 + tmp - '0';
                
                if(result > INT_MAX)
                {
                    if (negative == -1) return INT_MIN;
                    else return INT_MAX;
                }
               
            }
            else
            {
                break;
            }
        }
        
        result = result * negative;
        if ( result > INT_MAX) return INT_MAX;
        if ( result < INT_MIN) return INT_MIN;
        return result;
    }
};