/*
 * LSST Data Management System
 * Copyright 2008-2017  AURA/LSST.
 *
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the LSST License Statement and
 * the GNU General Public License along with this program.  If not,
 * see <https://www.lsstcorp.org/LegalNotices/>.
 */
#include "pybind11/pybind11.h"

#include "lsst/meas/mosaic/matches.h"

namespace py = pybind11;
using namespace pybind11::literals;

namespace lsst {
namespace meas {
namespace mosaic {
namespace {

template <typename CatT>
void declareCopyCatalog(py::module& mod) {
    mod.def("copyCatalog", copyCatalog<CatT>, "catalog"_a, "target"_a, "targetPrefix"_a = "",
            "sourcePrefix"_a = "");
}

}  // <anonymous>

PYBIND11_MODULE(matches, mod) {
    mod.def("copySchema", copySchema, "schema"_a, "target"_a, "targetPrefix"_a = "", "sourcePrefix"_a = "");
    mod.def("matchesFromCatalog", matchesFromCatalog, "catalog"_a);
}

}  // mosaic
}  // meas
}  // lsst
