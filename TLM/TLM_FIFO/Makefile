CC = "g++"
PROJECT =  main	 
SRC = module.cpp module0.cpp main.cpp vp.cpp module1.cpp

LIBS = `pkg-config opencv4 --cflags --libs`
																		
$(PROJECT) : $(SRC)
	$(CC) -g $(SRC) -lsystemc -fno-omit-frame-pointer -o $(PROJECT) $(LIBS)

profiling: 
	valgrind --tool=callgrind ./$(PROJECT)
clean:
	rm -f *.o all $(PROJECT) callgrind.*

