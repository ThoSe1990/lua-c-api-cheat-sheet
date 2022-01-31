

int multiply_2_numbers(lua_State* L) 
{
    lua_Number arg_2 = lua_tonumber(L, -1); 
    lua_Number arg_1 = lua_tonumber(L, -2); 

    std::cout << "[C] executing multiply_2_numbers with two arguments: " << arg_1 << " and " << arg_2 << '\n';

    lua_Number result = arg_2 * arg_1;  

    lua_pushnumber(L, result);

    return 1;
}

void example_6_calling_c_function_from_lua() 
{
    std::cout << "--- example_6_calling_c_function_from_lua ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    lua_pushcfunction(L, multiply_2_numbers);
    lua_setglobal(L, "multiply_2_numbers");
    
    if (luaL_dofile(L, "./scripts/example_6_calling_c_function_from_lua.lua") == LUA_OK)
        std::cout << "[C] Executed example_6_calling_c_function_from_lua.lua\n";
    else 
        std::cout << "[C] Error reading script\n";

    lua_close(L);

    std::cout << '\n';

}