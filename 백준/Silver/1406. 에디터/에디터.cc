#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int N;
    char query;
    stack<char> s;

    cin >> str;
    cin >> N;

    while(N--) {
        cin >> query;
        switch(query) {
            case 'P':
                char c;
                cin >> c;
                str.push_back(c);
                break;
            case 'L':
                if(!str.empty()) {
                    s.push(str.back());
                    str.pop_back();
                }
                break;
            case 'D':
                if(!s.empty()) {
                    str.push_back(s.top());
                    s.pop();
                }
                break;
            case 'B':
                if(!str.empty())
                    str.pop_back();
        }
    }
    while(!s.empty()) {
        str.push_back(s.top());
        s.pop();
    }
    cout << str;

    return 0;
}