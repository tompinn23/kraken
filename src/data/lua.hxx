#pragma once


#define SOL_ALL_SAFETIES_ON 1
#include "sol/sol.hpp"

#include <filesystem>
namespace fs = std::filesystem;

#include "config.hxx"

namespace data {

class LuaRuntime {
private:
	sol::state lua;
	fs::path data_dir;
public:
	LuaRuntime(fs::path data_dir);
	LuaConfig LoadConfig();	

};

}
