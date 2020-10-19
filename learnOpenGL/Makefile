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
TARGET1 := basic_lighting_diffuse
TGT_ALL += $(TARGET1).out
TARGET2 := basic_lighting_exercise1
TGT_ALL += $(TARGET2).out
TARGET3 := basic_lighting_exercise2
TGT_ALL += $(TARGET3).out
TARGET4 := basic_lighting_specular
TGT_ALL += $(TARGET4).out
TARGET5 := camera_circle
TGT_ALL += $(TARGET5).out
TARGET6 := camera_class
TGT_ALL += $(TARGET6).out
TARGET7 := camera_keyboard_dt
TGT_ALL += $(TARGET7).out
TARGET8 := camera_mouse_zoom
TGT_ALL += $(TARGET8).out
TARGET9 := colors
TGT_ALL += $(TARGET9).out
TARGET10 := coordinate_systems
TGT_ALL += $(TARGET10).out
TARGET11 := coordinate_systems_depth
TGT_ALL += $(TARGET11).out
TARGET12 := coordinate_systems_multiple
TGT_ALL += $(TARGET12).out
TARGET13 := hello_triangle
TGT_ALL += $(TARGET13).out
TARGET14 := hello_window_clear
TGT_ALL += $(TARGET14).out
TARGET15 := light_casters_directional
TGT_ALL += $(TARGET15).out
TARGET16 := light_casters_point
TGT_ALL += $(TARGET16).out
TARGET17 := light_casters_spot
TGT_ALL += $(TARGET17).out
TARGET18 := light_casters_spot_soft
TGT_ALL += $(TARGET18).out
TARGET19 := lighting_maps_diffuse
TGT_ALL += $(TARGET19).out
TARGET20 := lighting_maps_specular
TGT_ALL += $(TARGET20).out
TARGET21 := materials
TGT_ALL += $(TARGET21).out
TARGET22 := model_loading
TGT_ALL += $(TARGET22).out
TARGET23 := model_loading_fox
TGT_ALL += $(TARGET23).out
TARGET24 := model_loading_light
TGT_ALL += $(TARGET24).out
TARGET25 := model_loading_multi_light
TGT_ALL += $(TARGET25).out
TARGET26 := model_loading_multi_light_normal_ChryslerImperial
TGT_ALL += $(TARGET26).out
TARGET27 := model_loading_multi_light_normal
TGT_ALL += $(TARGET27).out
TARGET28 := multiple_lights
TGT_ALL += $(TARGET28).out
TARGET29 := multiple_lights_exercise1
TGT_ALL += $(TARGET29).out
TARGET30 := shaders_class
TGT_ALL += $(TARGET30).out
TARGET31 := shaders_interpolation
TGT_ALL += $(TARGET31).out
TARGET32 := shaders_uniform
TGT_ALL += $(TARGET32).out
TARGET33 := textures_combined
TGT_ALL += $(TARGET33).out
TARGET34 := textures
TGT_ALL += $(TARGET34).out
TARGET35 := transformations
TGT_ALL += $(TARGET35).out

# link
$(TARGET1).out: $(TARGET1).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET2).out: $(TARGET2).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET3).out: $(TARGET3).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET4).out: $(TARGET4).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET5).out: $(TARGET5).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET6).out: $(TARGET6).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET7).out: $(TARGET7).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET8).out: $(TARGET8).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET9).out: $(TARGET9).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET10).out: $(TARGET10).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET11).out: $(TARGET11).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET12).out: $(TARGET12).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET13).out: $(TARGET13).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET14).out: $(TARGET14).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET15).out: $(TARGET15).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET16).out: $(TARGET16).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET17).out: $(TARGET17).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET18).out: $(TARGET18).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET19).out: $(TARGET19).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET20).out: $(TARGET20).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET21).out: $(TARGET21).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET22).out: $(TARGET22).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET23).out: $(TARGET23).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET24).out: $(TARGET24).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET25).out: $(TARGET25).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET26).out: $(TARGET26).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET27).out: $(TARGET27).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET28).out: $(TARGET28).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET29).out: $(TARGET29).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET30).out: $(TARGET30).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET31).out: $(TARGET31).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET32).out: $(TARGET32).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET33).out: $(TARGET33).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET34).out: $(TARGET34).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

$(TARGET35).out: $(TARGET35).o glad.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)
	./$@

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
