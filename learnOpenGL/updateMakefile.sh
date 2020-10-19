#!/bin/bash

make_file="Makefile"

cat << 'EOF' > "${make_file}"
# make path, dir item separate by ":"
vpath %.c ./src:../thirdParty/src
vpath %.cpp ./src:../thirdParty/src
vpath %.h ./inc:../thirdParty/inc

# compile and link parameter
CC := gcc
CXX := g++
CFLAGS :=
CXXFLAGS:= -std=c++17
LDFLAGS := -lglfw3 -lassimp -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor
#LIBS := ../thirdParty/lib/libglfw3.a ../thirdParty/lib/libassimp.so
LIBS :=
DEFINES :=
INCLUDE := -I./inc -I../thirdParty/inc
INC = -I./inc -I../thirdParty/inc
INCLUDE_DIRS = -I./inc -I../thirdParty/inc
DEPS = glad.h glfw3.h glfw3native.h

# target
EOF

#for tgt in src/*.cpp; do tgt_arr+=("$tgt"); done
#declare -p tgt_arr
#echo "${tgt_arr[@]%%.cpp}"
#declare -p tgt_arr

#echo "TGT_ALL :=" >> "${make_file}"
for tgt in src/*.cpp
do
    let i++
    tgt=${tgt##*/}
    tgt=${tgt%%.cpp}
    TGT_name="TARGET${i}"
    TGT_arr+=("TARGET${i}")
    echo "$TGT_name := ${tgt}" >> "${make_file}"
    echo "TGT_ALL += \$(${TGT_name}).out" >> "${make_file}"
done
#declare -p TGT_arr

echo '' >> "${make_file}"
echo '# link' >> "${make_file}"
for TGT in ${TGT_arr[@]}
do

    cat << EOF >> "${make_file}"
\$(${TGT}).out: \$(${TGT}).o glad.o
	\$(CXX) -o \$@ \$^ \$(LIBS) \$(LDFLAGS)
	./\$@

EOF
done

cat << 'EOF' >> "${make_file}"
.PHONY: all
all: $(TGT_ALL)
	@echo "$^"

%.out: %.o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

# compile
%.o: %.cpp
	$(CXX) -o $@ -c $<  $(CXXFLAGS) $(INC)

%.o: %.c
	$(CXX) -o $@ -c $<  $(CXXFLAGS) $(INC)

# run out
.PHONY: run
run:
	./$(TARGET).out

# clean
.PHONY: clean
clean:
	rm -rf *.o *.out $(TARGET).out


#-- # Automatic-Prerequisites
#-- include $(TARGET:.cpp=.d)
#-- %.d: %.cpp
#-- 	@set -e; rm -f $@; \
#-- 	$(CC) -M $(CXXFLAGS) $< > $@.$$$$; \
#-- 	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
#-- 	rm -f $@.$$$$


##
# initial full make cmd
#hello_window_clear.o: hello_window_clear.cpp glad.c
#	g++ -o  hello_window_clear.out hello_window_clear.cpp ../thirdParty/src/glad.c -I ../thirdParty/inc -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor
#	./hello_window_clear.out
#
EOF
