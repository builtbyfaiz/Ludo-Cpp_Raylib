#include <vector>
#include <iostream>
#include "raylib.h"
#include "ludoCells.hpp"
#include "constants.hpp"

int main()
{
	//Init Window, Set FPS etc.
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(750, 750, "Ludo");

	ludoCells cells;

	// Game loop
	while (!WindowShouldClose()) // Run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		//Rendering
		BeginDrawing();
		ClearBackground(BLACK);

		cells.draw();

		EndDrawing();
	}

	// cleanup
	CloseWindow();

	return 0;
}
