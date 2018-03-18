class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char tmp;
        char top;
        for (size_t i = 0; i<s.size(); i++)
        {
            tmp = s[i];
            if(tmp == '(' || tmp == '{' || tmp == '[')
            {
                st.push(tmp);
            }
            else
            {
                if (st.empty()) return false;
                top = st.top();
                if ( (tmp == ')' && top == '(') || 
                     (tmp == ']' && top == '[') || 
                     (tmp == '}' && top == '{') )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        
        return st.empty()? true : false;
    }
};