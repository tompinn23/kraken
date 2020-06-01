#include "game.hxx"

#include "libtcod/libtcod.hpp"

void Game::Init() {

}

void Game::Run() {
	while(!TCODConsole::isWindowClosed()) {
		TCOD_key_t key;
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
		// Global keypresses
		// Current widget keypresses
		//ui->current->update(key);
	}
}

void Game::Exit() {

}
