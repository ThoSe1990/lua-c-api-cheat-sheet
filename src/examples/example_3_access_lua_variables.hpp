

void example_3_access_lua_variables() 
{
    std::cout << "--- example_3_access_lua_variables ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, "./scripts/example_3_access_lua_variables.lua") == LUA_OK) {
        lua_getglobal(L, "foo"); // get foo on the stack
        lua_Number foo_in_c = lua_tonumber(L, -1); // foo is on top of the stack, use -1
        std::cout << "[C] Received lua's foo with value " << foo_in_c << '\n';
    } else {
        std::cout << "[C] Error reading script\n";
        luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }

    lua_close(L);

    std::cout << '\n';

}