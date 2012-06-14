set(UNITY_SRC ../plugins/unityshell/src)

find_package (PkgConfig)

set (CFLAGS
     ${CACHED_UNITY_DEPS_CFLAGS}
     ${CACHED_UNITY_DEPS_CFLAGS_OTHER}
     ${MAINTAINER_CFLAGS}
     "-DGETTEXT_PACKAGE=\"unity\""
     "-I${CMAKE_CURRENT_BINARY_DIR}"
     )

if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
  set (CFLAGS ${CFLAGS} "-fPIC")
endif (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")

add_definitions (${CFLAGS})

set (LIBS ${CACHED_UNITY_DEPS_LIBRARIES} "-lunity-core-${UNITY_API_VERSION} -lm -lGL -lGLU")
link_libraries (${LIBS})

set (LIB_PATHS ${CACHED_UNITY_DEPS_LIBRARY_DIRS})
link_directories (${CMAKE_BINARY_DIR}/UnityCore ${LIB_PATHS})

include_directories (. .. ../services ../UnityCore ${UNITY_SRC} ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

#
# Headers & Sources
#
set (SHORTCUTS_SOURCES
     AbstractShortcutHint.h
     MockShortcutHint.h
     ShortcutController.cpp
     ShortcutController.h
     ShortcutHint.cpp
     ShortcutHintPrivate.cpp
     ShortcutModel.cpp
     ShortcutModel.h
     ShortcutView.cpp
     ShortcutView.h
     )

add_library (shortcuts-lib STATIC ${SHORTCUTS_SOURCES})
add_dependencies (shortcuts-lib unity-core-${UNITY_API_VERSION} unity-shared)

# 
# Standalone variant
#
add_executable (shortcuts StandaloneShortcuts.cpp)
add_dependencies (shortcuts shortcuts-lib)
target_link_libraries (shortcuts shortcuts-lib unity-shared)