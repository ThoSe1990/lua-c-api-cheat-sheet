



void example_10_reading_lua_tablearray_in_c() 
{
    std::cout << "--- example_10_reading_lua_tablearray_in_c ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    
    if (luaL_dofile(L, "./scripts/example_10_reading_lua_tablearray_in_c.lua") == LUA_OK) {
        std::cout << "[C] Executed example_10_reading_lua_tablearray_in_c.lua\n";
        lua_getglobal(L, "foo");
        if (lua_istable(L, -1)) 
        {
            lua_pushnumber(L, 1);
            lua_gettable(L, -2);
            if (lua_istable(L, -1)) { 
                lua_getfield(L, -1, "bar");
                auto bar = lua_tonumber(L, -1);
                lua_getfield(L, -2, "baz");
                auto baz = lua_tostring(L, -1);
            
                std::cout << "[C] foo[1].bar = " << bar << '\n' <<
                            "[C] foo[1].baz = " << baz << '\n' ;
            } else {
                std::cout << "[C] There's apparently no table on the stack top\n";
                luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
            }
            
            lua_pushnumber(L, 2);
            lua_gettable(L, -5);
            if (lua_istable(L, -1)) { 
                lua_getfield(L, -1, "bar");
                auto bar = lua_tonumber(L, -1);
                lua_getfield(L, -2, "baz");
                auto baz = lua_tostring(L, -1);
            
                std::cout << "[C] foo[2].bar = " << bar << '\n' <<
                            "[C] foo[2].baz = " << baz << '\n' ;
            } else {
                std::cout << "[C] There's apparently no table on the stack top\n";
                luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
            }
        } else {
            std::cout << "[C] There's apparently no table on the stack top\n";
            luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
        }
    } else {
        std::cout << "[C] Error reading script\n";
        luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }

    lua_close(L);

    std::cout << '\n';
}