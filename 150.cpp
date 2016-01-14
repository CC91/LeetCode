// 150. Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> op;
        for (int i=0; i<tokens.size(); i++) {
            if ((tokens[i][0]=='-' && tokens[i].size()>1) || (tokens[i][0]>='0' && tokens[i][0]<='9')) {
                op.push(stoi(tokens[i])); // above is the negative integer and positive integer statement
                continue;
            }
            int op1 = op.top();
            op.pop();
            int op2 = op.top();
            op.pop();
            
            if (tokens[i]=="+") op.push(op2+op1);
            if (tokens[i]=="-") op.push(op2-op1);
            if (tokens[i]=="*") op.push(op2*op1);
            if (tokens[i]=="/") op.push(op2/op1);
        }
        return op.top();
    }
};