#include "lua.hxx"

namespace data {
	LuaRuntime::LuaRuntime(fs::path data_dir) {
		lua.open_libraries(sol::lib::base);
		this->data_dir = fs::absolute(data_dir);
	}

	LuaConfig LuaRuntime::LoadConfig() {
		sol::environment fuck_all(lua, sol::create);
		auto bad_code_result = lua.script_file(data_dir / "config.lua", fuck_all);
		LuaConfig config;
		config.default_tm = fuck_all.get_or<std::string>("tilemap", "Alloy.png");
		return config;
	}
}
