// 273. Integer to English Words

class Solution {
public: // http://www.cnblogs.com/grandyang/p/4772780.html
    string number2hundred(int n) {
        string res = "";
        string digit1[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string digit2[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int a = n/100, b = n%100, c = n%10;
        res = (b<20)?digit1[b]:digit2[b/10]+(c?" "+digit1[c]:"");
        if (a) res = digit1[a]+" Hundred"+(b?" "+res:"");
        return res;
    }
    string numberToWords(int num) {
        string res = number2hundred(num%1000);
        string base[3] = {"Thousand", "Million", "Billion"};
        for (int i=0; i<3; i++) {
            num /= 1000;
            res = num%1000?number2hundred(num%1000)+" "+base[i]+" "+res:res;
        }
        while (res.back()==' ') res.pop_back();
        return res.empty()?"Zero":res;
    }
};