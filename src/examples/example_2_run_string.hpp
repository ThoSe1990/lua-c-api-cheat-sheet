



void example_2_run_string() 
{
    std::cout << "--- example_2_run_string ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    const char* s = "print(\"[Lua] Hello from this string\")";

    if (luaL_dostring(L, s) == LUA_OK) {
        std::cout << "[C] Executed string s\n";
    } else {
        std::cout << "[C] Error reading script\n";
        luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }

    lua_close(L);
    
    std::cout << '\n';

}