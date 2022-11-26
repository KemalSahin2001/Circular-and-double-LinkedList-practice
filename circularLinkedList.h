#pragma once
#include <iostream>
#include "singleNode.h"
#include <stdexcept>
using namespace std;

class circularLinkedList {
    int size;
    singleNode* head;
    singleNode* tail;
    public:
        circularLinkedList(){
            size = 0;
            head = 0;
            tail = 0;
        }
        Apartment front() { return begin()->apt; }
	    Apartment back() { return end()->apt; }
        int length() { return size; }
        bool isEmpty() const { return size == 0; }

        singleNode* begin(){
            if(isEmpty()) {
			    return 0;
            }
            return head;
        }

        singleNode* end(){
            if(isEmpty()) {
			    return 0;;
            }
            return tail;
        }

        void push_back(const int& value,const string ID) {
            if(isEmpty()) {
                head = tail = new singleNode(value,ID);
                tail->next = head;
                size++;
            }else {
                singleNode* temp = end();
                temp->next = new singleNode(value,ID);
                tail = temp->next;
                tail->next = head;
                size++;
            }
	    }  
        void pop_back() {
            if(isEmpty()){
                
            }
            else if (begin() == end())
            {
                delete head;
                delete tail;
                size--;
            }
            else {
                singleNode* temp = begin();
                while(temp->next->next != begin()) {
                    temp = temp->next;
                }
                delete temp->next;
                tail = temp;
                temp->next = head;
                size--;
            }
	    }
        void push_front(const int& value,const string ID) {
            if(isEmpty()) {
                head = tail = new singleNode(value,ID);
                tail->next = head;
                size++;
            }else {
                singleNode* temp = begin();
                head = new singleNode(value,ID);
                head->next = temp;
                tail->next = head;
                size++;
            }       
	    }
        void pop_front() {
            if(isEmpty()){
            } else {
                singleNode* temp = begin();
                head = head->next;
                tail->next = head;
                delete temp;
                size--;
            }       
	    }
        void insert(int value,string ID,int index = 0) {
            if(isEmpty()){
                head = tail = new singleNode(value,ID);
                tail->next = head;
                size++;
            }else if(index < 0 || index > size) {
            } else {
                if(index == 0)
                    push_front(value,ID);
                else if(index == size)
                    push_back(value,ID);
                else
                {
                    singleNode* temp = head;
                    for (int i = 0; i < index - 1; i++)
                    {
                        temp = temp->next;
                    }
                    singleNode* newNode = new singleNode(value,ID);
                    newNode->next = temp->next;
                    temp->next = newNode;
                    size++;
                }
            }
	    }
        int getLoc(string name){
            if(isEmpty()){
                return -1;
            }
            else{
                singleNode* temp = head;
                int count = 0;
                while(temp->apt.getName() != name){
                    temp = temp->next;
                    count++;
                    if(count == size){
                        return -1;
                    }
                }
                if(count == size){
                    return -1;
                }
                return count;
            }
        }
        void remove(int index) {
            if(isEmpty()){
            } else if (index < 0 || index >= size) {
            } else {
                if(index == 0) {
                    return pop_front();
                }else if(index == size - 1) {
                    return pop_back();
                }else {
                    singleNode* temp = head;
                    for (int i = 0; i < index - 1; i++)
                    {
                        temp = temp->next;
                    }
                    singleNode* del = temp->next;
                    temp->next = temp->next->next;
                    delete del;
                    size--;
                }
            }
	    }
        void removeFromList(int index) {
            if(index == 0) {
                head = head->next;
                tail->next = head;
                size--;
            }else if(index == size - 1) {
                if(isEmpty()){
                }
                else if (begin() == end())
                {
                    head = tail = 0;
                    size--;
                }
                else {
                    singleNode* temp = begin();
                    while(temp->next->next != begin()) {
                        temp = temp->next;
                    }
                    tail = temp;
                    temp->next = head;
                    size--;
                }
            }
            else{
                singleNode* temp = head;
                for (int i = 0; i < index - 1; i++)
                {
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                size--;
            }
            
        }
        singleNode* get(int index = 0) {            
            if(index < 0 || index >= size) {
            }else {
                int count = 0;
                singleNode* temp = head;
                while (count != index)
                {
                    temp = temp->next;
                    count++;
                }
                return temp;
            }
	    }
        singleNode* get(string AptName) {
            int index = getLoc(AptName);
            if(index == -1){
                cout << "WRONG DELETION There is no such APT" << endl;
                return 0;
            }           
            else {
                int count = 0;
                singleNode* temp = head;
                while (count != index)
                {
                    temp = temp->next;
                    count++;
                }
                return temp;
            }
	    }
        void print() {
            cout << "MaxBandWith Name FlatList" << endl; 
            if(isEmpty()) {
                cout << "Empty list!\n";
            }else {
                singleNode* temp = begin();
                for (int i = 0; i < size; i++)
                {
                    cout << *temp;
                    temp = temp->next;
                }
                cout << endl;
            }
            cout << "First node: " << *head << endl;
            cout << "Last node: " << *tail << endl;
	    }   
}; 