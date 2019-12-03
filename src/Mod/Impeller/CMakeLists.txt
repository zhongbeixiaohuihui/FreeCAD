
add_subdirectory(App)
if(BUILD_GUI)
    add_subdirectory(Gui)
endif(BUILD_GUI)

set(Impeller_Scripts
    Init.py
)

if(BUILD_GUI)
    list (APPEND Impeller_Scripts InitGui.py)
endif(BUILD_GUI)

add_custom_target(ImpellerScripts ALL
    SOURCES ${Impeller_Scripts}
)

fc_target_copy_resource_flat(ImpellerScripts
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/Mod/Impeller
    ${Impeller_Scripts}
)

install(
    FILES
        ${Impeller_Scripts}
    DESTINATION
        Mod/Impeller
)
