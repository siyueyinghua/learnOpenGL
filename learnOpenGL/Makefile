# make path, dir item separate by ":"
vpath %.c ./src:../thirdParty/src
vpath %.cpp ./src:../thirdParty/src
vpath %.h ./inc:../thirdParty/inc

# compile and link parameter 
CC := gcc 
CXX := g++ 
CFLAGS := 
CXXFLAGS:= 
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
#define TGT_ALL
#endef
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


# link 
$(TARGET).out: $(TARGET).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

.PHONY: all
all: $(TGT_ALL)
	@echo "$^"

%.out: %.o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)

#compile 
%.o: %.cpp
	$(CXX) -o $@ -c $<  $(CFLAGS) $(INC)

%.o: %.c
	$(CXX) -o $@ -c $<  $(CFLAGS) $(INC)

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \
	sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

# clean
.PHONY: clean
clean: 
	rm -rf *.o *.out $(TARGET).out


##
# initial full make cmd
#hello_window_clear.o: hello_window_clear.cpp glad.c
#	g++ -o  hello_window_clear.out hello_window_clear.cpp ../thirdParty/src/glad.c -I ../thirdParty/inc -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor
#	./hello_window_clear.out
#
