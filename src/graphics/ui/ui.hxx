#pragma once

#include "libtcod/libtcod.hpp"

class UIWidget {
protected:
	int x;
	int y;

	TCODConsole* console;
public:
	UIWidget(int x, int y);
	~UIWidget();
	virtual	int update(TCOD_key_t key, uint32_t dt) = 0;
	virtual	void render(TCODConsole* destination) = 0;
};





class Ui {
public:
	UIWidget* current;
	
};
