#ifndef COMMON_PYCUSTOM_HPP
#define COMMON_PYCUSTOM_HPP

#include <Python.h>

#pragma warning(disable: 4530)

#define ACLIBPyObject_HEAD_INIT(type) {_PyObject_EXTRA_INIT 1, type}

#define INFO(what) printf(what)

namespace ACLIB
{
    struct ACLIBPyMemberDef
    {
        const char* name;
        int         type;
        Py_ssize_t  offset;
        int         flags;
        const char* doc;
    };

    typedef struct ACLIBPyMemberDef ACLIBPyMemberDef;

    struct ACLIBPyGetSetDef
    {
        const char* name;
        getter      get;
        setter      set;
        const char* doc;
        void*       closure;
    };

    typedef struct ACLIBPyGetSetDef ACLIBPyGetSetDef;
}

#endif  // COMMON_PYCUSTOM_HPP
