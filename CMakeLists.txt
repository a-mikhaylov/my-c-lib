cmake_minimum_required(VERSION 3.15)

set(mycpplibtest_VERSION 1.0.0)

project(mycpplibtest 
	VERSION ${mycpplibtest_VERSION}
	LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(mycpplibtest shapes.cpp shapes.h)
add_library(mycpplibtest::mycpplibtest ALIAS mycpplibtest)

if(BUILD_SHARED_LIBS AND WIN32)
	target_compile_definitions(mycpplibtest
		PRIVATE "MY_EXPORT=__declspec(dllexport)"
		INTERFACE "MY_EXPORT=__declspec(dllimport)")
endif()

target_compile_features(mycpplibtest PUBLIC cxx_std_17)
target_include_directories(mycpplibtest
	PUBLIC
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

configure_package_config_file(cmake/config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/mycpplibtest-config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/mycpplibtest
	NO_SET_AND_CHECK_MACRO)
write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/mycpplibtest-config-version.cmake
	VERSION ${mycpplibtest_VERSION}
	COMPATIBILITY SameMajorVersion)
install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/mycpplibtest-config.cmake
		${CMAKE_CURRENT_BINARY_DIR}/mycpplibtest-config-version.cmake
	DESTINATION
		${CMAKE_INSTALL_DATADIR}/mycpplibtest)

install(TARGETS mycpplibtest EXPORT mycpplibtest-targets ) 
install(FILES shapes.h       DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} )
install(EXPORT mycpplibtest-targets
	NAMESPACE mycpplibtest::
	DESTINATION ${CMAKE_INSTALL_DATADIR}/mycpplibtest)
