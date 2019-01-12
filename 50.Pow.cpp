class Solution {
public:
   double myPow(double value, int pow) {
	    double result = 1;
        if(pow < 0) 
            value = 1/value;
        while (pow != 0) {
            if (pow % 2)
                result *= value;
            value *= value;
            pow /= 2;
        }
        return result;
    }
};