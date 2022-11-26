#pragma once
#include "circularLinkedList.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <vector>
#include "fstream"
static circularLinkedList street;
void add_apartment(string ID,int Initial_Bandwith){
    if(street.getLoc(ID) == -1){
        street.push_front(Initial_Bandwith,ID);
    }
    else{
        cout << "There is Same named Apt." << endl;
    }
};
void add_apartment(string name,string pos,int max_bw){
    if(pos == "head"){
        add_apartment(name,max_bw);
    }
    else{
        string values[2], value;
        stringstream ss(pos),ss2;
        int i = 0;
        while(getline(ss,value,'_')) {
            ss2.str("");
            ss2.clear();
            ss2 << value;
            ss2 >> values[i];
            i++;
        }
        if(values[0] == "after")
        street.insert(max_bw,name,street.getLoc(values[1]) + 1);
        
        else if (values[0] == "before")
        street.insert(max_bw,name,street.getLoc(values[1]));
    }        
};
void add_flat(string AptName,int index,int initial_bandwith,int ID){
    if(index >= 0 && index <= street.get(street.getLoc(AptName))->apt.getFlatCount()){
        if(street.get(AptName) != 0){
            Apartment& apt = street.get(AptName)->apt;
            if(initial_bandwith + apt.getInitial_Bandwidth() <= apt.getMaxBandwidth()){             
                apt.flatsList->insert(index,initial_bandwith,ID);
                apt.Plus_FlatCount();
                apt.Plus_Initial_Bandwidth(initial_bandwith);
            }
            else{
                if(apt.getInitial_Bandwidth() == apt.getMaxBandwidth()){
                    apt.flatsList->insert(index,0,ID);
                    apt.Plus_FlatCount();
                }
                else{
                    apt.flatsList->insert(index,apt.getMaxBandwidth() - apt.getInitial_Bandwidth(),ID);
                    apt.Plus_Initial_Bandwidth(apt.getMaxBandwidth() - apt.getInitial_Bandwidth());
                    apt.Plus_FlatCount();
                }
                
            }
        }
        else{
            cout << "No Such APT" << endl;
        }
    }                 
    else{
        cout << "Wrong Index" << endl;
    }
};
void remove_apartment(string AptName){
    street.remove(street.getLoc(AptName));
}
void make_flat_empty(string APTName,int ID){
    street.get(APTName)->apt.Minus_Initial_Bandwidth(street.get(APTName)->apt.flatsList->get(street.get(APTName)->apt.flatsList->getIndex(ID))->flat.getInitialBandwidth());
    street.get(APTName)->apt.flatsList->get(street.get(APTName)->apt.flatsList->getIndex(ID))->flat.setisEmpty(true);  
}
int find_sum_of_max_bandwidth(){
    int count = 0;
    for (int i = 0; i < street.length(); i++)
    {
        count += street.get(i)->apt.getMaxBandwidth();
    }
    return count;
    
}
void merge_two_apartments(string apt1, string apt2){
    singleNode* var1 = street.get(apt1);
    singleNode* var2 = street.get(apt2);  
    var1->apt.Merge(var2->apt);  
    street.removeFromList(street.getLoc(apt2));
}
void relocate_flats_to_same_apartments(string apt,int flat_ID,vector<int>& g1){
    singleNode* insApt = street.get(apt);
    vector<int> temp;

    singleNode* varApt = street.begin();
    for (int i = 0; i < g1.size(); i++)
    {
        temp.push_back(g1.at(i));
        do{
            if(varApt->apt.flatsList->begin() != 0){
                doubleNode* varFlat = varApt->apt.flatsList->begin();
                while(varFlat != 0){
                    if (count(temp.begin(), temp.end(), varFlat->flat.getID())) {                 
                        doubleNode* flt = varApt->apt.flatsList->relocate(varApt->apt.flatsList->getIndex(varFlat));
                        varApt->apt.minusMaxBandwidth(flt->flat.getInitialBandwidth());
                        varApt->apt.Minus_Initial_Bandwidth(flt->flat.getInitialBandwidth());
                        varApt->apt.Minus_FlatCount();
                        insApt->apt.flatsList->insert(flt,insApt->apt.flatsList->getIndex(flat_ID));
                        insApt->apt.plusMaxBandwidth(flt->flat.getInitialBandwidth());
                        insApt->apt.Plus_Initial_Bandwidth(flt->flat.getInitialBandwidth());
                        insApt->apt.Plus_FlatCount();
                    }
                    varFlat = varFlat->next;
                }
            }      
            varApt = varApt->next;
        } while (varApt != street.begin());  
        temp.erase(temp.begin());
    }
    
     
    
}   
void list_apartments(ofstream& output) {
	singleNode* temp = street.begin();
	int count = 0;
	while (count < street.length())
	{
		output << temp->apt.getName() << "(" <<temp->apt.getMaxBandwidth()  << ")" << "\t" << temp->apt.flatsList << endl;
		temp = temp->next;
		count++;
	}
	output << endl;
}