#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
   std::ofsream file("log.txt");
   print(std::string("hello"), file);
}
