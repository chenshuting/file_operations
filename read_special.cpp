/*
 * =====================================================================================
 *
 *       Filename:  read_special.cpp
 *
 *    Description:  read file with special data format from input file, and 
 *    output the read data to another file
 *
 *        Version:  1.0
 *        Created:  2013/09/27 09时15分17秒
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
#include <cstring>
#include <cstdlib>
using namespace std;


int main(int argc, char *argv[])
{
	if (argc < 2) {
		cout << argv[0] << " read_path" << endl;
		return 0;
	}

	ifstream inFile(argv[1]);
	if (!inFile) {
		cout << "Open file " << argv[1] << " to read failed!" << endl;
		return 0;
	}

	const int buffer_size = 256;
	char buffer[buffer_size];
	const int size = 20;

	while (inFile.getline(buffer, buffer_size)) {
		char *number;
		char *format;
		char *tmp;	
		number = strtok(buffer, " ");
		format = strtok(NULL, " ");
		cout << number << " " << format << endl;
		
		int i = 0;
		int num = 0;
		tmp = strtok(format, "-");
		while (tmp) {
			num += atoi(tmp);
			while (i < num) {
				cout << number[i++];
			}
			tmp = strtok(NULL, "-");
			if (tmp)
				cout << "-";
		}
		cout << endl;
		memset(buffer, '\0', buffer_size);
	}
	
	inFile.close();
	return 0;
}
