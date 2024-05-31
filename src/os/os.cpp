#include "os.hpp"

#define _WIN32_WINNT 0x0501
#include <windows.h>

#include <stdio.h>
#include <string.h>

namespace tcpk
{
  std::map<std::string, int> os_arch_mapping = {
    { "x86_64", x86_64 },
    { "x86", x86 },
    { "arm64", ARM_64 },
    { "ia32", IA_32 },
    { "ia64", IA_64 }
  };

  std::map<std::string, int> os_type_mapping = {
    { "linux", LINUX },
    { "macos", MACOS },
    { "windows", WINDOWS }
  };

  std::string GetOSArch()
  {
    SYSTEM_INFO info;
    GetNativeSystemInfo(&info);

    switch (info.wProcessorArchitecture)
    {
      case PROCESSOR_ARCHITECTURE_ARM:
        return "arm64";
      case PROCESSOR_ARCHITECTURE_AMD64:
        return "x86_64";
      case PROCESSOR_ARCHITECTURE_INTEL:
        return "x86";
      case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64:
        return "ia64";
      case PROCESSOR_ARCHITECTURE_IA64:
        return "ia64";
    };

    return "";
  }

  std::string GetOSType()
  {
    #ifdef _WIN32
      return "windows";
    #endif

    #ifdef __APPLE__
      return "macos";
    #endif

    #ifdef __linux__
      return "linux";
    #endif

    return "";
  }
}