#pragma once
#include <iostream>
using namespace std;

class Flat{
    int ID;
	int initial_bandwidth;
	bool is_empty;

    public:

        Flat(int ID_val = 0, int initial_bandwidth_val = 0, bool is_empty_val = true):
        ID(ID_val), initial_bandwidth(initial_bandwidth_val), is_empty(is_empty_val){};

        int getID() const { return ID; }
        int getInitialBandwidth() const { return initial_bandwidth; }
		bool isEmpty() const { return is_empty; }
        void setisEmpty(bool val){ 
            is_empty = val;
            initial_bandwidth = 0; }
        friend ostream &operator<<(ostream &os, const Flat &flat){
            os << "Flat ID: " << flat.ID << "\nFlat Initial Band: " << flat.initial_bandwidth
	        << "\nFlat's Empty Status: " << flat.is_empty << endl;
	        return os;
        }
};