# ACLIB Common C++ sources

Follow the [Documentation](https://github.com/ACLIB/Documentation) for more details.

## Python Module Example

```c++
#include "python/PyModule.hpp"

using namespace ACLIB;

// Module function
static PyObject* test(PyObject* self, PyObject* args)
{
    return Py_None;
}

// Custom type
class CustomType : public PyClassType
{
public:
    explicit CustomType(const char* name)
        : PyClassType(name)
    {}

    int number;
};

static PyObject* getNumber(CustomType* self, PyObject* args)
{
    return PyLong_FromLong(self->number);
}

// Proxy type
struct ProxyStruct
{
    float ratio;
};

static PyObject* getRatio(PyProxyClassType<ProxyStruct>* self, PyObject* args)
{
    return PyFloat_FromDouble(self->proxy()->ratio);
}

PyMODINIT_FUNC PyInit_module_name()
{
    static auto module = PyModule("module_name");
    module.addMethod("test", test);
    module.init();

    static auto custom_type = PyClassType("Custom");
    custom_type.addGetSet("number", (getter)getNumber, nullptr);
    custom_type.init(module.getModule());

    static auto proxy_type = PyProxyClassType<ProxyStruct>("Proxy");
    proxy_type.addGetSet("ratio", (getter)getRatio, nullptr);
    proxy_type.init(module.getModule());

    return module.getModule();
}
```

## Build

```python
from distutils.core import setup, Extension

extension = Extension(
    name='module_name',
    sources=['source/main.cpp'],
    include_dirs=['include/'],
    extra_compile_args=['/Ot'])


setup(name='module_name',
      version='1.0',
      ext_modules=[extension])

 ```

## Usage

```python
import module_name as module

print(module.test())

custom = module.Custom()
print(custom.number)

proxy = module.Proxy()
print(proxy.ratio)

```
