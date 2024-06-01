#include "tcpk.hpp"
#include "os/os.hpp"

#include <iostream>

namespace tcpk
{
  int tcpk_main()
  {
    std::cout << "System Config: " << tcpk::GetOSType() << " " << tcpk::GetOSArch() << std::endl;

    return 0;
  }
}