#pragma once


#include "ui.hxx"

class BoxWidget : public UIWidget {
public:
	enum boxStyle {
		STYLE_THIN,
		STYLE_THICK,
		STYLE_CHAR,
		STYLE_NONE
	};
	BoxWidget(int x, int y, int width, int height);
	int update(TCOD_key_t key, uint32_t dt);
	void render(TCODConsole* destination);
	void set_style(boxStyle style) { style= style; }
protected:
	void _render();
	boxStyle style;
	int width;
	int height;
};

class MessageBox : public BoxWidget {
public:
	MessageBox(int x, int y, int width, int height, std::string message) :
		BoxWidget(x, y, width, height), message(message) {}
	int update(TCOD_key_t key, uint32_t dt);
	void render(TCODConsole* destination);
private:
	std::string message;

};

class DialogueBox : public BoxWidget {
public:
	int update(TCOD_key_t key, uint32_t dt);
	void render(TCODConsole* destination);
private:
	std::string message;
};


class MainView : public UIWidget {
public:
	int update(TCOD_key_t key, uint32_t dt);
	void render(TCODConsole* destination);
	TCODConsole* get_con();
};
