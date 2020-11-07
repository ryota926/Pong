default: build

build:
	@g++ src/main.cpp src/Player.cpp src/Ball.cpp src/Player2Factory.cpp src/EasyComputer.cpp src/HardComputer.cpp src/Player2.cpp src/HumanPlayer.cpp -lncurses -o pong || (echo "\n==> $(tput setaf 1)Make failed.  Do you have all the src files?\n$(tput sgr0)"; exit 1)
	@echo "\n==> $(tput setaf 2)Make successful. Start the game using the command: $(tput sgr0)'make run'$(tput setaf 2)\n"

run:
	./pong || true

clean:
	rm pong
