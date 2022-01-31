



void example_9_reading_lua_array_in_c() 
{
    std::cout << "--- example_9_reading_lua_array_in_c ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    
    if (luaL_dofile(L, "./scripts/example_9_reading_lua_array_in_c.lua") == LUA_OK) 
    {
        std::cout << "[C] Executed example_9_reading_lua_array_in_c.lua\n";
        lua_getglobal(L, "foo");

        lua_rawgeti(L, -1, 1);
        auto first = lua_tonumber(L, -1);
        
        lua_rawgeti(L, -2, 2);
        auto second = lua_tonumber(L, -1);        
        
        lua_rawgeti(L, -3, 3);
        auto third = lua_tonumber(L, -1);

        std::cout << "[C] Got table foo from lua with:\n" <<
            "[C] foo[1] = " << first << '\n' <<
            "[C] foo[2] = " << second << '\n' <<
            "[C] foo[3] = " << third << '\n' ;
    }
    else 
        std::cout << "[C] Error reading script\n";

    lua_close(L);

    std::cout << '\n';
}