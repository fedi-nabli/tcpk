#include "os.hpp"

#ifdef _WIN32
#define _WIN32_WINNT 0x0501
#include <windows.h>
#else
#include <sys/utsname.h>
#endif

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
  #if defined(_WIN32)
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
#endif

#if defined(__APPLE__) || defined(__linux__)
  long ret = -1;
  struct utsname un;

  if (ret == -1)
    ret = uname(&un);
  if (ret != -1)
  {
    if (strlen(un.machine) == 4 && un.machine[0] == 'i' && un.machine[2] == '8' && un.machine[3] == '6')
      return std::string("x86");
    if (strcmp(un.machine, "amd64") == 0)
      return std::string("x86_64");

    return std::string(un.machine);
  }
#endif

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