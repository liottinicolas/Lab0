# Compilador
CXX = g++

# Banderas
CXXFLAGS = -std=c++98 -Wall -Wextra -I./include

# Directorios
SRCDIR = src
OBJDIR = obj
TARGET = lab0

# Comando de Valgrind
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Comandos
MKDIR = mkdir -p $(OBJDIR)
RM    = rm -rf $(OBJDIR) $(TARGET)
RUN   = ./$(TARGET)

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

.PHONY: clean run check
