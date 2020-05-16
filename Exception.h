// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author:

#ifndef BASE_EXCEPTION_H
#define BASE_EXCEPTION_H

#include "Types.h"
#include <exception>

namespace Base
{

class Exception : public std::exception
{
 public:
  Exception(string what);
  ~Exception() noexcept override = default;

  // default copy-ctor and operator= are okay.

  const char* what() const noexcept override
  {
    return message_.c_str();
  }

  const char* stackTrace() const noexcept
  {
    return stack_.c_str();
  }

 private:
  string message_;
  string stack_;
};

}  // namespace Base

#endif  // BASE_EXCEPTION_H
