
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "data/lua.hxx"
#include "graphics/ui/widgets.hxx"

#include "libtcod/libtcod.hpp"

int main(int argc,char** argv) {
	spdlog::set_pattern("[%n] %^%l%$ %v");
	auto console = spdlog::stdout_color_st("main_logger");
	console->info("Kraken: v1.0.0");
	console->info("Loading config");
	auto lua = data::LuaRuntime(".");
	auto conf  = lua.LoadConfig();
	TCODConsole::setCustomFont("Alloy.png", TCOD_FONT_LAYOUT_ASCII_INROW);
	TCODConsole::initRoot(80, 60, "KRKN 2", false);
	auto root = TCODConsole::root;
	root->clear();
	root->putChar(2, 2, 'A');
	root->flush();
	auto wid = MessageBox(3, 4, 20, 10, "Hello World");
	wid.set_style(BoxWidget::STYLE_THICK);
	wid.render(root);
	root->flush();
	getc(stdin);
	return 0;
}
