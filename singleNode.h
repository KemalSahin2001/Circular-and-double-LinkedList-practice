#pragma once
#include "doubleLinkedList.h"
#include "apartment.h"
class singleNode{
    public:
        singleNode* next;
        Apartment apt;
        singleNode(int data,string name):apt(data,name),next(0){}
        ~singleNode(){
            this->next = 0;     
        }
        friend ostream& operator<<(ostream& os, const singleNode& temp) {
			os << temp.apt.getMaxBandwidth() << "    " << temp.apt.getName() << "      " << temp.apt.flatsList << endl;
			return os;
		}
};