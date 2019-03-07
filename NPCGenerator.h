//
//  NPCGenerator.h
//  Adventure
//
//  Created by Charlie  Velazquez on 11/15/16.
//  Copyright © 2016 GoonPlatoon. All rights reserved.
//

#ifndef NPCGenerator_h
#define NPCGenerator_h
#include "Character.h"
#include <iostream>     // std::cout
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <array>

string fNamesM[] = {"Benny","Gerard","Andrew","Alex","Corben","Giaus","Jesse","John","Jake","Lance","Phin","Xander","Haram","Floyd","Jerry","Kimbo","Ajax","Blade","Tony","Zaine","Rob","Gage","Gunther","Zach"};
string fNamesF[] ={"Lisa","Celeste","Cleo","Gwen","Lyra","Olivia","MoMo","Vernice","Ashley","Silvia","Helga","Gisela","Maryanne","Kimberley","Liz","Becca","Josie","Beatrice","Gloria","Kate","Sasha","Trish","Ebony","Mia"};
string lNamesB[] = {"Davidson","Aguliar","Smith","Colfax","Jager","Ishtar","Samus","Cortez","Rios","Watson","Dawrin","Montoya","West","Arthur","Wolfe","Stribling","Petty","Burton","Lawler","Cambell","Caldwell","Sander","Sugata","Miagi","O'Connor","Digorno","Guillory","Chavez","Miamoto","Lee","Muler","Ronaldo"};

void randomShuffle(string a[],int s)
{
    int index= rand() % s;
    int index2= rand() % s;
    if (index!=index2)
    {
        string temp= a[index];
        a[index]=a[index2];
        a[index2]=temp;
    }
}
void  shuffleNames() {
    for (int i=0; i<12; i++)
    {
        randomShuffle(fNamesM,24);
        randomShuffle(fNamesF,24);
        randomShuffle(lNamesB,32);
    }
}

void NPCgen(Character* x[],string g)
{
    string prevGender=g;
    for (int i=1; i<24; i++)
    {
        if (prevGender == "male")
        {
            x[i] = new NPC(fNamesF[i/2], lNamesB[i], &(Map[24]), 100, rand()%10+1, rand()%10+1, rand()%10+1, rand()%10+1, "female");
            randomShuffle(fNamesM,24);
            randomShuffle(fNamesF,24);
            randomShuffle(lNamesB,32);
            prevGender= "female";
        }
        else
        {
            x[i] = new NPC(fNamesM[i/2], lNamesB[i], &(Map[24]), 100, rand()%10+1, rand()%10+1, rand()%10+1, rand()%10+1, "male");
            randomShuffle(fNamesM,24);
            randomShuffle(fNamesF,24);
            randomShuffle(lNamesB,32);
            prevGender= "male";
        }
    }
}

#endif
