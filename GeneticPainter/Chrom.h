#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Helper.h"
using namespace sf; 
using namespace std; 
class Chrom
{
	static constexpr double range=0.2;
public: 
	
	double  x, y, w, h, angle; // range for mutation right now .9->1.1// angle (degrees )is going be between 0 and 180// x and y are the position;  the origin of the shape is going to be in the middle of the shape 
	unsigned  r, g, b, a; // the color ranging from 0 to 255
	
	RectangleShape shape; 
	// i want each constructor to create a shape using the dimensions
	Chrom();  // does nothing for now 
	Chrom(unsigned width, unsigned height); // this is going to make a rando shape with a rand postion withing the bounds of the model


	//Chrom(Chrom &parent ); // this is the one for mutations where it takes in the last succesful chrom then mutates it slightly to see if it gets a better result


	~Chrom(); 

	double static mutateRate(); // returns the number to multiply the field by 
	void createRand(unsigned width, unsigned height) // creates a random chrom
	{

		//creats the shape within the bounds 
		// remember to set origin too
		// make the fields random
		//pos is going to be between 0 and the bounds of the screen
		x = rand() % width;
		y = rand() % height;
		//size as well 
		w = rand() % width;
		h = rand() % height;
		//orentation
		angle = rand() % 180;
		//color 
		r = (int)(rand() % 255);
		b = (int)(rand() % 255);
		g = (int)(rand() % 255);
		a = (int)(rand() % 255);





		//setting fields of the shape  
		shape.setSize(Vector2f(w, h));// size
		shape.setOrigin(w / 2.0, h / 2.0); // set the shapes origin to the middle of the shape 
		shape.setFillColor(Color::Color(r, g, b, a));
		shape.setPosition(x, y);
		shape.rotate(angle);
	}
	void setEqual(Chrom c)
	{
		shape = c.shape; 
		x = c.x; 
		y = c.y; 
		w = c.w; 
		h = c.h; 
		angle = c.angle; 
		r = c.r; 
		g = c.g; 
		b = c.b; 
		a = c.a; 
	}

	

	
};

