#pragma once
#include "Chrom.h"	
double fit = -1;// if the picture has a greater fit than make change it to that 
unsigned verticalIt = 8, horizontalIt = 8; // the jump at which it checks pixels 
bool running = true, looking = true; // looking is going to be true when it is seraching random shapes and false when it is mutating one shape 
Chrom buffer;  // this is going to be set equal to the first shape that increases 
RenderWindow window; // what actually gets displayed ; the window 
RenderTexture evolved , current ;// the evolved picture ; if this has a better fit that the current, then the current is set equal to this 
double fit1=255, fit2=255; 
int noEvolution = 0; 
bool used;
vector<Chrom> chroms ; 
Texture model; // the model is what we are trying to replicate;  the width and height of the window should match the model
const unsigned attempts =1;  // the amount of "offspring" or tries each succesful chrom gets 
unsigned width, height; 
Sprite sprite; // going to have to make it a sprite before i can draw to window ; this is going to hold the winning texture 
void calcFit(); 
void init() // this is going to init the rendertexture and start the process 
{
	// set the dimensions of the windows 
	model.loadFromFile("images/sapp.jpg"); 
	width = model.getSize().x;
	height = model.getSize().y; 
	window.create(VideoMode(width, height), "GeneticPainter"); 
	
	
	
	
	chroms.push_back(Chrom(width, height )); // creates a rand chrom 

	// maybe make the rendertexture here too
	evolved.create(width, height); 
	
	current.create(width, height); 
	

}

void   calcFit(RenderTexture& evol)
{
	// if the fitness of evolved is greateer than current, change fitness to that 
	 // might need to return as a double
	fit1 = fit2; // the sum of the differences 
	fit2 = 0; 
	// get the absolute value of the difference between each pixel that gets checked
	for (int y = 0; y < height; y += verticalIt) // going by the vertical  iterator 
	{
		for (int x = 0; x < width; x += horizontalIt) // going vertical iterator
		{
			// slow but it has to do ig 
			Image modelImage = model.copyToImage();
			Image evolvedImage = evol.getTexture().copyToImage();
			fit2  += abs(modelImage.getPixel(x, y).r - evolvedImage.getPixel(x, y).r);
			fit2 += abs(modelImage.getPixel(x, y).b - evolvedImage.getPixel(x, y).b);
			fit2 += abs(modelImage.getPixel(x, y).g - evolvedImage.getPixel(x, y).g);
			 
		}
	}
	fit2 /= (model.getSize().x * model.getSize().y * 3*2.55); 
	// if this fit is less previous, set previous 

	
	
}
float randfloat(float  min, float  max)
{
	return (float)rand() / RAND_MAX * (max - min) + min;
}
Vector2f randVector2f(Vector2f const& min, Vector2f const& max)
{
	return Vector2f((float)(rand() / (float)RAND_MAX) * (max.x - min.x) + min.x, (float)(rand() / (float)RAND_MAX) * (max.y - min.y) + min.y);
}

/*bool makeOffspring(Chrom &parent ,RenderTexture &prevText )
{
	// mutates it to see if it can get better ; 
	for (int i =0 ; i<attempts; i++)
	{
		
		temp.create(width, height);
		temp.draw(Sprite(e.getTexture())); 
		Chrom child(parent);
		temp.draw(child.shape);
		// above code make it so that it compares the fit of the child to the fit of its parent
		double thisFit = calcFit(temp); 
		if (thisFit > fit)
		{
			
			fit = thisFit;
			evolved.clear(); 
			evolved.draw(Sprite(temp.getTexture()));
			sprite.setTexture(temp.getTexture());
			parent = child; // set the parent = to the better child 
			cout << fit << endl; 
			return true; 
			
		}
	}


	// if it gets to the end of the loop without finding a good offspring then should return false or sum meaning to end loop 
	return false; 
}*/
