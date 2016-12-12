
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

# == RUN ==

.PHONY: run
run: build
	@clear
	@./$(APP)

# == CLEAN ==

.PHONY: clean
clean:
	@echo "Remove $(COL_A)$(APP)$(COL) executable"
	@rm -f $(APP)
	@echo "Remove $(COL_A)$(PATH_BUILD)/$(COL) folder"
	@rm -fr $(PATH_BUILD)
	@echo "$(COL_B)- Cleaned -$(COL)"


# == OTHER ==

.PHONY: rebuild
rebuild: clean build

.PHONY: rebuildrun
rebuildrun: clean build run