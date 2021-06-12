#ifndef COMMON_PYMODULE_HPP
#define COMMON_PYMODULE_HPP

#include "PyClassType.hpp"
#include "PyProxyClassType.hpp"

namespace ACLIB
{
    class PyModule
    {
    private:
        const char*              m_module_name;
        PyObject*                m_module;
        PyModuleDef              m_module_def;
        std::vector<PyMethodDef> m_methods;

    public:
        explicit PyModule(const char* name)
            : m_module_name(name)
            , m_module(nullptr)
            , m_module_def()
            , m_methods()
        {
        }

        PyObject* init()
        {
            PyMethodDef sentinel = {nullptr};
            m_methods.push_back(sentinel);

            PyModuleDef_Base base  = PyModuleDef_HEAD_INIT;
            m_module_def.m_base    = base;
            m_module_def.m_name    = m_module_name;
            m_module_def.m_size    = -1;
            m_module_def.m_methods = m_methods.data();

            m_module = PyModule_Create(&m_module_def);
            if(m_module == nullptr)
            {
                INFO("Module was not initialized successfully.\n");
            }
            return m_module;
        }

        PyObject* getModule()
        {
            return m_module;
        }

        void addMethod(
            const char*  name,
            PyCFunction  method,
            std::int16_t args      = METH_VARARGS,
            const char*  docstring = "")
        {
            PyMethodDef method_def = {name, method, args, docstring};
            m_methods.push_back(method_def);
        }
    };

}  // namespace ACLIB

#endif  // COMMON_PYMODULE_HPP
