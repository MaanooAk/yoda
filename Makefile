
# paths
PATH_SRC = src
PATH_BUILD = build

# commands
COMPILE := g++ -Wall

# files
SOURCES = $(wildcard $(PATH_SRC)/*.cpp)
OBJECTS = $(SOURCES:$(PATH_SRC)/%.cpp=$(PATH_BUILD)/%.o)
APP = yoda

# colors
COL = \033[m
COL_A = \033[1;34m
COL_B = \033[1;37m

# == BUILD ==

.PHONY: build
build: $(PATH_BUILD)/ $(APP)
	@echo "$(COL_B)- Builded -$(COL)"

$(PATH_BUILD)/:
	@echo "Make $(COL_A)$@$(COL) folder"
	@mkdir -p $@

$(APP): $(OBJECTS)
	@echo "Link objects"
	@$(COMPILE) -o $@ $^

$(PATH_BUILD)/%.o: $(PATH_SRC)/%.cpp
	@echo "Compile $(COL_A)$<$(COL)"
	@$(COMPILE) -c $< -o $@
