



void example_8_reading_lua_table_in_c() 
{
    std::cout << "--- example_8_reading_lua_table_in_c ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    
    if (luaL_dofile(L, "./scripts/example_8_reading_lua_table_in_c.lua") == LUA_OK) 
    {
        std::cout << "[C] Executed example_8_reading_lua_table_in_c.lua\n";
        lua_getglobal(L, "foo");
        if (lua_istable(L, -1)) 
        {
            lua_getfield(L, -1, "foo_number");
            auto foo_number = lua_tonumber(L, -1);
            
            lua_getfield(L, -2, "bar_number");
            auto bar_number = lua_tonumber(L, -1);

            lua_getfield(L, -3, "foo_string");
            auto foo_string = lua_tostring(L, -1);
            
            lua_getfield(L, -4, "bar_string");
            auto bar_string = lua_tostring(L, -1);

            std::cout << "[C] Got table foo from lua with:\n" <<
                "foo_number = " << foo_number << '\n' <<
                "bar_number = " << bar_number << '\n' <<
                "foo_string = " << foo_string << '\n' <<
                "bar_string = " << bar_string << '\n';
        }
    }
    else 
        std::cout << "[C] Error reading script\n";

    lua_close(L);

    std::cout << '\n';
}