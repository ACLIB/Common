#ifndef COMMON_PYPROXYCLASSTYPE_HPP
#define COMMON_PYPROXYCLASSTYPE_HPP

#include "PyCustom.hpp"

#include <cstdint>
#include <Python.h>
#include <structmember.h>
#include <vector>

namespace ACLIB
{
    template<typename T>
    class PyProxyClassType : public PyClassType
    {
    private:
        T* m_proxy;

    public:
        static PyObject* _new(PyTypeObject* type, PyObject* args, PyObject* kwds)
        {
            auto self = reinterpret_cast<PyProxyClassType<T>*>(type->tp_alloc(type, 0));
            if(self == nullptr)
            {
                INFO("Could not allocate PyProxyClassType.\n");
                return nullptr;
            }
            self->m_proxy = new T();
            return reinterpret_cast<PyObject*>(self);
        }

        static void _del(PyTypeObject* self)
        {
            delete reinterpret_cast<PyProxyClassType<T>*>(self)->m_proxy;
            self->tp_free(self);
        }

        static int _init(PyProxyClassType<T>* self, PyObject* args, PyObject* kwds)
        {
            return 0;
        }

        explicit PyProxyClassType(const char* name)
            : PyClassType(name)
        {
        }

        T* proxy()
        {
            return m_proxy;
        }

        virtual bool init(PyObject* module)
        {
            // MSVC c99 :/
            PyMethodDef method_sentinel = {nullptr};
            PyMemberDef member_sentinel = {nullptr};
            PyGetSetDef getset_sentinel = {nullptr};
            m_methods.emplace_back(method_sentinel);
            m_members.emplace_back(member_sentinel);
            m_getset.emplace_back(getset_sentinel);

            PyVarObject ob_base = ACLIBPyObject_HEAD_INIT(&PyType_Type);
            m_type.ob_base      = ob_base;
            m_type.tp_name      = m_class_name;
            m_type.tp_basicsize = sizeof(PyProxyClassType<T>);
            m_type.tp_flags     = Py_TPFLAGS_DEFAULT;
            m_type.tp_new       = (newfunc)_new;
            m_type.tp_dealloc   = (destructor)_del;
            m_type.tp_init      = (initproc)_init;
            m_type.tp_methods   = m_methods.data();
            m_type.tp_members   = m_members.data();
            m_type.tp_getset    = m_getset.data();

            if(module == nullptr)
            {
                INFO("Call init() before adding class types.");
                return false;
            }

            bool success = true;

            // Init class
            success &= PyType_Ready(&m_type) >= 0;

            // Add class object
            success &=
                PyModule_AddObject(module, m_type.tp_name, reinterpret_cast<PyObject*>(&m_type)) >= 0;

            return success;
        }
    };

}  // namespace ACLIB

#endif  // COMMON_PYPROXYCLASSTYPE_HPP
