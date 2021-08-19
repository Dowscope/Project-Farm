CFLAGS = -std=c++20
LDFLAGS = -lstdc++ -lglfw -lGL 
	
main:
	gcc $(CFLAGS) src/*.cpp -o game.run $(LDFLAGS)

debug:
	gcc $(CFLAGS) -g src/*.cpp -o game.run $(LDFLAGS)

clear:
	rm main