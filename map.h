#pragma once
#include<vector>
#include<string>
#include<time.h>
#include<ctime>
#define MAXCITY 5
class Node
{
public:
    int value;
	bool isvisited;
    std::string name;
	Node(int v,bool is,std::string n):value(v),isvisited(is),name(n){}
};
class Cities
{
	
    bool neighbors[MAXCITY][MAXCITY];//neighbor matrix
	std::vector<Node> cityList;
public:
    Cities();
    Node& selectDestination();
};

class Mail
{
public:
    static std::string mail(bool ishome)
    {
        if(ishome)
            return nullptr;
        Cities nowcity;
        Node chosencity=nowcity.selectDestination();
        return chosencity.name;
    };

};

