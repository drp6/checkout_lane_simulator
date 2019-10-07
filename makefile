all: grocery_sim
grocery_sim: main.cpp customer.cpp register.cpp store.cpp
	g++ main.cpp customer.cpp register.cpp store.cpp -o grocery_sim

clean: 
	$(RM) grocery_sim