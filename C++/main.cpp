#include <stdio.h>
#include <vector>
#include "singleton.h"

using namespace std;

class Solution {
public:

    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        // write your code here

		size_t size = A.size();
		int begin = 0, end = size - 1;
		for (int outer_index = begin; outer_index <= end; ++outer_index) {

		}
    }

    int binarySearch(vector<int> &array, int target) {
		size_t size = array.size();
		int begin = 0, end = size - 1;

		int result = -1;
		while (begin < end) {
			int pos = (begin + end) / 2;

			if (array[pos] == target) {
				result = pos;
				end = pos;
			} else if (array[pos] > target) {
				end = pos - 1;
			} else if (array[pos] < target) {
				begin = pos + 1;
			}
		}
		
		if (array[begin] == target) {
			result = begin;
		}

        return result;
	}
};

int main() {

	Solution solution = Solution();
	int n[] = {1,4,4,5,7,7,8,9,9,10};
	vector<int> arr(n, n+9);
	int ret = solution.binarySearch(arr, 4);
printf("%d\n", ret);

	return 0;
	Singleton *singleton1 = Singleton::getInstance();
	Singleton *singleton2 = Singleton::getInstance();
	if (singleton1 != singleton2) {
		printf("yyyyyyyyy\n");
	}
	return 0;
}
