default:
	gcc src/main.c -o fork
install:
	sudo cp fork /usr/local/bin/
	sudo chmod +x /usr/local/bin/fork
