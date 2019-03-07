//
//  Header.h
//  Adventure
//
//  Created by Charlie  Velazquez on 11/13/16.
//  Copyright © 2016 GoonPlatoon. All rights reserved.
//
#ifndef CHARACTER_H
#define CHARACTER_H
#include "Weapon.h"
using namespace std;

class Character
{
public:
    Character(){ weap = new Fists();}
    virtual ~Character(){delete weap;}
    void setHealth(double h){health=h;}
    void setCurrentLoc(char *cl){currentLoc = cl;}
    void setWeapon(Weapon* x)
    {
        delete weap; weap = x;
        if(x->getType()=="Melee")
        {
            setStr(getStr()+x->getBuff());
        }
        if(x->getType()=="Magic")
        {
            setMind(getMind()+x->getBuff());
        }
        if(x->getType()=="Range")
        {
            setSkill(getSkill()+x->getBuff());
        }
        if(x->getType()=="Armor")
        {
            setFit(getFit()+x->getBuff());
        }
    }
    
    string getName()const{return name;}
    Weapon* getWeapon()const{return weap;}
    char *getCurrentLoc()const{return currentLoc;}
    double getHealth()const{return health;}
    double getMind()const{return mind;}
    double getStr()const{return str;}
    double getSkill()const{return skill;}
    double getFit()const{return fitness;}
    int getIndex(){return index;}
    string getGender()const{return gender;}
    void move(string d)
    {
        int i=7;
        if (d=="north")
        {
            if (*(currentLoc-i)!='X')
            {
                currentLoc-=i;
                index-=i;
            }
            else
            {
                cout<<"You are trying to escape the arena, which is impossible. Chose a different direction."<<endl;
            }
        }
        else if(d=="south")
        {
            if (*(currentLoc+i)!='X')
            {
                currentLoc+=i;
                index+=i;
            }
            else
            {
                cout<<"You are trying to escape the arena, which is impossible. Chose a different direction."<<endl;
            }
        }
        else if(d=="east")
        {
            if (*(currentLoc+1)!='X')
            {
                currentLoc+=1;
                index+=1;
            }
            else
            {
                cout<<"You are trying to escape the arena, which is impossible. Chose a different direction."<<endl;
            }
        }
        else if(d=="west")
        {
            if (*(currentLoc-1)!='X')
            {
                currentLoc-=1;
                index-=1;
            }
            else
            {
                cout<<"You are trying to escape the arena, which is impossible. Chose a different direction."<<endl;
            }
        }
    }
protected:
    int index;
    char *currentLoc;
    void setName(string f, string l){ name = f+" "+l; };
    void setMind(double m){mind=m;}
    void setStr(double s){str=s;}
    void setSkill(double s){skill=s;}
    void setFit(double f){fitness=f;}
    void setGender(string g){gender=g;}
private:
    string name;
    double health;
    double mind;
    double str;
    double skill;
    double fitness;
    string gender;
    Weapon *weap;
};
class Player: public Character
{
public:
    Player(string f,string l,char *cl,double h,double m,double str,double s,double fit,string g)
    {
        setName(f, l);
        setHealth(h);
        setMind(m);
        setStr(str);
        setSkill(s);
        setFit(fit);
        setGender(g);
        setCurrentLoc(cl);
        index=24;
    }
    ~Player(){}
};
class NPC: public Character
{
public:
    NPC(string f,string l,char *cl,double h,double m,double str,double s,double fit,string g)
    {
        setName(f, l);
        setHealth(h);
        setMind(m);
        setStr(str);
        setSkill(s);
        setFit(fit);
        setGender(g);
        setCurrentLoc(cl);
        index=24;
    }
    ~NPC(){};
};
#endif
