#include"lotter.h"
using namespace std;
map<string, int>Lotter::rank{make_pair("yellow", 1), make_pair("red", 3), make_pair("green", 9), make_pair("blue", 27), make_pair("white", 60)};
//int Lotter:: num;
//int rankmax = 100;
//set possibility

/*bool Lotter::startLotter()
{
	int& cur_raffle = Lotter::getRaffle();
	if (cur_raffle >= 5)
	{
        cur_raffle -= 5;
		return true;
	}
	return false;
}
string Lotter::lottering()
{
         std::srand((unsigned)time(NULL));
	int res = rand() % rankmax;
	if (res < Lotter::rank["yellow"])
		return "yellow";
	else if (res < Lotter::rank["red"])
		return "red";
	else if (res < Lotter::rank["green"])
		return "green";
	else if (res < Lotter::rank["blue"])
		return "blue";
	else
		return"white";
}*/
