/*
 * =====================================================================================
 *
 *       Filename:  file_sumarize.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013/09/27 11时08分03秒
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
#include <string>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>
#include <cstdio>
#include <dirent.h>
#include <vector>
#include <errno.h>
using namespace std;

const int path_length = 256;

bool remove_file(char *path)
{
	string cmd = "rm -f ";
	cmd.append(path);
	cout << cmd << endl;
	if (system(cmd.c_str()) == 0)
		return true;
	else
		return false;
}

bool copy(char *src, char *dst)
{
	string cmd = "cp ";
	cmd.append(src);
	cmd.append(" ");
	cmd.append(dst);

	if (system(cmd.c_str()) == 0) {
		return true;
	} else {
		return false;
	}
}

void list_file_and_dirs(char *path)
{
	DIR *dp;
	struct dirent *dirp;
	vector<string> file_names;
	vector<string> dir_names;

	if ((dp = opendir(path)) == NULL) {
		cerr << "opendir error!" << path << " is not a dir or not exist!" 
			<< strerror(errno)<< endl;
		return;
	}

	while ((dirp = readdir(dp)) != NULL) {
		if ((strcmp(dirp->d_name,".")==0) ||
				(strcmp(dirp->d_name, "..") == 0)) {
			continue;
		}
		if (dirp->d_type == DT_DIR) {
			dir_names.push_back(dirp->d_name);
		} else {
			file_names.push_back(dirp->d_name);
		}
	}
	cout << "-----------------------[Directories]----------------------" << endl;
	for (vector<string>::iterator it = dir_names.begin();
			it != dir_names.end(); it++) {
		cout << *it << endl;
	}

	cout << "-----------------------[files]----------------------" << endl;
	for (vector<string>::iterator it = file_names.begin();
			it != file_names.end(); it++) {
		cout << *it << endl;
	}
}

void print_info()
{
	cout << "1.list files and dirs in path" << endl;
	cout << "2.delete file with specific name" << endl;
	cout << "3.copy file from path1 to path2" << endl;
	cout << "0.quit " << endl;
}

void choose_to_operate()
{
	int type = 1;

	while (type) {
		print_info();
		cin >> type;
		switch(type) {
		case 1:
			char path[path_length];
			cout << "Input path:>";
			cin >> path;
			list_file_and_dirs(path);
			cout << endl;
			break;
		case 2:
			char delete_path[path_length];
			cout << ">";
			cin >> delete_path;
			if (remove_file(delete_path)) {
				cout << "Remove " << delete_path << " successful" << endl;
			} else {
				cout << "Remove " << delete_path << " failed" << endl;
			}
			break;
		case 3:
			char src_path[path_length];
			char dst_path[path_length];
			cout << "source:";
			cin >> src_path;
			cout << "destination:";
			cin >> dst_path;
			if (copy(src_path, dst_path)) {
				cout << "Copy success！" << endl;
			} else {
				cerr << "Copy failed! " << strerror(errno) << endl; 
			}
			break;
		default:
			print_info();
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	char path[path_length] = {0};
	
	if (!getcwd(path, 260)) {
		cout << "Get current path failed!" << endl;
		return 0;
	}

	cout << "Current dir: " << path << endl;
	
	choose_to_operate();
	
}
