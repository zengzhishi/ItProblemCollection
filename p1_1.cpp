//实现一个栈，能返回最小元素（或者最大元素）
//要求：1.可使用现成的栈结构    2.pop、push和getMin操作都是O(1)复杂度
#include <iostream>
#include <stack>

using namespace std;

class StackForMin{
private:
    stack<int> stackData;
    stack<int> stackMin;
    
public:
    void push(int newNum) {
        if (stackMin.empty()) {
            stackMin.push(newNum);
        } else if (newNum <= stackMin.top()) {
            stackMin.push(newNum);
        }
        stackData.push(newNum);
    }

    int pop() {
        if (stackData.empty()) {
            throw "Stack is empty!";
        }
        int value = stackData.top();
        stackData.pop();
        if (value == stackMin.top()) {
            stackMin.pop();
        }
        return value;
    }

    int getMin() {
        if (stackData.empty()) {
            throw "Stack is empty";
        }
        return stackMin.top();
    }
};


int main () {
    StackForMin stack;
    stack.push(3);
    stack.push(4);
    try {
        cout << stack.getMin() << endl;
        stack.push(1);
        cout << stack.getMin() << endl;
        stack.pop();
        cout << stack.getMin() << endl;
        stack.pop();
        stack.pop();
        stack.pop();
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    return 0;
}
