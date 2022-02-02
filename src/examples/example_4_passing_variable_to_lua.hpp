

void example_4_passing_variable_to_lua() 
{
    std::cout << "--- example_4_passing_variable_to_lua ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    int bar = 199;
    std::cout << "[C] Declared bar = " << bar <<  '\n';

    lua_pushnumber(L, bar);
    lua_setglobal(L, "bar");
    
    if (luaL_dofile(L, "./scripts/example_4_passing_variable_to_lua.lua") == LUA_OK) {
        std::cout << "[C] Executed example_4_passing_variable_to_lua.lua\n";
    } else {
        std::cout << "[C] Error reading script\n";
        luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }
    lua_close(L);

    std::cout << '\n';

}