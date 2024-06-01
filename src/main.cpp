#include <iostream>
#include "os/os.hpp"

int main()
{
  std::cout << "OS Arch: " << tcpk::GetOSArch() << std::endl;
  std::cout << "OS Type: " << tcpk::GetOSType() << std::endl;

  return 0;
}