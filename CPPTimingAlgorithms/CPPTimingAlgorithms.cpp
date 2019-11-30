// CPPTimingAlgorithms.cpp - by Michael G. Workman
//
// This C++ console application shows how to time algorithms using the clock
//
// This example freely distributable under terms of MIT open source license

#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
	// create a type for seconds
	typedef double seconds;

	// create vector and populate with consecutive integers
	vector<int> v(1000000);
	int i = 0;
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		(*it) = i;
		i++;
	}

	// start timing the sort of vector of consecutive integers
	clock_t consecutiveStart = clock();
	sort(v.begin(), v.end());
	clock_t consecutiveEnd = clock();

	// shuffle the vector, then start timing the sort of the vector of shuffled integers
	random_shuffle(v.begin(), v.end());
	clock_t shuffledStart = clock();
	sort(v.begin(), v.end());
	clock_t shuffledEnd = clock();

	// determine the time in seconds of the sort of vector of consecutive integers
	seconds consecutiveTime = ((double) consecutiveEnd - consecutiveStart) / (double) CLOCKS_PER_SEC;

	// determine the time in seconds of the sort of vector of shuffled integers
	seconds shuffledTime = ((double) shuffledEnd - shuffledStart) / (double) CLOCKS_PER_SEC;

	// output results
	cout << "Time to sort a consecutive vector: "
		<< consecutiveTime << " seconds" << endl;

	cout << "Time to sort a shuffled vector: "
		<< shuffledTime << " seconds" << endl;

	return 0;
}


