#pragma once
#include<QPoint>
#include<QString>

class Clovers_pro
{
public:
	static int square_1[4];
	static int square_2[4];
    static int square_3[4];
    static QString&  produceClovers_kind()//about which pic to use
	{

		int kind = rand() % 3;
                QString* str=new QString;
                switch(kind)
                {
                    case(0):*str="/clover_154.png";break;
                    case(1):*str="/clover_160.png";break;
                    case(2):*str="/clover_166.png";break;
                }

        return *str;
	}
    static QPoint produceClovers()//about where to grow
	{

        int kind = rand() % 2;
		int x=square_1[0], y=square_1[2];
		switch (kind)
		{
        case(0):
			x = rand() % (square_1[1] - square_1[0]) + square_1[0];
			y= rand() % (square_1[3] - square_1[2]) + square_1[2];
			break;
        case(1):
			x = rand() % (square_2[1] - square_2[0]) + square_2[0];
			y = rand() % (square_2[3] - square_2[2]) + square_2[2];
			break;
        case(2):
                    x = rand() % (square_3[1] - square_3[0]) + square_3[0];
                    y = rand() % (square_3[3] - square_3[2]) + square_3[2];
                    break;
		default:
			break;
		}
        QPoint tmp(x, y);
		return tmp;
	}
};
