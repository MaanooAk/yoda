
# paths
PATH_SRC = src
PATH_BUILD = build

# commands
COMPILE = g++ -Wall -std=c++11

# files
SOURCES = $(wildcard $(PATH_SRC)/*.cpp)
OBJECTS = $(SOURCES:$(PATH_SRC)/%.cpp=$(PATH_BUILD)/%.o)
APP = yoda

# colors
COL = \033[m
COL_A = \033[1;34m
COL_B = \033[1;37m

.PHONY: default
default: build

# == BUILD ==

.PHONY: build
build: clean $(PATH_BUILD)/ $(APP)
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

# == RUN ==

.PHONY: run
run: build
	@clear
	@./$(APP)

# == TEST ==

.PHONY: test
test: build
	@./$(APP) test || exit 1

# == CLEAN ==

.PHONY: clean
clean:
	@echo "Remove $(COL_A)$(APP)$(COL) executable"
	@rm -f $(APP)
	@echo "Remove $(COL_A)$(PATH_BUILD)/$(COL) folder"
	@rm -fr $(PATH_BUILD)
	@echo "$(COL_B)- Cleaned -$(COL)"


# == OTHER ==

.PHONY: all
all: clean build test run

# == HELP ==

.PHONY: help
help:
	@echo "Format: make [option]"
	@echo ""
	@echo "Options:"
	@echo "  build        Build (default)"
	@echo "  run          Build and run"
	@echo "  test         Build and run tests"
	@echo "  clean        Clean"
	@echo "  all          Build, run tests and run"
	@echo "  help         Help"
	@echo ""
