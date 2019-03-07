//
//  MISCfunc.h
//  Adventure
//
//  Created by Charlie  Velazquez on 11/23/16.
//  Copyright © 2016 GoonPlatoon. All rights reserved.
//

#ifndef MISCfunc_h
#define MISCfunc_h

void sleep(int seconds)
{
    long long int goal = time(NULL) +seconds;
    while(time(NULL) < goal)
    {
    }
}
int deathCount(Character *p[])
{
    int count=0;
    for (int i=0; i<24; i++)
    {
        if (p[i]->getHealth()==0)
        {
            count++;
        }
    }
    return count;
}
           
void battle(Character *a,Character *b)
{
    double aAVG = a->getFit() + a->getStr() + a->getMind() + a->getSkill();
    double bAVG = b->getFit() + b->getStr() + b->getMind() + b->getSkill();
    aAVG = aAVG/4;
    bAVG = bAVG/4;
    if(aAVG < bAVG)
    {
        a->setHealth(0);
        cout<<b->getName()<<" has KILLED "<<a->getName()<<" using ";
        if (b->getGender()=="male")
        {
            cout<<"his ";
        }
        else
        {
            cout<<"her ";
        }
        cout<<(b->getWeapon())->getName()<<endl;
    }
    else if(aAVG > bAVG)
    {
        b->setHealth(0);
        cout<<a->getName()<<" has KILLED "<<b->getName()<<" using ";
        if (a->getGender()=="male")
        {
            cout<<"his ";
        }
        else
        {
            cout<<"her ";
        }
        cout<<(a->getWeapon())->getName()<<endl;
    }
    else
    {
        a->setHealth(a->getHealth()-50);
        b->setHealth(b->getHealth()-50);
        cout<<b->getName()<<" fought hard against "<<a->getName()<<endl;
        if (a->getHealth()==0 && b->getHealth()==0)
        {
            cout<<"Both being weakend from a previous battle they both die\n";
        }
        else if (a->getHealth()==0)
        {
            cout<<"Having been weakend from a previous battle "<<a->getName()<<" is killed by "<<b->getName()<<endl;
        }
        else if (b->getHealth()==0)
        {
            cout<<"Having been weakend from a previous battle "<<b->getName()<<" is killed by "<<a->getName()<<endl;
        }
    }
    sleep(1);
}

void moveBattle(Character *x, Character* y[])
{
    
    for (int i=0; i<24; i++)
    {
        if( (y[i]->getIndex()==x->getIndex()) && (y[i]->getHealth())>0 && (x->getHealth())>0 && (x!=y[i]) )
        {
            battle(x,y[i]);
        }
    }
    
}

void updateMap(Character *x)
{
    pMap[x->getIndex()] = Map[x->getIndex()];
}
void weaponRack(Weapon *r[])
{
    for (int i=0; i<24; i++)
    {
        r[i]=Weapon::makeWeap(rand()%8);
    }
}
//    printMap(Map,mapKey);
void printMap(Character* p,char x[],string k)
{
    for (int i=0; i<49; i++)
    {
        if (i==p->getIndex())
        {
            cout<<"("<<x[i]<<")";
        }
        else
        {
            cout<<" "<<x[i]<<" ";
        }
        if (i==6||i==13||i==20||i==27||i==34||i==41)
        {
            cout<<endl;
        }
    }
    cout<<"\nKey:"<<endl;
    cout<<k<<endl;
}
void reveal(Character* p[],char x[],string k)
{
    for (int i=0; i<49; i++)
    {
        bool flag=false;
        for (int z=1; z<24; z++)
        {
            if (p[z]->getIndex()==i && p[z]->getHealth()>0)
            {
                flag=true;
            }
        }
        if (flag)
        {
            cout<<"("<<x[i]<<")";
        }
        else
        {
            cout<<" "<<x[i]<<" ";
        }
        if (i==6||i==13||i==20||i==27||i==34||i==41)
        {
            cout<<endl;
        }
    }
    cout<<"\nKey:"<<endl;
    cout<<k<<endl;
}
void printStats(Character *x)
{
    Character& thisCon = *x;
    cout<<"Health: "<<thisCon.getHealth()<<"\nStrength: "<<thisCon.getStr()<<"\nMind: "<<thisCon.getMind()<<"\nFitness: "<<thisCon.getFit()<<"\nSkill: "<<thisCon.getSkill()<<"\n"<<endl;
}
void scout(Character *p[],string d)
{
    int pI=0,amnt=0;
    if (d=="north")
    {
        pI=(p[0]->getIndex())-7;
    }
    else if (d=="south")
    {
        pI=(p[0]->getIndex())+7;
    }
    else if (d=="east")
    {
        pI=(p[0]->getIndex())+1;
    }
    else if (d=="west")
    {
        pI=(p[0]->getIndex())-1;
    }
    for (int i=1; i<24; i++)
    {
        if (p[i]->getIndex()==pI && p[i]->getHealth()>0)
        {
            amnt++;
        }
    }
    if (amnt>1)
    {
        cout<<"There are "<<amnt<<" contestants "<<d<<" of your position.\n";
    }
    else
    {
        cout<<"There is "<<amnt<<" contestant "<<d<<" of your position.\n";
    }
}


#endif /* MISCfunc_h */
