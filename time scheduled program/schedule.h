#include<iostream>
#include<string>
#include"Header.h"
using namespace std;
class Link;
// ADT class for schedule storing
class Schedule
{
private:
    friend Link; //making class friend for accessing private element
    string day_of_week;
    //pointers for tme calss objects
    tme* start_time;//Composition
    tme* end_time;//Composition
    std::string activity;
    int priority;
public:
    //Default and overloaded constructer
    Schedule(string dweek = "", tme* start = 0, tme* end = 0, std::string act = "", int pr = 0);
    void Display();//for displaying
    tme* Length(); //for duration
};
//Node for binary tree
class Node 
{
    friend Link; //for accesssing its element
    Schedule data; //Composition
    //pointers for Node class
    Node* left;
    Node* right;
    Node(Schedule a)//Node Class Constructer
    {
        data = a;
        left = NULL;
        right = NULL;
    }
};
//binary tree class
class Link
{
    //pointer of Node class
    Node* root;
    void dest(Node*); //recursive function for deletion
    void m_fy(Node* x, string act, Schedule);//recursive function for modification
    Node* insert(Node* root, string dweek, tme* start, tme* end, string act, int pr);//recursive function for modification
    void lvr(Node*);//recursive fuction for display
public:
    Link();//Default Constructer
    //Overloaded Constructer
    Link(string dweek = "", tme* start = 0, tme* end = 0, string act = "", int pr = 0);
    ~Link();//Destructer
    //Insertion
    void insert(string dweek, tme* start, tme* end, string act, int pr);
    void display();//for display
    bool search(Node*, Schedule);//for seaerching
    void  modify(string, Schedule);//for modification
};
#pragma once
