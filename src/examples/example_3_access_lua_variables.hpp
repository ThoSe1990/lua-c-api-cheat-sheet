

void example_3_access_lua_variables() 
{
    std::cout << "--- example_3_access_lua_variables ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, "./scripts/example_3_access_lua_variables.lua") == LUA_OK)
    {
        lua_getglobal(L, "foo");
        lua_Number foo_in_c = lua_tonumber(L, -1);
        std::cout << "[C] Received lua's foo with value " << foo_in_c << '\n';
    }
    else 
        std::cout << "[C] Error reading script\n";

    lua_close(L);

    std::cout << '\n';

}