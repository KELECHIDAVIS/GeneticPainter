#include <iostream>
#include "Helper.h"



void draw(RenderWindow& window)
{
	/*window.clear(Color::White);

	window.draw(sprite); 
	window.display();*/
}

void update() 
{
	// every loop I want to make a new rendertexture draw and draw a rand chrom on it. 
	// *if the chrom is successful set that actual rendertexture = to that render texture 
		//then keep making offspring from the succesful chrom until the process is not successful anymore ()
	//* if chrom is not successful, meaning it doesn't increase overall fit, then keep making random chroms until they do.
	// the loop of mutating the shape is going to keep on going until this is 

	// need to  make sure to draw the last successful one regardless every frame
	for (int l =0 ; l< 1 ; l++)
	{
		int i = chroms.size() - 1;
		buffer = chroms[i];
		// mutate all its fields slightly 
		chroms[i].shape.move(randVector2f(Vector2f(-5, 5), Vector2f(-5, 5)));
		chroms[i].shape.scale(randVector2f(Vector2f(-5, 5), Vector2f(-5, 5)));
		chroms[i].shape.rotate(randfloat(-5, 5));
		int r = 0, g = 0, b = 0, a = 0;
		r += randfloat(-10, 10);
		g += randfloat(-10, 10);
		b += randfloat(-10, 10);
		a += randfloat(-10, 10);
		chroms[i].shape.setFillColor(Color(chroms[i].shape.getFillColor().r + r, chroms[i].shape.getFillColor().g + g, chroms[i].shape.getFillColor().b + b, chroms[i].shape.getFillColor().a + a));

		// set evolved equal to current 
		evolved.clear(Color::White);
		evolved.draw(Sprite(current.getTexture()));
		evolved.draw(chroms[i].shape);
		evolved.display();

		calcFit(evolved);

		if (fit2 >= fit1) // worse fit 
		{
			fit2 = fit1;
			noEvolution++;
			if (!used) {
				chroms[i] = Chrom(width, height);
				noEvolution = 0;
			}
			else
			{
				chroms[i] = buffer;
			}
		}
		else // better fit 
		{

			cout << "Mutation Fit: " << fit2 << "\n";
			used = true;
			noEvolution = 0;
			// draw the evolved one to the window 
			window.clear(Color::White);
			window.draw(Sprite(evolved.getTexture()));
			window.display();

		}


		if (noEvolution > 500) // been on the same shape for too long and it has finished evolving 
		{
			if (!used)
			{
				chroms.pop_back();
				evolved.clear(Color::White);
				evolved.draw(Sprite(current.getTexture()));
				evolved.display();
			}
			else
			{
				evolved.clear(Color::White);
				evolved.draw(Sprite(current.getTexture()));
				evolved.draw(buffer.shape);
				evolved.display();

				current.clear(Color::White);
				current.draw(Sprite(evolved.getTexture()));
				current.display();
			}

			chroms.push_back(Chrom(width, height)); // adds a rand to the array 
			cout << "New Shape count" << chroms.size() << "\n";
			noEvolution = 0;
			used = false;
		}


	}
	
	
	


}



void pollEvents(RenderWindow& window)
{
	Event ev;
	while (window.pollEvent(ev))
	{
		switch (ev.type)
		{
		case Event::Closed:
			window.close();
			running = false;
			break;
		case Event::KeyPressed:
			switch (ev.key.code)
			{
			case Keyboard::Escape:
				window.close();
				running = false;
				break;

			}
			break;
		}
	}

}










int main()
{
	srand(time(NULL)); 
	// do need to initializes the reference window then start the drawing reference 
	init(); 
	
	// every loop I want to make a new rendertexture draw and draw a rand chrom on it. 
	// *if the chrom is successful set that actual rendertexture = to that render texture 
		//then keep making offspring from the succesful chrom until the process is not successful anymore ()
	//* if chrom is not successful, meaning it doesn't increase overall fit, then keep making random chroms until they do.

	

	while (running)
	{
		pollEvents(window);

		update();

		/*draw(current);*/ // draw the best texture to the screen  
	}

	return 0;
}

