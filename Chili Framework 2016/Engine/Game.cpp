/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <cstdlib>
#include <time.h>
#include "Snake.h"
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(rd()),
	snek({ 5,5 }),//passing a location to a snek
	snekFruit({3, 10})
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{


	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		delta_loc = { 0, -1 };		
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		delta_loc = { 0, 1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		delta_loc = { -1, 0 };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		delta_loc = { 1, 0 };
	}

	

	++snekMoveCounter;
	if (snekMoveCounter >= snekMovePeriod) {
		snek.Update(brd);
		if (snekFruit.CheckIfEaten(snek.GetHeadLocation()) == true) {
			snek.Grow();
		}
		
		//if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
			
		//}
		snekMoveCounter = 0;
		snek.MoveBy(delta_loc);
	}
	if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
		snek.Reset({ 5, 5 });
		delta_loc = { 0, 0 };
	}


}

void Game::ComposeFrame()
{

	if (snek.alive) {
		snekFruit.Spawn(brd);
		snek.Draw(brd);
	}
	gfx.drawBorder(brd.GetDimension(), Colors::Blue);

}
