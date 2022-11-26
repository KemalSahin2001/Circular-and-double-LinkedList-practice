#pragma once
#include <iostream>
#include "doubleLinkedList.h"
#include "flat.h"
#include <stdexcept>
using namespace std;

class Apartment {
	string name;
	int max_bandwidth;
	int initial_bandwidth;
	int flatCount;
	public:
		doubleLinkedList* flatsList;
		Apartment(int max_bw_val, string name_val) : 
		name(name_val), max_bandwidth(max_bw_val),initial_bandwidth(0),flatCount(0){
			flatsList = new doubleLinkedList();
		}
		~Apartment(){
			delete flatsList;
		}
		void plusMaxBandwidth(int val){
			max_bandwidth += val;
		}
		void minusMaxBandwidth(int val){
			max_bandwidth -= val;
		}
		string getName() const { return name; }
		void Plus_Initial_Bandwidth(int val) {initial_bandwidth += val;}
		void Minus_Initial_Bandwidth(int val) {initial_bandwidth -= val;}
		int getInitial_Bandwidth(){return initial_bandwidth;}
		int getFlatCount() const {return flatCount;}
		void Plus_FlatCount() {flatCount++;}
		void Minus_FlatCount() {flatCount--;}
		int getMaxBandwidth() const { return max_bandwidth; }
		void Merge(Apartment& apt2){
			int count = 0;
			max_bandwidth += apt2.getMaxBandwidth();
			while (apt2.flatsList->get(count) != 0)
			{
				flatsList->push_back(apt2.flatsList->get(count));
				initial_bandwidth += apt2.flatsList->get(count)->flat.getInitialBandwidth();
				flatCount++;
				count++;
			}			
		}
};