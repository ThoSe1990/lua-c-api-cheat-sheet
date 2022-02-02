



void example_11_reading_lua_tablearray_alternative() 
{
    std::cout << "--- example_11_reading_lua_tablearray_alternative ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    
    if (luaL_dofile(L, "./scripts/example_11_reading_lua_tablearray_alternative.lua") == LUA_OK) {
        std::cout << "[C] Executed example_11_reading_lua_tablearray_alternative.lua\n";
        lua_getglobal(L, "foo");
        if (lua_istable(L, -1)) 
        {
            lua_getfield(L, -1, "foo_1");
            if (lua_istable(L, -1)) 
            { 
                lua_getfield(L, -1, "bar");
                auto bar = lua_tonumber(L, -1);
                lua_getfield(L, -2, "baz");
                auto baz = lua_tostring(L, -1);
            
                std::cout << "[C] foo.foo_1.bar = " << bar << '\n' <<
                            "[C] foo.foo_1.baz = " << baz << '\n' ;
            }
            
            lua_getfield(L, -4, "foo_2");
            if (lua_istable(L, -1)) 
            { 
                lua_getfield(L, -1, "bar");
                auto bar = lua_tonumber(L, -1);
                lua_getfield(L, -2, "baz");
                auto baz = lua_tostring(L, -1);
            
                std::cout << "[C] foo.foo_2.bar = " << bar << '\n' <<
                            "[C] foo.foo_2.baz = " << baz << '\n' ;
            }
        }
    } else {
        std::cout << "[C] Error reading script\n";
        luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }

    lua_close(L);

    std::cout << '\n';
}