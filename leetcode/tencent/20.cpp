class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(auto c : s) {
            if(c=='(' || c=='{' || c=='[')
                sk.push(c);
            else {
                if(sk.empty()) return false;
                char left = sk.top();
                sk.pop();
                if((c==')'&&left!='(')||(c=='}'&&left!='{')||(c==']'&&left!='['))
                    return false;
            }
                   
        }
        
        return sk.empty();
    }
};