vpath %h ../thirdParty/inc
vpath %c ../thirdParty/src

hellowindow.o: hellowindow2.cpp glad/glad.h GLFW/glfw3.h
	g++ hellowindow2.cpp -I ../thirdParty/inc -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi
