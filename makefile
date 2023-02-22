main: src/main.cpp
	g++ -o sitecat src/main.cpp -lcurl 

#Prints to console to help the user finish the install. 
$(info The code is compiled!)
$(info run: "sudo cp sitecat /usr/bin" to finish the install.)