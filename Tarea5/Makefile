CPP_SRCS += \
./Map.cpp \
./Tarea5.cpp \


OBJS += \
./Map.o \
./Tarea5.o \


CPP_DEPS += \
./Map.d \
./Tarea5.d \

%.o: ./%.cpp
	g++ -std=gnu++11 -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"

all: Tarea5

run: all
	./Tarea5.out MapEDD.pbm 

Tarea5: $(OBJS) 
	g++ -o Tarea5.out $(OBJS) $(LIBS)
	@echo "Sin problemas."

# Other Targets
clean:
	rm $(OBJS) $(CPP_DEPS) Tarea5.out
	@echo "Archivos eliminados."