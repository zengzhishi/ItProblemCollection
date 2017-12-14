//使用一个栈来实现另一个栈的排序
//问题描述：一个栈中元素为整数，现在想将该栈从顶到底按照从大到小排序，
//        只允许申请一个栈，可以申请新的变量，但是不能使用其他数据结构

#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int> &toSort) {
    stack<int> help;
    int current;
    while (!toSort.empty()) {
        current = toSort.top();
        toSort.pop();
        if (help.empty()) {
            help.push(current);
        } else {
            while (!help.empty() && help.top() < current) {
                toSort.push(help.top());
                help.pop();
            }
            help.push(current);
        }
    }
    while (!help.empty()) {
        toSort.push(help.top());
        help.pop();
    }
}

int main() {
    stack<int> stackToSort;
    int list[] = {3, 4, 6, 1, 2};
    for (int i = 0; i < sizeof(list) / sizeof(list[0]); ++i) {
        stackToSort.push(list[i]);
    }
    sortStack(stackToSort);
    while (!stackToSort.empty()) {
        cout << stackToSort.top() << endl;
        stackToSort.pop();
    }
    return 0;
}