#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    int count;
    cin >> str >> count;

    stack<char> left, right;
    for (char ch : str) {
        left.push(ch);
    }

    while (count--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        }
        else if (cmd == 'P') {
            char ch;
            cin >> ch;
            left.push(ch);
        }
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
    return 0;
}