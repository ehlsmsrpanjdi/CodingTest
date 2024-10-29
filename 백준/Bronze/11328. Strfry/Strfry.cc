#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N = 0;
    bool test = false;
    std::string str = "";
    cin >> N;
    std::cin.ignore();

    while (N--) {
        std::map<char, int> smap;
        std::map<char, int> vmap;

        // 첫 번째 문자열 입력
        std::getline(std::cin, str, ' ');
        for (char c : str) {
            ++smap[c];
        }

        // 두 번째 문자열 입력
        std::getline(std::cin, str);
        for (char c : str) {
            ++vmap[c];
        }

        // 두 맵 비교
        test = false;
        for (auto& pair : smap) {
            if (smap[pair.first] != vmap[pair.first]) {
                test = true;
                break;
            }
        }

        // 결과 출력
        if (test) {
            std::cout << "Impossible\n";
        } else {
            std::cout << "Possible\n";
        }
    }
    return 0;
}