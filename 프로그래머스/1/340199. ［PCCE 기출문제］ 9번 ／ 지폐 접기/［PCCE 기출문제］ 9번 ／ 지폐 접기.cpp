#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    int big, small;
    int Mbig, Msmall;

    if (wallet[1] >= wallet[0]) {
        big = wallet[1];
        small = wallet[0];
    }
    else {
        big = wallet[0];
        small = wallet[1];
    }

    if (bill[1] >= bill[0]) {
        Mbig = bill[1];
        Msmall = bill[0];
    }
    else {
        Mbig = bill[0];
        Msmall = bill[1];
    }

    while (true) {
        if (Mbig > big) {
            Mbig /= 2;
            if (Mbig < Msmall) {
                int temp = Msmall;
                Msmall = Mbig;
                Mbig = temp;
            }
            ++answer;
            continue;
        }

        else if (Msmall > small) {
            Mbig /= 2;
            if (Mbig < Msmall) {
                int temp = Msmall;
                Msmall = Mbig;
                Mbig = temp;
            }
            ++answer;
            continue;
        }

        break;

    }

    return answer;
}