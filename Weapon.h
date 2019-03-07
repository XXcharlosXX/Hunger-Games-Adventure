//
//  Weapon.h
//  Adventure
//
//  Created by Charlie Velazquez & Ty Fitch on 11/13/16.
//  Copyright © 2016 GoonPlatoon. All rights reserved.
//
#ifndef WEAPON_H //makes sure we dont define it twice
#define WEAPON_H //ditto^
using namespace std; //uses standard namespace

class Weapon //creates a generic weapon
{
public:
    Weapon(){};
    virtual ~Weapon(){};
    static Weapon* makeWeap(int n);
    string getType()const{return type;}
    string getName()const{return name;}
    int getBuff(){return buff;}
    
protected:
    int buff;
    void setType(string x){type=x;}
    void setName(string x){name=x;}
    string type;
    string name;
    
};

class Melee : public Weapon //create melee weapons
{
public:
    Melee(){type = "Melee";};
    ~Melee(){};
};

class Magic : public Weapon //create magic weapon
{
public:
    Magic(){type = "Magic";};
    ~Magic(){};
};
class Range : public Weapon //create range weapon
{
public:
    Range(){type = "Range";};
    ~Range(){};
    int getCount()const{return count;}
protected:
    void setCount(int x){count=x;}
    int count;
};

class Armor : public Weapon //create armor
{
public:
    Armor(){type = "Armor";};
    ~Armor(){};
};

//the following classes creates different types of armors, ranges weapons, melee weapons, and magic weapons

class Helm : public Armor
{
public:
    Helm(){buff= 1;name="Helm";}
    ~Helm(){};
};

class Breastplate : public Armor
{
public:
    Breastplate(){buff = 2;name="Breastplate";}
    ~Breastplate(){};
};

class Bow : public Range
{
public:
    Bow(){buff = 1;name="Bow and Arrows";count=10;}
    ~Bow(){};
};

class NinjaStars : public Range
{
public:
    NinjaStars(){buff = 1;name="NinjaStars";count=5;}
    ~NinjaStars(){};
};

class Staff : public Magic
{
public:
    Staff(){buff = 2;name="Staff";}
    ~Staff(){};
};


class Wand : public Magic
{
public:
    Wand(){buff = 1;name="Wand";}
    ~Wand(){};
};

class Axe : public Melee
{
public:
    Axe(){buff = 2;name="Axe";}
    ~Axe(){};
};

class Fists : public Melee
{
public:
    Fists(){buff = 0;name="Fists";}
    ~Fists(){};
};

class Sword : public Melee
{
public:
    Sword(){buff = 3;name="Sword";}
    ~Sword(){};
};

Weapon* Weapon::makeWeap(int n)
{
    if (n == 1)
        return new Sword();
    else if (n == 2)
        return new Axe();
    else if (n == 3)
        return new Breastplate();
    else if (n == 4)
        return new Helm();
    else if (n == 5)
        return new Bow();
    else if (n == 6)
        return new NinjaStars();
    else if (n == 7)
        return new Wand();
    else
        return new Staff();
}


#endif
