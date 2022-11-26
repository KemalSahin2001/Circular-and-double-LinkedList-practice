#include <iostream>
using namespace std;
#include "circularLinkedList.h"
#include "System.h"
#include <vector>
#include <fstream>
int main(int argc, char const *argv[])
{
	string line,arg,item;
	stringstream ss,ss2;
    ifstream* input = new ifstream(argv[1]);
	ofstream* output = new ofstream(argv[2]);
	while (getline(*input, line))
	{
		ss.clear();
		ss << line;
		vector<string> items;
		while(getline(ss,arg,'\t')) {
			ss2.str("");
			ss2.clear();
			ss2 << arg;
			ss2 >> item;           
			items.push_back(item);
		}
		if(items.at(0) == "add_apartment") {
			stringstream ss3;
			int val;
			ss3 << items.at(3);
			ss3 >> val;
			add_apartment(items.at(1), items.at(2), val);
		} else if(items.at(0) == "add_flat") {
			stringstream ss3;
			int val[3];
			for (int i = 2; i <= 4; i++)
			{
				ss3.clear();
				ss3 << items.at(i);
				ss3 >> val[i - 2];
			}
			add_flat(items.at(1), val[0], val[1], val[2]);
		} 
        else if(items.at(0) == "remove_apartment") remove_apartment(items.at(1));
		else if(items.at(0) == "merge_two_apartments") merge_two_apartments(items.at(1), items.at(2));
		else if (items.at(0) == "find_sum_of_max_bandwidths") *output << "sum of bandwidth: " << find_sum_of_max_bandwidth() << endl << endl;
		else if(items.at(0) == "make_flat_empty") {
			stringstream ss3;
			int val;
			ss3 << items.at(2);
			ss3 >> val;
			make_flat_empty(items.at(1), val);
		} else if(items.at(0) == "list_apartments") list_apartments(*output);
		else if(items.at(0) == "relocate_flats_to_same_apartment") {          
            stringstream ss3;
            int val2;
            ss3 << items.at(2);
            ss3 >> val2;
            string flats = items.at(3);
            flats = flats.substr(1, flats.length() - 2);
            stringstream aa(flats), aa2;
            vector<int> v;
            string value;
            int val3;
            while (getline(aa, value, ','))
            {
                aa2.str("");
                aa2.clear();
                aa2 << value;
                aa2 >> val3;
                v.push_back(val3);
            }
            relocate_flats_to_same_apartments(items.at(1), val2, v);
		}
	}
    return 0;
}
