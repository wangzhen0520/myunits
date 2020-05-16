#ifndef BASE_NONCOPYABLE_H
#define BASE_NONCOPYABLE_H

namespace Base
{

class noncopyable
{
 public:
  noncopyable(const noncopyable&) = delete;
  void operator=(const noncopyable&) = delete;

 protected:
  noncopyable() = default;
  ~noncopyable() = default;
};

}  // namespace Base

#endif  // BASE_NONCOPYABLE_H
