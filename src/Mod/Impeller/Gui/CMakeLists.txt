
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
    ${COIN3D_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${XercesC_INCLUDE_DIRS}
)

set(ImpellerGui_LIBS
    Impeller
    FreeCADGui
)

if (BUILD_QT5)
    qt5_add_resources(Impeller_QRC_SRCS Resources/Impeller.qrc)
else()
    qt4_add_resources(Impeller_QRC_SRCS Resources/Impeller.qrc)
endif()

SET(ImpellerGui_SRCS
    ${Impeller_QRC_SRCS}
    AppImpellerGui.cpp
    Command.cpp
    PreCompiled.cpp
    PreCompiled.h
    Workbench.cpp
    Workbench.h
)

add_library(ImpellerGui SHARED ${ImpellerGui_SRCS})
target_link_libraries(ImpellerGui ${ImpellerGui_LIBS})

SET_BIN_DIR(ImpellerGui ImpellerGui /Mod/Impeller)
SET_PYTHON_PREFIX_SUFFIX(ImpellerGui)
    
install(TARGETS ImpellerGui DESTINATION ${CMAKE_INSTALL_LIBDIR})
