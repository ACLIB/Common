#ifndef ACLIBSHAREDMEMORY_THREAD_HPP
#define ACLIBSHAREDMEMORY_THREAD_HPP

#include <windows.h>

namespace ACLIB
{
    class Thread
    {
    private:
        DWORD  m_thread_id;
        HANDLE m_thread_handle;

    protected:
        bool   m_running;
        DWORD  m_timeout_ms;

    public:
        Thread();
        ~Thread();

        bool start();
        void join();
        virtual void run();
        bool stop();
    };

    DWORD WINAPI startThread(LPVOID p);
}  // namespace ACLIB

#endif  // ACLIBSHAREDMEMORY_THREAD_HPP
