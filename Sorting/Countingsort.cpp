#include <iostream>
#include <vector>
#include <algorithm>

const int RANGE_LIMIT = 1000000;

int getMinValue(const std::vector<int>& vec)
{
	int minValue = vec[0];
	for(const int element : vec)
	{
		minValue = std::min(minValue, element);
	}
	return minValue;
}

int getMaxValue(const std::vector<int>& vec)
{
	int maxValue = vec[0];
	for(const int element : vec)
	{
		maxValue = std::max(maxValue, element);
	}
	return maxValue;
}

void countingSort(std::vector<int>& vec)
{

	int minValue = getMinValue(vec);
	int maxValue = getMaxValue(vec);
	int rangeSize = maxValue - minValue + 1; 
	if(rangeSize > RANGE_LIMIT)
	{
		std::cout << "WARNING: Counting sort may work slow - input range too wide." << std::endl;
	}

	int rangeBias = -minValue;

	std::vector<int> outputVec;
	std::vector<int> count(RANGE_LIMIT, 0);

	unsigned int n = vec.size();
	 
	for (unsigned int i = 0; i < n; ++i)
	{
		++count[vec[i] + rangeBias];
	}

	int nextToAssign = 0;
	for (unsigned int i = 0; i < rangeSize; ++i)
	{
		while(count[i] > 0)
		{
			vec[nextToAssign++] = i - rangeBias;
			--count[i];
		}
	}
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	
	for(int i=0; i < n; ++i)
	{
		std::cin >> vec[i];
	}

	countingSort(vec);

	std::cout << vec[0];
	for(int i=1; i < n; ++i)
	{
		std::cout << ' ' << vec[i];
	}
	std::cout << std::endl;
	
	return 0;
}
