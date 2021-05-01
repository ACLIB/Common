#include "Thread.hpp"

#include <AC.hpp>

namespace ACLIB
{
    Thread::Thread()
        : m_thread_id(0)
        , m_thread_handle(nullptr)
        , m_running(true)
        , m_timeout_ms(1)
    {
    }

    Thread::~Thread()
    {
        join();
        if(m_thread_handle)
        {
            CloseHandle(m_thread_handle);
        }
    }

    bool Thread::start()
    {
        m_thread_handle = CreateThread(nullptr, 0, &startThread, this, 0, &m_thread_id);

        if(m_thread_handle == nullptr)
        {
            // err
            //printf("Could not create thread\n");
            return false;
        }
        LOG("start");
        return true;
    }

    void Thread::join()
    {
        LOG("join");
        m_running = false;
        WaitForSingleObject(m_thread_handle, INFINITE);
    }

    void Thread::run()
    {
        LOG("run");
        while(m_running)
        {
            Sleep(m_timeout_ms);
        }
    }

    bool Thread::stop()
    {
        LOG("stop");
        m_running = false;
        return false;
    }

    DWORD startThread(LPVOID p)
    {
        if(p == nullptr)
        {
            //printf("Thread parameter is nullptr.\n");
            return -1;
        }
        reinterpret_cast<Thread*>(p)->run();
        return 0;
    }
}  // namespace ACLIB
