class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int gasSize = gas.size();
		int gasIndex = 0;

		int totalGas = 0;
		int totalCost = 0;

		int currentGas = 0;

		for (int i = 0; i < gasSize; ++i) {
			totalGas += gas[i];
			totalCost += cost[i];

			currentGas += gas[i] - cost[i];

			if (currentGas < 0) {
				gasIndex = i + 1;
				currentGas = 0;
			}
		}

		if (totalGas < totalCost) {
			return -1;
		}


		return gasIndex;
	}
};