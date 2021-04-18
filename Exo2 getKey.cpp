#include <stdio.h>
#include <pybind11/pybind11.h>
#include <iostream>
#include <string>

using namespace std;

char version[]="1.0";

char const* getVersion() {
    return version;
}
class Key
{
public:
    string privateKey;
    string publicKey;
    void initialize(const std::string &key) { privateKey = key; }

    string getPrivateKey()
    {
        return privateKey;
    }
    string getPublicKey()
    {
        return publicKey;
    }
};

namespace py = pybind11;

PYBIND11_MODULE(key_component,greetings)
{
greetings.doc() = "greeting_object 1.0";

greetings.def("getVersion", &getVersion, "a function returning the version");

py::class_<Key>(greetings, "Key")

.def(py::init())
.def("initialize", &Key::initialize)
.def("getPrivateKey", &Key::getPrivateKey)
.def("getPublicKey", &Key::getPublicKey);

}