/*
 * Python module export
 * copyright: Kogia-sima 2018
 */

#include <StringFilter/StringFilter.hpp>
#include <pybind11/pybind11.h>

namespace py = pybind11;


PYBIND11_MODULE(StringFilter, m) {
  m.doc() = R"pbdoc(
    StringFilter plugin for python
  )pbdoc";

  py::class_<StringFilter>(m, "StringFilter")
    .def(py::init<const char*>())
    .def("is_valid", &StringFilter::is_valid);
}
