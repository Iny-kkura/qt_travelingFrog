#include"map.h"
#include<iostream>
//srand((unsigned)time(NULL))
//Node::Node(int v, bool is, std::string n):value(v),isvisited(is),name(n){}
Cities::Cities()
{
	for (int i = 0; i < MAXCITY; ++i)
	{
		for (int j = 0; j < MAXCITY; ++j)
		{
			if (j == i + 1)
                neighbors[i][j] = true;
			else
				neighbors[i][j] = false;
		}
	}
	Node city_01(10, false, "crab"),city_02(10,false,"forest"),city_03(10,false,"raining"),city_04(10,false,"star"),city_05(10,false,"street");
	cityList.push_back(city_01);
	cityList.push_back(city_02);
	cityList.push_back(city_03);
	cityList.push_back(city_04);
	cityList.push_back(city_05);

}
Node& Cities::selectDestination()
{
	int choice = rand()%MAXCITY;
	
	return cityList[choice];
}
