#ifndef KDR_FILE_HPP
#define KDR_FILE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

namespace kdr
{
  namespace File
  {
    /**
    * Retrieves the contents of a file as a string.
    *
    * @param path The path to the file.
    * @return A string containing the contents of the file. If an error occurs, an empty string is returned.
    */
    const std::string getContents(const char* path);
  }
}

#endif // KDR_FILE_HPP
