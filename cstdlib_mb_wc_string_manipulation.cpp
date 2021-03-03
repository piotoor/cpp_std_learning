#include <iostream>
#include <cstdlib>
#include <string>
#include <bitset>
#include <iomanip>

void dumpMultiByteString(std::string str) {
    std::wcout << "---------------------------- UTF-8 sequence ----------------------------" << std::endl;
    std::wcout << std::hex;
    unsigned char uc;
    for (const auto &c: str) {
      std::wcout << std::setw(8) << (unsigned char)c << "|";
    }
    std::wcout << std::endl;
    for (const auto &c: str) {
      std::wcout << (std::bitset<8>(c)) << "|";
    }
    std::wcout << std::endl;
}

void dumpWideCharString(std::wstring wstr) {
  std::wcout << "-------------------------- UTF-16 sequence -------------------------" << std::endl;
  std::wcout << std::hex;
  for (const auto &c: wstr) {
    std::wcout << std::setw(16) << c << "|";
  }
  std::wcout << std::endl;

  for (const auto &c: wstr) {
    std::wcout << std::setw(16) << (unsigned char)c << "|";
  }
  std::wcout << std::endl;

  for (const auto &c: wstr) {
    std::wcout << std::bitset<16>(c) << "|";
  }
  std::wcout << std::endl;
}

int main() {
    std::setlocale(LC_ALL, "de_DE.UTF-8");
    std::wcout.imbue(std::locale("de_DE.UTF-8"));
    std::string mbs= "\u00C4\u00E4\u00D6\u00F6";

    wchar_t buff[9];
    std::mbstowcs(buff, mbs.c_str(), 9);
    dumpMultiByteString(mbs);
    std::wcout << std::endl;
    dumpWideCharString(std::wstring(buff));
    return 0;
}
