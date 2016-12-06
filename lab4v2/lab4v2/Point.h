#pragma once
struct Point
{
	double x;
	double y;
};
std::istream & operator >> (std::istream &stream, Point & point);
typedef std::vector<Point> Vertices;