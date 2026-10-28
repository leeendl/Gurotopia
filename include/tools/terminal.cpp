#include "terminal.hpp"

#include <string_view>

void print(std::string_view str, FILE *file)
{
    fwrite(str.data(), sizeof(char), str.length(), file);
    
    fwrite("\n", sizeof(char), sizeof('\n'), file);
}
