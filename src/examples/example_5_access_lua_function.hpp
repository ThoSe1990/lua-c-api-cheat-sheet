

void example_5_access_lua_function() 
{
    std::cout << "--- example_5_access_lua_function ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, "./scripts/example_5_access_lua_function.lua") == LUA_OK) {
        lua_getglobal(L, "add_2_numbers");
        if (lua_isfunction(L, -1)) { 
            lua_pushnumber(L, 55); // first function arg: one 
            lua_pushnumber(L, 17); // second function arg: two

            const int arguments_count = 2 ; // we have 2 arguments, which we just pushed to the lua stack
            const int returnvalues_count = 1; // function returns 0 values
            
            lua_pcall(L, arguments_count, returnvalues_count, 0);
            lua_Number result = lua_tonumber(L, -1);

            std::cout << "[C] The result from Lua is: " << static_cast<int>(result) << '\n';
        } else { 
            std::cout << "[C] Error: didn't find a function on top of Lua stack\n";
        }
    } else {
        std::cout << "[C] Error reading script\n";
        luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }

    lua_close(L);
    std::cout << '\n';

}