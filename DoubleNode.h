#pragma once
#include <iostream>
#include "flat.h"
#include <stdexcept>
using namespace std;

class doubleNode{
    public:
        Flat flat;
        doubleNode* next;
        doubleNode* prev;

        doubleNode(int data,int& uniqueID,bool is_empty_val = true): flat(uniqueID,data,is_empty_val),next(0),prev(0){}
        ~doubleNode(){
            this->next = 0;
			this->prev = 0;
        }
        friend ostream& operator<<(ostream& os, const doubleNode& temp) {
			os << temp.flat.getInitialBandwidth() << "    " << temp.flat.getID() << "      " << temp.next << "      " << temp.prev << endl;
			return os;
		}
};