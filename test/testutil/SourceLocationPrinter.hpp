/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef TESTUTIL_SOURCELOCATIONPRINTER_HPP_
#define TESTUTIL_SOURCELOCATIONPRINTER_HPP_

#include <string>
#include <experimental/source_location>

namespace std
{

using source_location = experimental::source_location;

}  // namespace std

namespace testutil
{
namespace source_location
{

std::string toString(const std::source_location& location = std::source_location::current());

}  // namespace source_location
}  // namespace picosdkmock

#endif  // TESTUTIL_SOURCELOCATIONPRINTER_HPP_
