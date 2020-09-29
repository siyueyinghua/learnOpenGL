# make path, dir item separate by ":"
vpath %.c ./src:../thirdParty/src
vpath %.cpp ./src:../thirdParty/src
vpath %.h ./inc:../thirdParty/inc

# compile and link parameter 
CC := gcc 
CXX := g++ 
CFLAGS := 
CXXFLAGS:= -std=c++17
#LDFLAGS := -L../lib/libShared.so -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor
LDFLAGS := -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor
#LIBS := ../lib/static.a ../lib/libShared.so
LIBS := ../thirdParty/lib/libglfw3.a
DEFINES := 
INCLUDE := -I./inc -I../thirdParty/inc
INC = -I./inc -I../thirdParty/inc
INCLUDE_DIRS = -I./inc -I../thirdParty/inc
DEPS = glad.h glfw3.h glfw3native.h

# target 
TARGET := hello_window_clear
TGT_ALL := $(TARGET).out
TARGET := hello_triangle
TGT_ALL += $(TARGET).out
TARGET := shaders_uniform
TGT_ALL += $(TARGET).out
TARGET := shaders_interpolation
TGT_ALL += $(TARGET).out
TARGET := shaders_class
TGT_ALL += $(TARGET).out
TARGET := textures
TGT_ALL += $(TARGET).out
TARGET := textures_combined
TGT_ALL += $(TARGET).out
TARGET := transformations
TGT_ALL += $(TARGET).out
TARGET := coordinate_systems
TGT_ALL += $(TARGET).out
TARGET := coordinate_systems_depth
TGT_ALL += $(TARGET).out
TARGET := coordinate_systems_multiple
TGT_ALL += $(TARGET).out
TARGET := camera_circle
TGT_ALL += $(TARGET).out
TARGET := camera_keyboard_dt
TGT_ALL += $(TARGET).out
TARGET := camera_mouse_zoom
TGT_ALL += $(TARGET).out
TARGET := camera_class
TGT_ALL += $(TARGET).out


# link 
$(TARGET).out: $(TARGET).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

.PHONY: all
all: $(TGT_ALL)
	@echo "$^"

%.out: %.o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)

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
