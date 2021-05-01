#include "Mutex.hpp"

namespace ACLIB
{
    Mutex::Mutex()
    {
        m_mutex_handle = CreateMutex(nullptr, FALSE, nullptr);
        if(m_mutex_handle == nullptr)
        {
            // err
            //printf("Could not create mutex\n");
        }
    }

    Mutex::~Mutex()
    {
        if(m_mutex_handle)
        {
            CloseHandle(m_mutex_handle);
        }
    }

    DWORD Mutex::acquire()
    {
        return WaitForSingleObject(m_mutex_handle, INFINITE);
    }

    DWORD Mutex::release()
    {
        return ReleaseMutex(m_mutex_handle);
    }
}
