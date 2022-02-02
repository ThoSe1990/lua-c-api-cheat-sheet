

struct Foo
{
    int m_x;
    int m_y;
};


int create_foo(lua_State* L) 
{
    Foo* foo = static_cast<Foo*>(lua_newuserdata(L, sizeof(Foo)));
    foo->m_x = 0;
    foo->m_y = 0;

    std::cout << "[C] Created Foo with x = " << foo->m_x << " and y = " << foo->m_y << '\n';
    return 1;
}


void example_7_access_structs_in_lua() 
{
    std::cout << "--- example_7_access_structs_in_lua ---\n";

    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    lua_pushcfunction(L, create_foo);
    lua_setglobal(L, "create_foo");

    if (luaL_dofile(L, "./scripts/example_7_access_structs_in_lua.lua") == LUA_OK) {
        std::cout << "[C] Executed example_7_access_structs_in_lua.lua\n";
    } else {
        std::cout << "[C] Error reading script\n";
        luaL_error(L, "Error: %s\n", lua_tostring(L, -1));
    }

    lua_close(L);

    std::cout << '\n';
}