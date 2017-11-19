/*
File Type Maximum

In this problem, you have to modify an existing C++ program that reads in the scores received by students in a number of subjects, and does some processing on it.

The input is being read in from a file called input.txt, in this format:

root, directory, 128, admin, NONE
users, directory, 512, admin, root
navin, directory, 1024, navin, users
navin.jpg, photo, 128000, navin, navin
Project.doc, document, 256000, navin, navin
Sholay.mpg, video, 4123456123, navin, navin
amit, directory, 128, amit, users
Resume.doc, document, 256000, amit, amit

This contains information about files stored in a file system. Each line corresponds to one file, and the fields are separated by commas. The first field contains the filename, the second contains the file type, the third field is the size of the file in bytes, the fourth field is the username of the owner of the file, and the last field is the name of the parent directory of this file (i.e. the name of the directory in which this file is located.) Note: the special parent directory name NONE indicates that this file is the root directory of the filesystem. Also, for the purposes of this program, assume that all file/directory names are unique in the system.

Currently, the existing program reads the input, puts it into a data-structure, and calls a method processData on it. processData returns an integer that is printed to the output file. Unfortunately, processData currently does not do anything useful - it just returns 0.

You have to modify processData to figure out which file type has the most number of files/directories, and return that number.

Thus, if the input above were placed in a file called input.txt in the same directory as your program, then your program should create a file called output.txt in the same directory, and output.txt should contain the following:

4

This is because in the input given above, directory is the most common file type, and there are 4 entries with that file type.

Please make sure of the following:

    Please download this C++ Program, and change it to create your program, and submit your changed program as your answer
        All your changes must be inside the processArray method. Do not make any changes to the rest of the program
	    Make sure processArray returns the correct value
	        Copy paste the entire updated program in the space below. You must submit a full, working, program. Please compile, run, and check the output of your program before submitting it.
		    Please make sure to use only standard C. Do not use proprietary Microsoft or Turbo-C extensions. Specifically, do not use clrscr, getch, or conio.h.
		        The processArray method should not print anything to the standard output. Any unnecessary output will result in a program disqualification.
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <list>

#define NUM_FIELDS 5

// defined file types
#define DIR   " directory"
#define PHOTO " photo"
#define VIDEO " video"
#define DOC   " document"



struct SplitLine {
	std::string fields[NUM_FIELDS];
};

class Parser
{
	int directory_count;
	int photo_count;
	int video_count;
	int doc_count;
	public:
	Parser()
	{
		directory_count = 0;
		photo_count = 0;
		video_count = 0;
		doc_count = 0;
	}

	~Parser()
	{

	}

	void fileType_Parsing(std::string fileType)
	{
		if(!strcmp(fileType.c_str(),DIR))
		{
			directory_count ++;
		}
		else if(!strcmp(fileType.c_str(),PHOTO))
		{
			photo_count++;
		}
		else if(!strcmp(fileType.c_str(),VIDEO))
		{
			video_count++;
		}
		else if(!strcmp(fileType.c_str(),DOC))
		{
			doc_count++;
		}
	}

	int print_count()
	{
		std::list<int> mylist;

		mylist.push_back (directory_count);
		mylist.push_back (photo_count);
		mylist.push_back (video_count);
		mylist.push_back (doc_count);
		mylist.sort();

		std::list<int>::iterator it;
		int i;
		for (it=mylist.begin(); it!=mylist.end(); ++it)
		{
			i = *it;
		}
		return i;
	}
};

/* If you wish you can include any more files here.
   (from standard libraries only) */

int processData(std::vector<struct SplitLine> data) {
	/* 
	 * Modify this function to process `data` as indicated
	 * in the question. At the end, return the appropriate 
	 * value.
	 *
	 * Please create appropriate classes, and use appropriate
	 * data structures as necessary.
	 *
	 * Do not print anything in this function.
	 *
	 * Note: the existing program is not intended to be an example
	 * of good programming practice. (For example, struct
	 * SplitLine is not a very good way to hold the data for this
	 * problem.)  However, the code that *you* write will be
	 * evaluated on the basis of the quality of the code, use of
	 * appropriate classes/data-structures, comments, and
	 * efficiency of the algorithm used.
	 *
	 * Submit this entire program (not just this function)
	 * as your answer
	 */
	Parser obj;

	for (int i = 0; i< data.size(); i++)
	{
		obj.fileType_Parsing(data[i].fields[1]);
	}
	return obj.print_count();

}

int main(void) {
	std::ifstream in("input.txt");
	std::vector<struct SplitLine> input_data;
	while (in) {
		struct SplitLine line;
		for (int i=0; i<NUM_FIELDS; i++) {
			if (i==NUM_FIELDS-1)
				std::getline(in, line.fields[i]);
			else
				std::getline(in, line.fields[i], ',');
		}
		if (line.fields[0] != "")
			input_data.push_back(line);
	}
	std::ofstream out("output.txt");
	out << processData(input_data) << std::endl;
	return 0;
}

