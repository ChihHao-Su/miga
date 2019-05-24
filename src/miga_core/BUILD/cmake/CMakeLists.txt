cmake_minimum_required(VERSION 3.0)

project(noname_core)

set(SRC_ROOT ../../)
set(THIRDPARTY_ROOT ../../../thirdparty)

INCLUDE_DIRECTORIES(
	${THIRDPARTY_ROOT}
)

set(SRC 
	${SRC_ROOT}/app.cxx
	${SRC_ROOT}/baseObj.cxx
	${SRC_ROOT}/obj.cxx
	${SRC_ROOT}/objMan.cxx
	${SRC_ROOT}/ref.cxx

	${SRC_ROOT}excp/IthrowAble.cxx
	${SRC_ROOT}excp/unImplExcp.cxx
)

add_subdirectory('uhh	`y0miga_core)
add_library(noname_core SHARED ${SRC})
