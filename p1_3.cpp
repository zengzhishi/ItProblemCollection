//利用递归逆序一个栈, 只能使用递归函数，不能使用其他数据结构

#include <iostream>
#include <stack>

using namespace std;

int getLastElementAndDelete(stack<int> &store) {
    int value = store.top(), last;
    store.pop();
    if (!store.empty()) {
        last = getLastElementAndDelete(store);
        store.push(value);
    } else last = value;
    return last;
}


void reverse(stack<int> &store) {
    if (store.empty()) return;
    int last = getLastElementAndDelete(store);
    reverse(store);
    store.push(last);
}


int main() {
    stack<int> store;
    int input_list[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(input_list) / sizeof(input_list[0]); ++i) {
        store.push(input_list[i]);
    }

    reverse(store);

    cout << "=============== result =================" << endl;
    while (!store.empty()) {
        cout << store.top() << endl;
        store.pop();
    }
    cout << "========================================" << endl;
    return 0;
}