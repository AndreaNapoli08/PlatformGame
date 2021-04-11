#include "Controller.hpp"
#include <iostream>

Controller::Controller(View *view) {
	this->view = view;
	player = new Player(0, 0);
	player2 = new Player(10, 10);
	time = 0;
}
	
void Controller::run() {
	view->createWindow(	);
	bool quit = false;
	char* name = player->getName();

	do {
		view->info_commands(2, 2, 20, 50, name, time, player->getLife(), player->getPoints());
		view->drawMap(2, 2, 20, 50);
		int input = view->getKeyboardInput();
		switch (input) {
			case 113:			// 'q'
				quit = true;
				break;
			case 101:			// 'e'
				player->shoots(time);
				break;
		}

		player->move(input, 48, 18);

		view->clearWindow();

		view->drawPlatform(10,10, 6);
		view->printObject(player->getX()+3, player->getY()+3, (char *)"%s", (char *)"S");
		
		p_shot tmp_shot, shot = player->getShotHead();

		while (shot != __null) {
			view->printObject(shot->x+3, shot->y+3, (char *)"%s", (char *)"---");
			tmp_shot = shot->next;
			player->updateShot(shot, view->getWidth());
			shot = tmp_shot;
		}
		view->update();
		time += (double)view->getDelay() / 1000;
	} while (!quit);
	
	view->exitWindow();
}