#pragma once
#include <iostream>
#include "DoubleNode.h"
#include <stdexcept>

class doubleLinkedList{
    doubleNode* head;
	doubleNode* tail;
	int size;

    public:
        doubleNode* begin(){ return head; }
        doubleNode* end(){ return tail; }
        bool isEmpty() { return size == 0; }
        int length() { return size; }
        doubleLinkedList()
		{
            head = 0;
            tail = 0;
            size = 0;
		}
        ~doubleLinkedList() {
            doubleNode* temp = head;
            while(temp != 0){
                doubleNode* del = temp;
                temp = temp->next;
                delete del;
            }
            head = tail = 0;
            size = 0;
        }      
        void push_back(int ID,int val,bool is_empty_val = true){
            if(isEmpty()){
                head = tail = new doubleNode(val,ID,is_empty_val);
                size++;              
            }
            else{
                doubleNode* tmp = tail;
                tmp->next = new doubleNode(val,ID,is_empty_val);
                tmp->next->prev = tmp;
                tail = tmp->next;
                size++;
            }
        }
        void push_back(doubleNode* new_flat){
            if(isEmpty()){
                head = tail = new_flat;
                size++;              
            }
            else{
                doubleNode* tmp = tail;
                tmp->next = new_flat;
                new_flat->prev = tmp;
                tail = new_flat;
                size++;              
            }
        }
        int getIndex(doubleNode* node){
            if(isEmpty()){
                return -1;
            }
            else{
                int count = 0;
                doubleNode* temp = begin();
                while(temp != node){
                    temp = temp->next;
                    count++;
                }
                return count;
            }        
        }
        int getIndex(int ID){
            if(isEmpty()){
                return -1;
            }
            else{
                int count = 0;
                doubleNode* temp = begin();
                while(temp->flat.getID() != ID){
                    temp = temp->next;
                    count++;
                }
                
                return count;
            }        
        }
        void insert(int index, int val,int ID, bool is_empty_val = true){
            if(isEmpty()){
                head = tail = new doubleNode(val,ID,is_empty_val);
                size++;    
            }
            else{
                if(index < 0 || index > size) {
					cout << "Out of borders\n";
					return;}
                else if(index == size){
                    push_back(ID,val);
                }
                else if(index == 0){
                    doubleNode* temp =  head;
                    doubleNode* newNode = new doubleNode(val,ID,is_empty_val);
                    newNode->next = temp;
                    temp->prev = newNode;
                    head = newNode;
                    size++;
                }
                else{                
                    int count = 0;
                    doubleNode* tmp = head;
                    while(count != index){
                        tmp = tmp->next;
						count++;
                    }
                    doubleNode* newNode = new doubleNode(val,ID,is_empty_val);
                    newNode->next = tmp;
                    newNode->prev = tmp->prev;
                    tmp->prev->next = newNode;
                    tmp->prev = newNode;
                    size++;
                }           
            }
        
        }
        void insert(doubleNode* newNode,int index){
            if(isEmpty()){
                head = tail = newNode;
                size++;    
            }
            else{
                if(index < 0 || index > size) {
					cout << "Out of borders\n";
					return;}
                else if(index == size){
                    
                    push_back(newNode);
                }
                else if(index == 0){
                    doubleNode* temp =  head;
                    newNode->next = temp;
                    temp->prev = newNode;
                    head = newNode;
                    size++;
                }
                else{                                 
                    int count = 0;
                    doubleNode* tmp = head;
                    while(count != index){
                        tmp = tmp->next;
						count++;
                    }
                    newNode->next = tmp;
                    newNode->prev = tmp->prev;
                    tmp->prev->next = newNode;
                    tmp->prev = newNode;
                    size++;
                }           
            }
        
        }
        doubleNode* get(int index = 0) {
            if(index < 0 || index >= size){
                return 0;
            }
            else {
                int count = 0;
                doubleNode* temp = head;
                while(count != index){
                    temp = temp->next;
                    count++;                 
                }                
                return temp;                   
            }
        } 
        doubleNode* pop() {
            if(isEmpty()){
                return 0;
            }
            else if(begin() == end()){
                doubleNode* temp = begin();
                head = 0;
                tail = 0;
                size--;
                return temp;
            }
            else {
                doubleNode* temp = tail->prev;
                doubleNode* temp2 = tail;
                cout << "Removed node: \n";
                cout << *tail;
                tail = temp;
                delete tail->next;
                tail->next = 0;
                size--;
                return temp2;
            }
        }
        void remove(int index) {
            if(isEmpty()){
            }
            else {
                doubleNode* temp = head;
                int count = 0;
                while(count != index){
                    temp = temp->next;
                    count++;
                }
                temp->prev->next = temp->next;
                if(index != size - 1) {
					temp->next->prev = temp->prev;
				}
                else {
					tail = temp->prev;
				}
                size--;             
                delete temp;
            }
        }
        doubleNode* relocate(int index){
            if(isEmpty()){
                return 0;;
            }
            else if(index == 0){            
                doubleNode* temp = head;
                head = head->next;            
                head->prev = 0;
                if(head->next != 0){
                     head->next->prev = head;
                }
                size--;
                return temp;
            }
            else {
                doubleNode* temp = head;
                int count = 0;
                while(count != index){
                    temp = temp->next;
                    count++;
                }
                temp->prev->next = temp->next;            
                if(index != size - 1) {
					temp->next->prev = temp->prev;
				}
                else {
					tail = temp->prev;
				}
                size--;          
                return temp;
            }
        }
        void print() {
            if(isEmpty()) {
                cout << "Empty list! \n";
            }
            else{
                doubleNode* temp = head;
                cout << "DATA  ID     NextNode      PrevNode\n";
                for (int i = 0; i < size; i++)
                {
                    cout << *temp;
                    temp = temp->next;
                }               
            }
        }
        friend ostream& operator<<(ostream& os, doubleLinkedList* dt)
        {
            doubleNode* temp = dt->begin();
            for (int i = 0; i < dt->length(); i++)
            {
                os << "Flat" << temp->flat.getID() << "(" << temp->flat.getInitialBandwidth() << ")\t";
                temp = temp->next;
            }                          
            return os;
        }
};