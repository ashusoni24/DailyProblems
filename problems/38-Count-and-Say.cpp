The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";}
            string say = countAndSay(n-1);
            //prcoessing
            string result = "";
            for(int i = 0 ; i<say.length();i++){
                char ch = say[i];
                int count = 1;
                while(i<say.length()-1 and say[i]==say[i+1]){
                    count++;
                    i++; 
                }
                result += to_string(count)+ string(1,ch);
            }
        
        return result;
    }
};
