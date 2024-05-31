#pragma once

#include <string>
#include <map>

namespace tcpk
{
  enum OS_ARCH
  {
    x86_64 = 0,
    x86 = 1,
    ARM_64 = 2,
    IA_32 = 4,
    IA_64 = 5
  };

  enum OS_TYPE
  {
    LINUX = 0,
    MACOS = 1,
    WINDOWS = 2
  };

  extern std::map<std::string, int> os_arch_mapping;
  extern std::map<std::string, int> or_type_mapping;

  std::string GetOSArch();
  std::string GetOSType();
}