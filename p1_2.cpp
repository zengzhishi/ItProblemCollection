//编写一个类，用两个栈来实现队列，支持队列的基本操作（add， poll， peek）
//peek 指查看队列的头元素
//TODO: 可以思考一下如何实现 c++ 里面的 back(), front()

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stackPush;
    stack<int> stackPop;

public:
    void add (int value) {
        stackPush.push(value);
    }

    int poll () {
        if (stackPush.empty() && stackPop.empty()) {
            throw "stack is empty!";
        } else if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        int value = stackPop.top();
        stackPop.pop();
        return value;
    }

    int peek () {
        if (stackPush.empty() && stackPop.empty()) {
            throw "stack is empty!";
        } else if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
        return stackPop.top();
    }
};


int main () {
    MyQueue queue;
    queue.add(1);
    queue.add(2);
    queue.add(3);
    try {
        cout << queue.peek() << endl;
        queue.poll();
        cout << queue.peek() << endl;
        queue.poll();
        queue.poll();
        cout << queue.peek() << endl;
    } catch (const char *msg) {
        cout << msg << endl;
    }
    return 0;
}