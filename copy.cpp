/*
 * =====================================================================================
 *
 *       Filename:  copy.cpp
 *
 *    Description:  copy file from path1 to path2
 *
 *        Version:  1.0
 *        Created:  2013/09/27 09时13分27秒
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

//Note:the buffer_size should bigger than the maximun chars in one line
const int buffer_size = 256;

int main(int argc, char *argv[])
{
	if (argc < 3) {
		cout << argv[0] << " source_path destination_path" << endl;
		return 0;
	}

	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);

	if (!inFile) {
		cout << "Open file " << argv[1] << " for copy is faild! File not exist!" << endl;
		return 0;
	}

	if (!outFile) {
		cout << "Open file " << argv[2] << " for write is faild!" << endl;
		inFile.close();
		return 0;
	}
	char buffer[buffer_size];
	
	while(inFile.getline(buffer, buffer_size)) {
		outFile << buffer << endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}
