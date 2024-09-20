#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    for (std::string str : babbling) {

        size_t pos = str.find("aya");
        while (pos != std::string::npos) {
            str.replace(pos, 3, " ");
            pos = str.find("aya", pos);
        }

        pos = str.find("ye");
        while (pos != std::string::npos) {
            str.replace(pos, 2, " ");
            pos = str.find("ye", pos);
        }

        pos = str.find("woo");
        while (pos != std::string::npos) {
            str.replace(pos, 3, " ");
            pos = str.find("woo", pos);
        }

        pos = str.find("ma");
        while (pos != std::string::npos) {
            str.replace(pos, 2, " ");
            pos = str.find("ma", pos);
        }
        bool check = true;
        for (char c : str) {
            if (c != ' ') {
                check = false;
            }
        }
        if (check) {
            answer += 1;
        }
    }


    return answer;
}
