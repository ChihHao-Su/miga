set(SRC_ROOT ../../)
set(MIGA_CORE_ROOT ../../../miga_core)

#INCLUDE_DIRECTORIES(
#    ${MIGA_CORE_ROOT}
#)
set(SRC
    ${SRC_ROOT}/main.cxx
    ${SRC_ROOT}/refTest.cxx
    
)

add_subdirectory(miga_core)