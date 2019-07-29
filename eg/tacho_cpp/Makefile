TARGET = $(notdir $(CURDIR))

.PHONY: default clean clean-binary debug debug-clean debug-clean-binary release release-clean

default: debug

clean: debug-clean-binary

ifeq ($(OS),Windows_NT)
CC = gcc
CXX = g++
define remove
	cmd /c del /f $(subst /,\,$1)
endef
else
CC = arm-linux-gnueabi-gcc
CXX = arm-linux-gnueabi-g++
define remove
	rm -f
endef
endif

clean-all: debug-clean

debug:
	$(MAKE) -f $(MAKEFILE_BASE).Debug

debug-clean:
	$(MAKE) -f $(MAKEFILE_BASE).Debug clean

debug-clean-binary:
	$(MAKE) -f $(MAKEFILE_BASE).Debug clean-binary

release:
	$(MAKE) -f $(MAKEFILE_BASE).Release

$(CXX_OBJS): $(D_BIN)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PRECIOUS: $(F_BIN) $(C_OBJS) $(CXX_OBJS)

$(F_BIN): $(C_OBJS) $(CXX_OBJS)
	$(CXX) $(C_OBJS) $(CXX_OBJS) -Wall $(LIBS) -o $@

clean:
	-$(call remove,$(D_BIN)/*.o)
	-$(call remove,$(F_BIN))
