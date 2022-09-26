mingw:
	g++ -shared -o  heart.dll mongoose.c setup.cpp   request.cpp response.cpp server.cpp url.cpp view.cpp heart.cpp -Wl,--out-implib=libheart.a   -lws2_32  
	g++ test.cpp   -o test.exe libheart.a 