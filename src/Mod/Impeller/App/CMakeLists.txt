
include_directories(
    ${Boost_INCLUDE_DIRS}
    ${OCC_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${XercesC_INCLUDE_DIRS}
)

set(Impeller_LIBS
    FreeCADApp
)

SET(Impeller_SRCS
    AppImpeller.cpp
    PreCompiled.cpp
    PreCompiled.h
)

add_library(Impeller SHARED ${Impeller_SRCS})
target_link_libraries(Impeller ${Impeller_LIBS})


SET_BIN_DIR(Impeller Impeller /Mod/Impeller)
SET_PYTHON_PREFIX_SUFFIX(Impeller)

install(TARGETS Impeller DESTINATION ${CMAKE_INSTALL_LIBDIR})
