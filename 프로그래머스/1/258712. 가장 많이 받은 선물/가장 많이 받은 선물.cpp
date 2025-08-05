#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;

	std::unordered_map<string, std::unordered_map<string, int>> giftMap;
	std::unordered_map<string, int> giftPointMap;
	std::unordered_map<string, int> totalGiftCount;
	std::unordered_map<string, bool> isCheck;

	std::string gainedPeople;
	std::string givePeople;

	for (int i = 0; i < friends.size(); ++i) {
		for (int j = 0; j < friends.size(); ++j) {
			if (i == j) {
				continue;
			}
			giftMap[friends[i]][friends[j]];
		}
	}


	for (string& str : gifts) {
		int blinkLocation = str.find(' ');
		gainedPeople = str.substr(blinkLocation + 1);
		givePeople = str.erase(blinkLocation);

		++giftMap[givePeople][gainedPeople];

		++giftPointMap[givePeople];
		--giftPointMap[gainedPeople];
	}

	int MaxGiftCount = 0;

	//선물 몇 개 줬는가  
	for (std::pair<const std::string, std::unordered_map<std::string, int>>& pair : giftMap) {  //a가
		isCheck[pair.first] = true;
		for (std::pair<const std::string, int> ppair : pair.second) {  // 선물 준 b,c,d 사람들에게 준 선물 개수 확인
			if (isCheck[ppair.first] == true) {
				continue;
			}
			std::cout << pair.first << "랑 " << ppair.first << "랑 선물 비교 중" << std::endl;
			std::cout << pair.first << "가 준 선물 개수 : " << ppair.second << '\n' << ppair.first << "가 준 선물 개수 : " << giftMap[ppair.first][pair.first] << std::endl;

			if (ppair.second < giftMap[ppair.first][pair.first]) {  //b가 준 선물 개수가 a가 준 선물 개수가 더 많다면
				++totalGiftCount[ppair.first];
				if (MaxGiftCount < totalGiftCount[ppair.first]) {
					MaxGiftCount = totalGiftCount[ppair.first];
				}
			}
			else if (ppair.second > giftMap[ppair.first][pair.first]) {
				++totalGiftCount[pair.first];
				if (MaxGiftCount < totalGiftCount[pair.first]) {
					MaxGiftCount = totalGiftCount[pair.first];
				}
			}
			else {//만약 둘이 서로 같은 개수의 선물을 줬다면 선물점수가 높은애가 선물을 받아야함
				std::cout << pair.first << "랑 " << ppair.first << "랑 선물개수 같음" << std::endl;
				std::cout << pair.first << "의 선물 점수 : " << giftPointMap[pair.first] << '\n' << ppair.first << "의 선물 점수" << giftPointMap[ppair.first] << std::endl;
				if (giftPointMap[ppair.first] < giftPointMap[pair.first]) {
					++totalGiftCount[pair.first];
					if (MaxGiftCount < totalGiftCount[pair.first]) {
						MaxGiftCount = totalGiftCount[pair.first];
					}
				}
				else if (giftPointMap[ppair.first] > giftPointMap[pair.first]) {
					++totalGiftCount[ppair.first];
					if (MaxGiftCount < totalGiftCount[ppair.first]) {
						MaxGiftCount = totalGiftCount[ppair.first];
					}
				}
			}
			std::cout << '\n';
		}
	}
	return MaxGiftCount;
}