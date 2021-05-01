#ifndef ACLIBSHAREDMEMORY_LOCKGUARD_HPP
#define ACLIBSHAREDMEMORY_LOCKGUARD_HPP

#include "Mutex.hpp"

namespace ACLIB
{
    class LockGuard
    {
    private:
        Mutex& m_mutex;

    public:
        explicit LockGuard(Mutex& mutex);
        ~LockGuard();
    };
}  // namespace ACLIB

#endif  // ACLIBSHAREDMEMORY_LOCKGUARD_HPP
