mingw:
	g++ mongoose.c setup.cpp  request.cpp response.cpp server.cpp url.cpp view.cpp test.cpp -lws2_32  -o  test.exe