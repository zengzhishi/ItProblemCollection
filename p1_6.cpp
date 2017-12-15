//利用栈来求解汉诺塔问题
//问题描述： 除了传统汉诺塔的描述，这里添加一个限制，限制不能从最左侧的塔直接移动到最右侧的塔，
//          也不能从最左侧的塔直接移动到最右侧的塔，而是必须经过中间，求当塔有N层时，
//          打印最优移动过程和最优移动总步数.

#include <iostream>
#include <stack>

using namespace std;

void move(string src, string dest, int &steps) {
    cout << src << "---->" << dest << endl;
    ++steps;
}

int hanoi(int n, string src, string mid, string dest, int &steps) {
    if (n == 1) {
        move(src, mid, steps);
        move(mid, dest, steps);
    } else {
        hanoi(n - 1, src, mid, dest, steps);
        move(src, mid, steps);
        hanoi(n - 1, dest, mid, src, steps);
        move(mid, dest, steps);
        hanoi(n - 1, src, mid, dest, steps);
    }
}

//利用递归的方法
int hanoiProblem(int n, string src, string mid, string dest) {
    int steps = 0;
    if (n >= 1) {
        hanoi(n, src, mid, dest, steps);
    }
    return steps;
}

void judgeAndMove(int &steps, stack<int> &from, stack<int> &to, string src, string dest) {
    if (from.top() < to.top()) {
        to.push(from.top());
        from.pop();
        move(src, dest, steps);
    } else {
        from.push(to.top());
        to.pop();
        move(dest, src, steps);
    }
}

//利用栈迭代的方法
//推理：由于每一个步只能往相邻的栈移动，因此可以发现每次能移动的只能有四种可能，LM, ML, MR, RM
//条件推理：
//      1.再根据大数字不能再小数字之上，可以知道不能和上一步采取同样的步骤
//      2.如果和上次的方向是相逆的，比如（LM 和 ML）相当于还原，没有意义，因此排除
//      3.排除了逆向之后可以发现可以采取的两种移动步骤，会因为大小问题，只有一个满足
//因此实际上每次移动只有一种正确的步骤，只要每次判断大小和上一步的类型就可以推理出唯一的下一步，迭代直到right栈元素足够多就行了
int hanoiProblem2(int n, string src, string mid, string dest) {
    int steps = 0;
    if (n >= 1) {
        stack<int> sleft, smid, sright;
        sleft.push(n + 1);
        smid.push(n + 1);
        sright.push(n + 1);
        for (int i = n; i > 0; --i) {
            sleft.push(i);
        }
        string last_action = "";
        while (sright.size() < n + 1) {
            if (last_action != "LM") {
                judgeAndMove(steps, sleft, smid, src, mid);
                last_action = "LM";
            } else {
                last_action = "MR";
                judgeAndMove(steps, smid, sright, mid, dest);
            }
        }
    }
    return steps;
}

int main() {
    int N = 2, steps = 0;
    steps = hanoiProblem2(N, "A", "B", "C");
    cout << "All walks " << steps << endl;
    return 0;
}