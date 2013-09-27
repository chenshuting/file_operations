/*
 * =====================================================================================
 *
 *       Filename:  create_write.cpp
 *
 *    Description:  create a file to write strings from standard input
 *
 *        Version:  1.0
 *        Created:  2013/09/27 09时14分13秒
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
using namespace std;
const int buffer_size = 256;

int main(int argc, char *argv[])
{
	if (argc < 2) {
		cout << argv[0] << " write_path" << endl;
		return 0;
	}
	ofstream outFile(argv[1]);
	if (!outFile) {
		cout << "Open " << argv[1] << " to write failed!" << endl;
		return 0;
	}

	int line = 0;
	char buffer[buffer_size];

	cout << "Enter lines you want to input:>";
	cin >> line;
	
	while (line-- > 0) {
		cin >> buffer;
		outFile << buffer << " ";
	}

	outFile.close();
	return 0;
}

