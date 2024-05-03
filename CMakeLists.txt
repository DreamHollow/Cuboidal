cmake_minimum_required(VERSION 3.25.1)
project(cuboidal)

find_package(SFML REQUIRED graphics window system audio)
find_package(OpenGL REQUIRED)
find_package(Threads)

add_subdirectory(deps/glm)
add_subdirectory(deps/glad)

set(SFML_STATIC_LIBRARIES TRUE)

add_executable(${PROJECT_NAME} src/Main.cpp
	src/Application.cpp
	src/Camera.cpp
	src/debugger/Debugger.cpp
	src/files/File.cpp
	src/files/ConfigFile.cpp
	src/files/TextureFile.cpp
	#src/graphics/Renderer.cpp
	src/graphics/Shader.cpp
	src/graphics/Face.cpp
	src/graphics/Texture.cpp
	src/graphics/CubeTexture.cpp
	src/entities/Entity.cpp
	src/entities/Player.cpp
	src/entities/Triangle.cpp
	src/world/World.cpp
	src/states/State.cpp
	src/states/GameState.cpp
)

include_directories(include)

function(setup_target TARGET)
	# Enable C++20
	target_compile_features(${TARGET} PUBLIC cxx_std_20)

	# OS flags
	if(MSVC)
		target_compile_options(${TARGET} PRIVATE
			/W4 /WX)
	else()
		target_compile_options(${TARGET} PRIVATE
			-Wall -Wextra -pedantic)
	endif()

	target_include_directories(
		${TARGET}
		PRIVATE
		deps
	)
endfunction(setup_target)

setup_target(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
	glad
	glm
	sfml-graphics
	sfml-window
	sfml-system
	sfml-audio
	OpenGL::GL
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/src/shaders
    ${PROJECT_BINARY_DIR}/shaders
    COMMENT "Copying shaders..")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/src/config
    ${PROJECT_BINARY_DIR}/config
    COMMENT "Copying config files..")

# Auto-generated comment:
# Post-compile data

# Auto-generated comment:
# This list made with CMakeEasy.
