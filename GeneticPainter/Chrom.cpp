#include "Chrom.h"

Chrom::Chrom()
{
}

Chrom::Chrom(unsigned width, unsigned height)
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
	g= (int)(rand() % 255);
	a = (int)(rand() % 255);


	


	//setting fields of the shape  
	shape.setSize(Vector2f( w, h));// size
	shape.setOrigin(w / 2.0, h / 2.0); // set the shapes origin to the middle of the shape 
	shape.setFillColor(Color::Color(r, g, b, a)); 
	shape.setPosition(x, y); 
	shape.rotate(angle); 

}

//Chrom::Chrom(Chrom& parent) // this one we don't have to do much we just have to set the child shape equal to the parents the mutate it 
//	// each parent is going to have a bunch of children the; the best one out the family is compared to the fit, if it is an increse then add it to the window. 
//{
//	//inherits from the parent and mutates all the values slightly 
//	x = parent.x * Chrom::mutateRate();
//	y = parent.y * Chrom::mutateRate();
//	//size as well 
//	w = parent.w * Chrom::mutateRate();
//	h = parent.h * Chrom::mutateRate();
//	//orentation
//	angle = parent.angle;
//	//color 
//	r = parent.r * Chrom::mutateRate();
//	b = parent.b * Chrom::mutateRate();
//	g = parent.g * Chrom::mutateRate();
//	a = parent.a * Chrom::mutateRate();
//
//	// mutate all the values slightly ; 
//	shape.setSize(Vector2f(w, h));// size
//	shape.setOrigin(w / 2.0, h / 2.0); // set the shapes origin to the middle of the shape 
//	shape.setFillColor(Color::Color(r, g, b, a));
//	shape.setPosition(x, y);
//	shape.rotate(angle);
//
//
//}

Chrom::~Chrom()
{
}

double Chrom::mutateRate()
{
	
	double rate = 1; 
	rate -= range / 2.0; 
	double add=  (float )rand()/RAND_MAX;  // it gets a rand num from 0 to 1 then multiplies it by range so the num is from 0 to range ; then it adds it to the rate 

	add *= range; 
	rate += add; 
	return rate ;
}


