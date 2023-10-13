#include <cstdio>
#include <fstream>
#include <filesystem>

int main() {

    std::filesystem::create_directories("./tester");

    std::ofstream test;
    test.open("./tester/test.dat");

    test << "Hi, lets see if this works" << std::endl;

    return 0;
}