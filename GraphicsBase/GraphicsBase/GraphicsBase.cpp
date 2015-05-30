// GraphicsBase.cpp : Defines the entry point for the console application.
//

#include "base/Vector3.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	Vector3 v(1, 2, 3);
	Vector3 a(2, 1, 2);

	cout << v*a << endl;

	Vector3 l = crossProduct(v, a);

	cout << l.x << l.y << l.z << endl;
	getchar();
	return 0;
}

