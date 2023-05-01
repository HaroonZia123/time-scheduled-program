#include<iostream>
#include<iomanip>
#include<string>
#include"schedule.h"
using namespace std;
Schedule::Schedule(string dweek, tme* start, tme* end, std::string act, int pr)
{
    day_of_week = dweek;
    start_time = start;
    end_time = end;
    activity = act;
    priority = pr;
}
void Schedule::Display()
{
    //for displaying activity day time and date
    //setw for display in a good manner
    cout << setw(13) << activity <<" | " << setw(14) << day_of_week;
    cout << " |  " << setw(12) << start_time->tstring(start_time)  << " | " << setw(8) << start_time->tostring(start_time)  << " |  " << setw(8) << end_time->tostring(end_time)  << " | ";
}
tme* Schedule::Length()
{
    //return duration and also print it
    cout << this->start_time->tostring(start_time->duration(end_time, start_time));
    return this->start_time->duration(end_time, start_time);
}

Link::Link()
{
    root = nullptr;//at starting
}
Link::Link(string dweek, tme* start, tme* end, string act, int pr)
{
    Schedule b(dweek, start, end, act, pr);//Schedule class constructer called
    root = new Node(b);
}
Link::~Link()//destructer
{
    dest(root);//recursive function called
}
void Link::dest(Node* x)
{
    if (x != nullptr)
    {
        if ((x->left == nullptr) && (x->right == nullptr))
        {
            delete x;
            x = nullptr;
        }
        else
        {
            dest(x->left); //recursive call
            dest(x->right);//recursive call
        }
    }
}
bool Link::search(Node* rt, Schedule c)
{
    // for checking new entering schedule time slot is booked or not
    if (rt->left)
    {
        return search(rt->left, c);//recurisive call
    }
    else if (rt->right)
    {
        return search(rt->right, c);//recurisive  call
    }
    //if one of the condition below get true mean this time slot is not booked 
    else if (c.start_time->day != rt->data.start_time->day)
    {
        return false;
    }
    else if (c.start_time->month != rt->data.start_time->month)
    {
        return false;
    }
    else if (c.start_time->year != rt->data.start_time->year)
    {
        return false;
    }
    else if ((c.start_time->hour < rt->data.start_time->hour) || (c.start_time->hour > rt->data.end_time->hour))
    {
        return false;
    }
    else if ((c.start_time->minute < rt->data.start_time->minute) || (c.start_time->minute > rt->data.end_time->minute))
    {
        return false;
    }
    else if ((c.start_time->second < rt->data.start_time->second) || (c.start_time->second > rt->data.end_time->second))
    {
        return false;
    }
    //if above condition not true mean this time slow is reserved
    else
    {
        return true;
    }
        
}
void Link::insert(string dweek = 0, tme* start = 0, tme* end = 0, string act = "", int pr = 0)
{
    if (pr > root->data.priority) //for left insertion
    {
        root->left = insert(root->left, dweek, start, end, act, pr);
    }
    else//for right insertion
    {
        root->right = insert(root->right, dweek, start, end, act, pr);
    }
}
Node* Link::insert(Node* rt, string dweek, tme* start, tme* end, string act, int pr)
{
    Schedule a(dweek, start, end, act, pr);
    // for checking new entering schedule time booked or not
    if (search(root, a))
    {
        cout << " This slot is reserved\n";
        return nullptr;
    }
    rt = new Node(a);
    //Node* newNode = new Node(a);
    rt->left = rt->right = NULL;
    return rt;
}
void Link::display()
{
    if (root == nullptr)
    {
        //empty Schedule
        cout << " YOU have NO Activity in SChdule\n";
    }
    else
    {
      
        lvr(root); //recursive call
    }
}
void Link::lvr(Node* x)
{
    if (x && x->left)
    {
        lvr(x->left); //for left subtree recursive call
    }
    if (x)
    {
        x->data.Display();//Display function of Schedule called
        x->data.Length(); //Display function of Schedule called
        cout << endl;
    }
    if (x && x->right)
    {
        lvr(x->right);//for right subtree recursive call
    }
}
void Link::m_fy(Node* x, string act, Schedule b)
{
    if (x)
    {
        if (x->data.activity == act) //if modifying activity found
        {
            //chenge data of that Slot
            x->data.activity = b.activity;
            x->data.day_of_week = b.day_of_week;
            x->data.end_time = b.end_time;
            x->data.start_time = b.start_time;
            cout << " Data have been updated:\n";
            return;
        }
        else if (x->left)
        {
            m_fy(x->left, act, b);// left recursive call
        }
        else if (x->right)
        {
            m_fy(x->right, act, b);//right recursive call
        }
    }

}
void Link::modify(string act, Schedule b)//for modification
{
    m_fy(root, act, b);//recursive call
}
#pragma once
