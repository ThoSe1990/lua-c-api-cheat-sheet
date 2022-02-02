# LUA C API Cheat Sheet

If you're writing own Lua bindings, this can be helpful. A Lua C API cheat sheet with 11 examples. You can find my Blog article about those examples [here](https://www.codingwiththomas.com/blog/a-lua-c-api-cheat-sheet)

1. Running a Lua script from file
2. Running a Lua script from string
3. Access to variables
4. Passing variables to Lua
5. Access a Lua function
6. Calling a C function from Lua
7. Access structs in Lua (creating userdata)
8. Reading a Lua table in C
9. Reading a Lua array in C
10. Reading a Lua table array in C 
11. Reading a Lua table array in C (alternative)

  
Run cmake to build the examples (target `lua-examples`) or the Lua interpreter itsself (target `lua`)
````
cmake -S . -B ./build
cmake --build ./build
````

**And make sure you stay in the project directory when executing, I just used relative paths to the scripts**
````
./build/bin/lua-examples

--- example_1_run_script ---
[Lua] Hello Lua
[C] Executed example_1_run_script.lua

--- example_2_run_string ---
[Lua] Hello from this string
[C] Executed string s

--- example_3_access_lua_variables ---
[Lua] foo = 99
[C] Received lua's foo with value 99

--- example_4_passing_variable_to_lua ---
[C] Declared foo = 199
[Lua] Can access foo Lua = 199.0
[C] Executed example_4_passing_variable_to_lua.lua

--- example_5_access_lua_function ---
[Lua] I got 2 numbers to add: 55.0 + 17.0 = 72.0
[C] The result from Lua is: 72

--- example_6_calling_c_function_from_lua ---
[C] executing multiply_2_numbers with two arguments: 3 and 4
[Lua] Called multiply_2_numbers(..) and the result is: 12.0
[C] Executed example_6_calling_c_function_from_lua.lua

--- example_7_access_structs_in_lua ---
[C] Created Foo with x = 0 and y = 0
[Lua] Created userdata Foo
[C] Executed example_7_access_structs_in_lua.lua

--- example_8_reading_lua_table_in_c ---
[C] Executed example_8_reading_lua_table_in_c.lua
[C] Got table foo from lua with:
foo_number = 1
bar_number = 2
foo_string = foo
bar_string = bar

--- example_9_reading_lua_array_in_c ---
[Lua] foo[1] = 11
[Lua] foo[2] = 22
[Lua] foo[3] = 33
[C] Executed example_9_reading_lua_array_in_c.lua
[C] Got table foo from lua with:
[C] foo[1] = 11
[C] foo[2] = 22
[C] foo[3] = 33

--- example_10_reading_lua_tablearray_in_c ---
[C] Executed example_10_reading_lua_tablearray_in_c.lua
[C] foo[1].bar = 123
[C] foo[1].baz = baz
[C] foo[2].bar = 456
[C] foo[2].baz = another baz

--- example_11_reading_lua_tablearray_alternative ---
[C] Executed example_11_reading_lua_tablearray_alternative.lua
[C] foo.foo_1.bar = 123
[C] foo.foo_1.baz = baz
[C] foo.foo_2.bar = 456
[C] foo.foo_2.baz = another baz
````
