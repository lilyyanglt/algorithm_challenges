/*
  Date: December 24, 2020

  Approach:
    * I am thinking of using the stack structure to ensure I keep track of the values and operators of + and -
    * if the operator is * or /, then I compute it right away and update the stack with the result of the computation
    * I will also push + or - into the stack
    * Then once I've completed going through the string, I then empty the stack one by one and perform calculations of + and -


  ORIGINAL SOLUTION:

  class Solution {
    public:
        int calculate(string s) {
            size_t size = s.size();
            
            std::stack<int> st;
            int i = 0;
            int result = 0;
                
            while (i < size) {
                if (s[i] == '*' && !st.empty()) {
                    st.push(atoi(st.top()) * atoi(s[i+1]));
                    st.pop();
                    i += 2;
                } else if (s[i] == '/' && !st.empty()) {
                    st.push(atoi(st.top()) * atoi(s[i+1]));
                    st.pop();
                    i += 2;
                } else if (s[i] != ' ') {
                    st.push(s[i]);
                    i++;
                }
            }
            
            while (st.size() > 1) {
                int digit = atoi(st.top());
                st.pop();
                if (st.top() == '+') {
                    st.pop();
                    st.push(st.top() + digit);
                    st.pop();
                } else if (st.top() == '-') {
                    st.pop();
                    st.push(st.top() - digit);
                    st.pop();
                }
            }
            
            return st.top();
            
        }
        
    };


  However, I didn't take into account that there could be double digit numbers, and also that I can't be creating a stack that holds numbers and then put a char inside the stack. So I reviewed the solution and realized that the solution was very close to my approach except that I didn't fully flush it out properly. 


*/

#include <iostream>
#include <string>
#include <stack>

class Solution {
  public:
    int calculate(std::string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }

        std::stack<int> resultStack;

        int currentNumber = 0;
        char operation = '+';

        for (int i = 0; i < s.size(); i++) {
          char currentChar = s[i];

          if (isdigit(currentChar)) {
            currentNumber = (currentNumber * 10) + (currentChar - '0');
          }

          if (!isdigit(currentChar) && !iswspace(currentChar) || i == size - 1) {

            if (operation == '-') {
              resultStack.push(currentNumber * -1);
            } else if (operation == '+') {
              resultStack.push(currentNumber);
            } else if (operation == '*') {
              int stackTop = resultStack.top();
              resultStack.pop();
              resultStack.push(stackTop * currentNumber);
            } else if (operation == '/') {
              int stackTop = resultStack.top();
              resultStack.pop();
            }

            operation = currentChar;
            currentNumber = 0;
          }
        }

        int result = 0;
        while (resultStack.size() != 0) {
          result += resultStack.top();
          resultStack.pop();
        }

        return result;
    }

};

int main() {

  Solution s;



  return 0;
}