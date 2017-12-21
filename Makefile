# https://stackoverflow.com/a/16346321
BINDIR := ./bin
create_bin_dir := $(shell mkdir -p $(BINDIR))
OBJDIR := ./obj
create_obj_dir := $(shell mkdir -p $(OBJDIR))
SRCDIR := ./src

CPPFLAGS := -I ./
CFLAGS := -std=c11 -Wall -Wextra -Wshadow -pedantic
LDFLAGS := -lpthread

targets :=\
	array_len \
	strange_main_twitter \
	function_pointer \
	egg_dropping_puzzle

# shellcheck all shell scripts
# https://stackoverflow.com/a/5423310/496459
SHCHK := shellcheck
scripts := $(shell find . -type f -name \*.sh)
.PHONY: ${scripts}
${scripts}:
	@echo "SHCHK $@"
	$(SHCHK) $@

.PHONY: shellcheck
shellcheck: ${scripts}

.PHONY: all
all:: shellcheck
define make-target
$(1): $(OBJDIR)/$(1).o
	@echo "LD $(1)"
	$(CC) -o $(BINDIR)/$(1) $(OBJDIR)/$(1).o $(LDFLAGS)
all:: $(1)
endef
# To debug a foreach loop, replace $(eval ...) with $(info ...)
$(foreach element,$(targets),$(eval $(call make-target,$(element))))

.PHONY: clean
clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/*

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "CC $<"
	cppcheck --enable=all --suppress=missingIncludeSystem $<
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

# http://make.mad-scientist.net/managing-recipe-echoing/
$(V).SILENT:
