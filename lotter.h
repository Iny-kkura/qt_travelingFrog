#pragma once
#include<iostream>
#include<map>
#include<random>
#include<ctime>
#include"frog.h"
#define YELLOW 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define WHITE 5

class Lotter
{
public:
    static std::map<std::string, int> rank;
        static const int rankmax =100;
    //static int& num ;

        //static int& getRaffle(int& num) //as an API
       // {
          //  return num;
        //}

    static bool startLotter(Frog * f)//judge appearance and reduce raffle
        {

            if (f->get_raffle()>= 5)
            {
                f->set_raffle(-5);//need to add the change of ui
                return true;
            }
            return false;
        }
        static int lottering()	//begin
        {
            std::srand((unsigned)time(NULL));//set the seed
            int res = rand() % rankmax;

            if (res < Lotter::rank["yellow"])
                return YELLOW;
            else if (res < Lotter::rank["red"])
                return RED;
            else if (res < Lotter::rank["green"])
                return GREEN;
            else if (res < Lotter::rank["blue"])
                return BLUE;
            else
                return WHITE;
        }
};

