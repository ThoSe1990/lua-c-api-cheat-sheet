

void example_4_passing_variable_to_lua() 
{
    std::cout << "--- example_4_passing_variable_to_lua ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    int foo = 199;
    std::cout << "[C] Declared foo = " << foo <<  '\n';

    lua_pushnumber(L, foo);
    lua_setglobal(L, "foo");
    
    if (luaL_dofile(L, "./scripts/example_4_passing_variable_to_lua.lua") == LUA_OK)
        std::cout << "[C] Executed example_4_passing_variable_to_lua.lua\n";
    else 
        std::cout << "[C] Error reading script\n";

    lua_close(L);

    std::cout << '\n';

}