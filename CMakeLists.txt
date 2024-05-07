cmake_minimum_required(VERSION 3.15)

set(mycpplibtest_VERSION 1.0.0)

project(mycpplibtest VERSION ${mycpplibtest_VERSION})

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(mycpplibtest SHARED shapes_lib1.cpp shapes.h)
add_library(mycpplibtest::mycpplibtest ALIAS mycpplibtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


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
install(FILES shapes.h       DESTINATION include )
install(EXPORT mycpplibtest-targets
	NAMESPACE mycpplibtest::
	DESTINATION ${CMAKE_INSTALL_DATADIR}/mycpplibtest)
