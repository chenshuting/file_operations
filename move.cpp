/*
 * =====================================================================================
 *
 *       Filename:  move.cpp
 *
 *    Description:  move file from path1 to path2
 *
 *        Version:  1.0
 *        Created:  2013/09/27 09时13分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Shuting (cst), cicy0125@gmail.com
 *        Company:  gucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 3) {
		cout << argv[0] << " path1 path2" << endl;
		return 0;
	}

	string path1(argv[1]);
	string path2(argv[2]);

	fstream file;
	file.open(path1.c_str(), ios::in);
	if (!file) {
		cout << "File:" << path1 << " is not exist!" << endl;
	}
	file.close();

	rename(path1.c_str(), path2.c_str());

	return 0;
}
