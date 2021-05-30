#ifndef ACLIBSHAREDMEMORY_MUTEX_HPP
#define ACLIBSHAREDMEMORY_MUTEX_HPP

#include <windows.h>

namespace ACLIB
{
    class Mutex
    {
    private:
        HANDLE m_mutex_handle;

    public:
        Mutex();
        ~Mutex();

        DWORD acquire();
        DWORD release();
    };
}  // namespace ACLIB

#endif  // ACLIBSHAREDMEMORY_MUTEX_HPP
