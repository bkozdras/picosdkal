/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <testutil/SourceLocationPrinter.hpp>

#include <sstream>

namespace testutil
{
namespace source_location
{

std::string toString(const std::source_location& location)
{
    std::ostringstream stream;
    stream << "File: " << location.file_name()
        << ", Line: " << location.line()
        << ", Column: " << location.column()
        << ", Function: " << location.function_name();
    return stream.str();
}

}  // namespace source_location
}  // namespace picosdkmock
