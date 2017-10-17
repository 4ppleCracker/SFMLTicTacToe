#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include "gGraphics.h"
#include "Game.h"
using namespace std; using namespace sf;
// DECLARATIONS

// Functions
void Setup();
string Make2DArrayToString(char** matrix);
// Text and font
Font font;
Text text;
// Variables
int XScore;
int OScore;
bool reset;
char Player;
// OBJECTS

// Window and graphics
RenderWindow window(VideoMode(600, 500), "TicTacToe by Nobbele");
gGraphics graphics(window);

// Game logic and board (Check Game.cpp)
Game game(3, 3);

// DEFINITIONS

// Convert a 2 dimensional array into a single string
string Make2DArrayToString(char** matrix) {
	string s("");
	for (int i = 0; i < 3; i++) { // Cycle through 3 times
		for (int k = 0; k < 3; k++) { // Cycle through 3 times
			s.push_back(game.GetPlayerAtBoardPosition(i, k)); // Access the board placement at the current cycle for the for functions above
			s.push_back(char(32)); // Put a space after each column
		}
		s.push_back(char(10)); // Put a new line after each row
	}
	return s; // Return it all
}

// Returns the correct text to be shown on screen
string GraphicText() {
	return Make2DArrayToString(game.GetBoardMatrix()) + "\n it's " + Player + "'s turn" + "\n X: " + to_string(XScore) + " - O: " + to_string(OScore); // returns a long ass string
}

// Setup variables
void Setup() {
	Player = 'O'; // Starting player is O
	text.setFont(font); // Sets the correct font
	text.setString(GraphicText()); // Updates the text
	text.setCharacterSize(64); // Sets text size to 64
	text.setFillColor(Color::White); // Makes the text of white color
}

int main()
{
	// Check Setup() at the bottom of the file
	Setup();
	// Try and load the arial.ttf font, or else display and error message
	if (!font.loadFromFile("arial.ttf")) {
		return EXIT_FAILURE; // Failed to load the font
	}

	while (window.isOpen()) {
		graphics.Render(); // While the window is open, run the Render function constinously (Check gGraphics.cpp)
	}

    return EXIT_SUCCESS; // Successful exit
}

void gGraphics::WindowRender() { // Draw graphics
	window.draw(text); // Draw text
}
void gGraphics::Poll(Event event) { // Event handler
	char t = game.GetHasWon(); // set "t" to the win state (X or O)
	if (event.key.code == Keyboard::R || event.key.code == Keyboard::Numpad0 && reset) { // Pressed R or Numpad0
		game.NewGame(3, 3); // Generates a new board
		reset = false; // Make sure this function isn't repeated
		text.setString(GraphicText()); // Update the text
	}
	switch (event.type) { // What kind of event?
	case Event::Closed: // If program is closed
		window.close(); // Close the program
		break;
	case Event::KeyPressed: // If a key is pressed
		
		if (!game.GetIsOnReset()) { // And game is not at reset screen
			switch (event.key.code) { // What key is pressed?

				case Keyboard::Numpad7: // If it's numpad7
					if (game.Place(0, 0, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;
				case Keyboard::Numpad8: // If it's numpad8
					if (game.Place(0, 1, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;
				case Keyboard::Numpad9: // If it's numpad9
					if (game.Place(0, 2, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;
				case Keyboard::Numpad4: // If it's numpad4
					if (game.Place(1, 0, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;
				case Keyboard::Numpad5: // If it's numpad5
					if (game.Place(1, 1, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;
				case Keyboard::Numpad6: // If it's numpad6
					if (game.Place(1, 2, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;
				case Keyboard::Numpad1: // If it's numpad1
					if (game.Place(2, 0, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;
				case Keyboard::Numpad2: // If it's numpad2
					if (game.Place(2, 1, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;
				case Keyboard::Numpad3: // If it's numpad3
					if (game.Place(2, 2, Player) != 'u') Player == 'X' ? Player = 'O' : Player = 'X'; // Place tile on board and switch player
					break;

			}
		text.setString(GraphicText()); // Update text
		}
		break;
	}
	if (game.GetIsOnReset() && !reset) { // If game IS on reset
		reset = true; // Make sure this function isn't repeated
		string TextToPrint = ""; // Set text to print to nothing
		TextToPrint.push_back(t); // Place the player who won into the string
		(t == 'X' ? XScore : OScore) += 1; // Add 1 in score
		TextToPrint += " Has won \nthe game!\n\npress R \nor Numpad0\nto reset"; // Add this piece of text to the string
		text.setString(TextToPrint); // Set the game text to the string
	}
}

