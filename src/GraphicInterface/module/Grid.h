#ifndef GRID_H_
#define GRID_H_

#include <SFML/Graphics.hpp>

#include <fstream>

class Grid {

public:
	static void initialize ();
	static void update ();

	static void setGridOnWidth (double size);
	static void setgridOnHeight (double size);

	static double getPrimary ();
	static double getSecondary ();

private:
	static double primary;
	static double secondary;

};

#endif