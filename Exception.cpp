// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author:

#include "Exception.h"
#include "CurrentThread.h"

namespace Base
{

Exception::Exception(string msg)
  : message_(std::move(msg)),
    stack_(CurrentThread::stackTrace(/*demangle=*/false))
{
}

}  // namespace Base
