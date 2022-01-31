
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include <string>
#include <iostream>

#include "examples/example_1_run_script.hpp"
#include "examples/example_2_run_string.hpp"
#include "examples/example_3_access_lua_variables.hpp"
#include "examples/example_4_passing_variable_to_lua.hpp"
#include "examples/example_5_access_lua_function.hpp"
#include "examples/example_6_calling_c_function_from_lua.hpp"
#include "examples/example_7_access_structs_in_lua.hpp"
#include "examples/example_8_reading_lua_table_in_c.hpp"
#include "examples/example_9_reading_lua_array_in_c.hpp"
#include "examples/example_10_reading_lua_tablearray_in_c.hpp"
#include "examples/example_11_reading_lua_tablearray_alternative.hpp"

int main()  
{  
    example_1_run_script();
    example_2_run_string();
    example_3_access_lua_variables();
    example_4_passing_variable_to_lua();
    example_5_access_lua_function();
    example_6_calling_c_function_from_lua();
    example_7_access_structs_in_lua();
    example_8_reading_lua_table_in_c();
    example_9_reading_lua_array_in_c();
    example_10_reading_lua_tablearray_in_c();
    example_11_reading_lua_tablearray_alternative();
    
    return 0;
}