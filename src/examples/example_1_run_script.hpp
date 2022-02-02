


void example_1_run_script() 
{
    std::cout << "--- example_1_run_script ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, "./scripts/example_1_run_script.lua") == LUA_OK) {
        std::cout << "[C] Executed example_1_run_script.lua\n";
    } else {
        std::cout << "[C] Error reading script\n";
        luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }

    lua_close(L);

    std::cout << '\n';

}