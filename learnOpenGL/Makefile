# make path, dir item separate by ":"
vpath %.c ./src:../thirdParty/src
vpath %.cpp ./src:../thirdParty/src
vpath %.h ./inc:../thirdParty/inc

# compile and link parameter
#-- CC := gcc
#-- CXX := g++
CC := clang
CXX := clang++

# use pkg-config for getting CFLAGS and LDLIBS
FFMPEG_LIBS=    libavdevice                        \
                libavformat                        \
                libavfilter                        \
                libavcodec                         \
                libswresample                      \
                libswscale                         \
                libavutil                          \

CFLAGS := -std=c11
CXXFLAGS:= -std=c++17
LDFLAGS := -lglfw3 -lassimp -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lXxf86vm -lXinerama -lXcursor
DEFINES :=
INCLUDE := -I./inc -I../thirdParty/inc
INC = -I./inc -I../thirdParty/inc
INCLUDE_DIRS = -I./inc -I../thirdParty/inc
DEPS = glad.h glfw3.h glfw3native.h

CFLAGS += -Wall -g -fPIE -I../thirdParty/inc
CFLAGS := $(shell pkg-config --cflags $(FFMPEG_LIBS)) $(CFLAGS)
CXXFLAGS += -Wall -g
CXXFLAGS := $(shell pkg-config --cflags $(FFMPEG_LIBS)) $(CXXFLAGS)
LDLIBS := $(shell pkg-config --libs $(FFMPEG_LIBS)) $(LDLIBS)

# target
## TARGET1 := 0.1.0_multiwin_mx
## TGT_ALL += $(TARGET1).out
TARGET2 := 0.1.2_tessellation_demo
TGT_ALL += $(TARGET2).out
TARGET3 := 1.0_hello_window_clear
TGT_ALL += $(TARGET3).out
TARGET4 := 1.1.0_hello_triangle
TGT_ALL += $(TARGET4).out
TARGET5 := 1.1.1_hello_triangle_indexed
TGT_ALL += $(TARGET5).out
TARGET6 := 1.1.2_hello_triangle_indexed_for_demo
TGT_ALL += $(TARGET6).out
TARGET7 := 1.2.0_shaders_class
TGT_ALL += $(TARGET7).out
TARGET8 := 1.2.1_shaders_interpolation
TGT_ALL += $(TARGET8).out
TARGET9 := 1.2.2_shaders_uniform
TGT_ALL += $(TARGET9).out
TARGET10 := 1.3.0_textures
TGT_ALL += $(TARGET10).out
TARGET11 := 1.3.1_textures_combined
TGT_ALL += $(TARGET11).out
TARGET12 := 1.4.0_transformations
TGT_ALL += $(TARGET12).out
TARGET13 := 1.5.0_coordinate_systems
TGT_ALL += $(TARGET13).out
TARGET14 := 1.5.1_coordinate_systems_depth
TGT_ALL += $(TARGET14).out
TARGET15 := 1.5.2_coordinate_systems_multiple
TGT_ALL += $(TARGET15).out
TARGET16 := 1.6.0_camera_class
TGT_ALL += $(TARGET16).out
TARGET17 := 1.6.1_camera_circle
TGT_ALL += $(TARGET17).out
TARGET18 := 1.6.2_camera_keyboard_dt
TGT_ALL += $(TARGET18).out
TARGET19 := 1.6.3_camera_mouse_zoom
TGT_ALL += $(TARGET19).out
TARGET20 := 2.1.0_colors
TGT_ALL += $(TARGET20).out
TARGET21 := 2.2.0_basic_lighting_diffuse
TGT_ALL += $(TARGET21).out
TARGET22 := 2.2.1_basic_lighting_specular
TGT_ALL += $(TARGET22).out
TARGET23 := 2.2.2_basic_lighting_exercise1
TGT_ALL += $(TARGET23).out
TARGET24 := 2.2.3_basic_lighting_exercise2
TGT_ALL += $(TARGET24).out
TARGET25 := 2.3.0_materials
TGT_ALL += $(TARGET25).out
TARGET26 := 2.3.1_materials_for_demo
TGT_ALL += $(TARGET26).out
TARGET27 := 2.4.0_lighting_maps_diffuse
TGT_ALL += $(TARGET27).out
TARGET28 := 2.4.1_lighting_maps_specular
TGT_ALL += $(TARGET28).out
TARGET29 := 2.5.0_light_casters_point
TGT_ALL += $(TARGET29).out
TARGET30 := 2.5.1_light_casters_directional
TGT_ALL += $(TARGET30).out
TARGET31 := 2.5.2_light_casters_spot
TGT_ALL += $(TARGET31).out
TARGET32 := 2.5.3_light_casters_spot_soft
TGT_ALL += $(TARGET32).out
TARGET33 := 2.6.0_multiple_lights
TGT_ALL += $(TARGET33).out
TARGET34 := 2.6.1_multiple_lights_exercise1
TGT_ALL += $(TARGET34).out
TARGET35 := 3.1.0_model_loading
TGT_ALL += $(TARGET35).out
TARGET36 := 3.1.1_model_loading_light
TGT_ALL += $(TARGET36).out
TARGET37 := 3.1.2_model_loading_multi_light
TGT_ALL += $(TARGET37).out
TARGET38 := 3.1.3_model_loading_multi_light_normal
TGT_ALL += $(TARGET38).out
TARGET39 := 3.1.4_model_loading_multi_light_normal_for_demo
TGT_ALL += $(TARGET39).out
TARGET40 := 3.1.5_model_loading_multi_light_normal_for_offscreen
TGT_ALL += $(TARGET40).out
TARGET41 := 3.1.6_model_loading_fox
TGT_ALL += $(TARGET41).out
TARGET42 := 3.1.7_model_loading_multi_light_normal_ChryslerImperial
TGT_ALL += $(TARGET42).out
TARGET43 := 4.10.0_instancing_quads
TGT_ALL += $(TARGET43).out
TARGET44 := 4.1.0_depth_testing
TGT_ALL += $(TARGET44).out
TARGET45 := 4.5.0_framebuffers
TGT_ALL += $(TARGET45).out
TARGET46 := 4.5.1_framebuffers_demo
TGT_ALL += $(TARGET46).out
TARGET47 := 4.5.2_framebuffers_demo_v1
TGT_ALL += $(TARGET47).out
TARGET := 4.5.2_framebuffers_demo_v1
TARGET := 3.1.3_model_loading_multi_light_normal

