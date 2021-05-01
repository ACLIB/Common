#include "LockGuard.hpp"

namespace ACLIB
{
    LockGuard::LockGuard(Mutex& mutex)
        : m_mutex(mutex)
    {
        m_mutex.acquire();
    }

    LockGuard::~LockGuard()
    {
        m_mutex.release();
    }
}
