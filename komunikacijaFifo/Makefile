CC = "g++"
PROJECT =  main	 
SRC = module0.cpp main.cpp module1.cpp vp.cpp

LIBS = `pkg-config opencv4 --cflags --libs`
																		
$(PROJECT) : $(SRC)
	$(CC) -g $(SRC) -lsystemc -fno-omit-frame-pointer -o $(PROJECT) $(LIBS)

profiling: 
	valgrind --tool=callgrind ./$(PROJECT)
clean:
	rm -f *.o all $(PROJECT) callgrind.*

