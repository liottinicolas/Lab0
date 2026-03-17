CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include
SRCDIR = src
OBJDIR = obj
TARGET = lab0

# Comando de Valgrind
#VALGRIND = valgrind --leak-check=full --show-leak-kinds=definite
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Detectar sistema operativo
ifeq ($(OS),Windows_NT)
    MKDIR = if not exist $(OBJDIR) mkdir $(OBJDIR)
    RM    = if exist $(OBJDIR) rmdir /s /q $(OBJDIR)
    RUN   = $(TARGET).exe
else
    MKDIR = mkdir -p $(OBJDIR)
    RM    = rm -rf $(OBJDIR) $(TARGET)
    RUN   = ./$(TARGET)
endif

# Encontrar todos los archivos .cpp en src/
SOURCES  = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS  = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
MAIN_OBJ = $(OBJDIR)/main.o

# Regla principal
$(TARGET): $(MAIN_OBJ) $(OBJECTS)
	$(CXX) $(MAIN_OBJ) $(OBJECTS) -o $(TARGET)

# Regla para compilar main.cpp a obj/main.o
$(MAIN_OBJ): main.cpp
	@$(MKDIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(MAIN_OBJ)

# Regla para compilar archivos .cpp a .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(MKDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	@$(RM)

# Ejecutar el programa
run: $(TARGET)
	$(RUN)

# Analizar con Valgrind (solo Linux/Mac)
check: $(TARGET)
	$(VALGRIND) ./$(TARGET)

# Regla para mostrar ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make        - Compilar el proyecto"
	@echo "  make run    - Compilar y ejecutar"
	@echo "  make check  - Ejecutar con Valgrind (solo Linux/Mac)"
	@echo "  make clean  - Limpiar archivos compilados"
	@echo "  make help   - Mostrar esta ayuda"

.PHONY: clean run check help
