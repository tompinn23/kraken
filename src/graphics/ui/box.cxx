#include "widgets.hxx"

#include "spdlog/spdlog.h"
#include <string_view>

#define BOX_THIN_H 196
#define BOX_THIN_V 179
#define BOX_THIN_BL 192
#define BOX_THIN_BR 217
#define BOX_THIN_TL 218
#define BOX_THIN_TR 191

#define BOX_THICK_H 205
#define BOX_THICK_V 186
#define BOX_THICK_BL 200
#define BOX_THICK_BR 188
#define BOX_THICK_TL 201
#define BOX_THICK_TR 187


UIWidget::UIWidget(int x, int y) : x(x), y(y) {
	console = NULL;
}

UIWidget::~UIWidget() {
	delete console;
}


BoxWidget::BoxWidget(int x, int y, int width, int height) : UIWidget(x, y), 
	width(width), height(height), style(STYLE_THIN) {
	console = new TCODConsole(width, height);
}

int BoxWidget::update(TCOD_key_t key, uint32_t dt) {
	return 0;
}

void BoxWidget::_render() {
	console->clear();
	switch(style) {
		case STYLE_THIN:
			for(int x = 0; x < width; x++) {
				console->putChar(x, 0, BOX_THIN_H);
				console->putChar(x, height - 1, BOX_THIN_H);
			}
			for(int y = 0; y < height; y++) {
				console->putChar(0, y, BOX_THIN_V);
				console->putChar(width - 1, y, BOX_THIN_V);
			}
			console->putChar(0,0,BOX_THIN_TL);
			console->putChar(0, height - 1, BOX_THIN_BL);
			console->putChar(width -1, 0, BOX_THIN_TR);
			console->putChar(width - 1, height -1, BOX_THIN_BR);
			break;
		case STYLE_THICK:
			for(int x = 0; x < width; x++) {
				console->putChar(x, 0, BOX_THICK_H);
				console->putChar(x, height - 1, BOX_THICK_H);
			}
			for(int y = 0; y < height; y++) {
				console->putChar(0, y, BOX_THICK_V);
				console->putChar(width - 1, y, BOX_THICK_V);
			}
			console->putChar(0,0,BOX_THICK_TL);
			console->putChar(0, height - 1, BOX_THICK_BL);
			console->putChar(width -1, 0, BOX_THICK_TR);
			console->putChar(width - 1, height -1, BOX_THICK_BR);
			break;
		default:
		case STYLE_NONE:
			break;
	}
}

void BoxWidget::render(TCODConsole* destination) {
	_render();
	destination->blit(console, 0, 0, 0, 0, destination, x, y);
}

int MessageBox::update(TCOD_key_t key, uint32_t dt) {
	if(key.pressed) {
		return 1;
	}
	return 0;
}

void MessageBox::render(TCODConsole* destination) {
	BoxWidget::_render();
	/*
	std::string_view msg{message};
	if (message.length() <= width - 4) {
		console->print(2, 2, message);
	} else {
		for(int i = 0; i < height - 4; i++) {
			if(msg.length() > 0) {
				console->printRect(2, 2, width - 4, 1, msg.data());

			}
		}
	}
	*/
	console->printRect(2 ,2, (width - 4), height - 4, "%s", message.c_str());
	destination->blit(console, 0, 0, 0, 0, destination, x, y);
}


