//
//  PersonalityQuiz.h
//  Adventure
//
//  Created by Charlie  Velazquez on 11/13/16.
//  Copyright © 2016 GoonPlatoon. All rights reserved.
//
#ifndef PERSONQ_H
#define PERSONQ_H
#include "Character.h"
using namespace std;

Player personalityQuiz(string fName,string lName,string gender,char *cl)
{
    bool flag=true;
    double health=100,mind=5,skill=5,fit=5,str=5;
    while(flag)
    {
        int answer = 0;
        cout<<"Which of the three locations most resembles where you are from?\n1.urban\n2.suburban\n3.rural\n4.desert\n"; cin>>answer; //fitness
        if (answer>0 && answer<5)
        {
            if (answer==1)
            {
                str-=1;
            }
            else if (answer==2)
            {
                str-=2;
            }
            else if (answer==3)
            {
                str+=2;
            }
            else
            {
                str+=1;
            }
            flag = false;
        }
        else
        {
            cout << "Please only enter a number between 1 and 4." << endl;
        }
    }
    flag=true;
    while(flag)
    {
        int answer = 0;
        cout<<"A fight breaks out, what do you do?\n1.walk away\n2.record\n3.join in\n4.break it up\n"; cin>>answer; //mind
        if (answer>0 && answer<5)
        {
            if (answer==1)
            {
                mind+=2;
            }
            else if (answer==2)
            {
                mind-=1;
            }
            else if (answer==3)
            {
                mind-=2;
            }
            else
            {
                mind+=1;
            }
            flag = false;
        }
        else
        {
            cout << "Please only enter a number between 1 and 4." << endl;
        }
    }
    flag=true;
    while(flag)
    {
        int answer = 0;
        cout<<"How many different physical activities do you accel in? \n1.4-6.\n2.3\n3.0\n4.1-2.\n"; cin>>answer; //skill
        if (answer>0 && answer<5)
        {
            if (answer==1)
            {
                skill+=2;
            }
            else if (answer==2)
            {
                skill+=1;
            }
            else if (answer==3)
            {
                skill-=2;;
            }
            else
            {
                skill-=1;
            }
            flag = false;
        }
        else
        {
            cout << "Please only enter a number between 1 and 4." << endl;
        }
    }
    flag=true;
    while(flag)
    {
        int answer = 0;
        cout<<"How comfortable are you swimming in the ocean?\n1.No way.\n2.Maybe in a netted area.\n3.Lets do it!. \n4.I was born in the ocean.\n"; cin>>answer; //skill
        if (answer>0 && answer<5)
        {
            if (answer==1)
            {
                skill-=2;
                fit-=2;
            }
            else if (answer==2)
            {
                fit-=1;
                skill-=1;
            }
            else if (answer==3)
            {
                skill+=1;
                fit+=1;
            }
            else
            {
                skill+=2;
                fit+=2;
            }
            flag = false;
        }
        else
        {
            cout << "Please only enter a number between 1 and 4." << endl;
        }
    }
    flag=true;
    while(flag)
    {
        int answer = 0;
        cout<<"What kind of books do you like?\n1.long and detailed.\n2.short and sweet.\n3.textbooks and reference books. \n4.whats a book?\n"; cin>>answer; //mind
        if (answer>0 && answer<5)
        {
            if (answer==1)
            {
                mind+=1;
            }
            else if (answer==2)
            {
                mind-=1;
            }
            else if (answer==3)
            {
                mind+=2;
            }
            else if (answer==4)
            {
                mind-=2;
            }
            flag = false;
        }
        else
        {
            cout << "Please only enter a number between 1 and 4." << endl;
        }
    }
    flag=true;
    while(flag)
    {
        int answer = 0;
        cout<<"How often do you lift weights?\n1.never.\n2.sometimes.\n3.frequently.\n4.I'm lifting right now!\n"; cin>>answer; //str
        if (answer>0 && answer<5)
        {
            if (answer==1)
            {
                str-=2;
            }
            else if (answer==2)
            {
                str-=1;
            }
            else if (answer==3)
            {
                str+=1;
            }
            else
            {
                str+=2;
            }
            flag = false;
        }
        else
        {
            cout << "Please only enter a number between 1 and 4." << endl;
        }
    }
    flag=true;
    while(flag)
    {
        int answer = 0;
        cout<<"How much time do you spend running per week?\n1.none.\n2.2 hours.\n3.3+ hours.\n4.30 minutes.\n"; cin>>answer; //fitness
        if (answer>0 && answer<5)
        {
            if (answer==1)
            {
                fit-=2;
            }
            else if (answer==2)
            {
                fit+=1;
            }
            else if (answer==3)
            {
                fit+=2;
            }
            else
            {
                fit-=1;
            }
            flag = false;
        }
        else
        {
            cout << "Please only enter a number between 1 and 4." << endl;
        }
    }
    if (mind > 10)
    {
        mind = 10;
    }
    if (skill > 10)
    {
        skill = 10;
    }
    if (fit > 10)
    {
        fit = 10;
    }
    if (str > 10)
    {
        str = 10;
    }
    if (mind  < 0)
    {
        mind = 0;
    }
    if (skill < 0)
    {
        skill = 0;
    }
    if (fit < 0)
    {
        fit = 0;
    }
    if (str < 0)
    {
        str = 0;
    }
    return Player(fName,lName,cl,health,mind,skill,fit,str,gender);
}
#endif
