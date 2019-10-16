// alg_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
public:
	int x;
	int y;
	Point(int x, int y) : x(x), y(y) {}
};

int main()
{
	cout << boolalpha;

	vector<Point> p1 = {
							Point(1,2),
							Point(3,4),
							Point(5,6)
						};

	vector<Point> p2 = {
							Point(1,2),
							Point(3,4),
							Point(5,6)
	};

	bool res = equal(begin(p1), end(p1), begin(p2), end(p2), [](const Point& p1, const Point& p2) {
		
		return ((p1.x == p2.x) && (p1.y == p2.y));
	});
	cout << "Is collection 1 equals collection 2: " << res << endl;

	return 0;
}
