/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Bryan Valarezo
 * Date        : 09/27/2016
 * Description : Lists the number of ways to climb n stairs.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector<vector<int> > get_ways(int num_stairs) {
	// Return a vector of vectors of ints representing
	// the different combinations of ways to climb num_stairs
	// stairs, moving up either 1, 2, or 3 stairs at a time.
	vector<vector<int> > ways;
	vector<int> blank;

	if (num_stairs <= 0) {
		ways.push_back(blank);
	} else {
		for (int i = 1; i < 4; i++) {
			if (num_stairs >= i) {
				vector<vector<int> > result = get_ways(num_stairs - i);
				for (unsigned int j = 0; j < result.size(); j++) {
					result.at(j).push_back(i);
				}
				ways.insert(ways.end(), result.begin(), result.end());
			}
		}
	}
	return ways;
}

int num_digits(int num) {
	if (num < 10) {
		return 1;
	} else {
		return 1 + num_digits(num / 10);
	}
}

void display_ways(const vector<vector<int> > &ways) {
	// Display the ways to climb stairs by iterating over
	// the vector of vectors and printing each combination.
	//reverse

	for (unsigned int i = 0; i < ways.size(); i++) {
		if (ways.size() > 9) {
			cout << setw(num_digits(ways.size()));
		}
		cout << i + 1 << ". " << "[";
		for (unsigned int j = ways[i].size() - 1; j > 0; j--) {
			cout << ways[i][j] << ", ";
		}
		cout << ways[i][0];
		cout << "]" << endl;
	}
}

int main(int argc, char * const argv[]) {
	int number;

	istringstream iss;

	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " <number of stairs>" << endl;
		return 1;
	}

	if (argc > 2) {
		cerr << "Usage: " << argv[0] << " <number of stairs>" << endl;
		return 1;
	}

	iss.str(argv[1]);
	if (!(iss >> number)) {
		cerr << "Error: Number of stairs must be a positive integer." << endl;
		return 1;
	}
	iss.clear();

	if (number <= 0) {
		cerr << "Error: Number of stairs must be a positive integer." << endl;
		return 1;
	}

	int cb = get_ways(number).size();

	if (number == 1) {
		cout << cb << " way to climb " << number << " stair." << endl;
	} else {
		cout << cb << " ways to climb " << number << " stairs." << endl;
	}
	display_ways(get_ways(number));
	return 0;
}
