#!/bin/bash

sed -n -e '/learnopengl\//{=; p; s/learnopengl\///g; p}' -e '/FileSystem::getPath(\(.*\)).c_str()/{=; p; s/FileSystem::getPath("\(.*\)").c_str()/"..\/\1"/g; p}' -e '/"\(.*.vs\)"\(.*\)"\(.*.fs\)"/{=; p; s/"\(.*.vs\)"\(.*\)"\(.*.fs\)"/".\/src\/shaders\/\1"\2".\/src\/shaders\/\3"/; p}' "$@"

sed -i -e '/#include <GLFW\/glfw3.h>/a\#define STB_IMAGE_IMPLEMENTATION' -e '/learnopengl\/shader/s/learnopengl\///g' -e '/FileSystem::getPath(\(.*\)).c_str()/s/FileSystem::getPath("\(.*\)").c_str()/"..\/\1"/g' -e 's/"\(.*.vs\)"\(.*\)"\(.*.fs\)"/".\/src\/shaders\/\1"\2".\/src\/shaders\/\3"/' "$@"