# link
$(TARGET1).out: $(TARGET1).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET2).out: $(TARGET2).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET3).out: $(TARGET3).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET4).out: $(TARGET4).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET5).out: $(TARGET5).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET6).out: $(TARGET6).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET7).out: $(TARGET7).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET8).out: $(TARGET8).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET9).out: $(TARGET9).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET10).out: $(TARGET10).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET11).out: $(TARGET11).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET12).out: $(TARGET12).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET13).out: $(TARGET13).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET14).out: $(TARGET14).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET15).out: $(TARGET15).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET16).out: $(TARGET16).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET17).out: $(TARGET17).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET18).out: $(TARGET18).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET19).out: $(TARGET19).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET20).out: $(TARGET20).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET21).out: $(TARGET21).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET22).out: $(TARGET22).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET23).out: $(TARGET23).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET24).out: $(TARGET24).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET25).out: $(TARGET25).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET26).out: $(TARGET26).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET27).out: $(TARGET27).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET28).out: $(TARGET28).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET29).out: $(TARGET29).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET30).out: $(TARGET30).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET31).out: $(TARGET31).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET32).out: $(TARGET32).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET33).out: $(TARGET33).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET34).out: $(TARGET34).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET35).out: $(TARGET35).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET36).out: $(TARGET36).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET37).out: $(TARGET37).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET38).out: $(TARGET38).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET39).out: $(TARGET39).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET40).out: $(TARGET40).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET41).out: $(TARGET41).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET42).out: $(TARGET42).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET43).out: $(TARGET43).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET44).out: $(TARGET44).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET45).out: $(TARGET45).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET46).out: $(TARGET46).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

$(TARGET47).out: $(TARGET47).o glad.o ffmpeg_encode.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

.PHONY: all
all: $(TGT_ALL)
	@echo "$^"

%.out: %.o glad.o
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	./$@

# compile
%.o: %.cpp
	$(CXX) -o $@ -c $<  $(CXXFLAGS) $(INC)

%.o: %.c
	$(CC) -o $@ -c $<  $(CFLAGS) $(INC)

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
