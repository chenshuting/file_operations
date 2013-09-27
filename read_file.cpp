/*
 * =====================================================================================
 *
 *       Filename:  read_file.cpp
 *
 *    Description:  read the data from path1 to the standard output
 *
 *        Version:  1.0
 *        Created:  2013/09/27 09时14分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Shuting (cst), cicy0125@gmail.com
 *        Company:  gucas.ict.bwstor
 *
 * =====================================================================================
 */

#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2) {
		cout << argv[0] << " read_path" << endl;
		return 0;
	}

	ifstream inFile(argv[1]);
	if (!inFile) {
		cout << "File " << argv[1] << " not exist or open failed!" << endl;
		return 0;
	}
	
	struct stat info;
	stat(argv[1], &info);
	int fileLength = info.st_size;
	cout << "File length:" << fileLength << endl;

	const int buffer_size = 256;
	char buffer[buffer_size];
	int read_count = 0;

	while (read_count < fileLength){
		inFile.read(buffer, buffer_size);
		cout << buffer;
		read_count += buffer_size;
		memset(buffer,'\0', buffer_size);
	}
	
	inFile.close();
	return 0;
}
