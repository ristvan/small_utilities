PROGRAM_NAME=tour

INCLUDE_DIR_LIST=../../../common/inc

LIBRARY_DIR_LIST=../../../common/lib
LIBRARY_LIST=Common

CPP_FILES=TextFileReader.cc \
          TableCell.cc\
          TableRow.cc\
          Table.cc\
          TextTableWriter.cc\
          MainBase.cc\
          SummarizedInfo.cc\
          CsucsokCsucsa.cc\
          main.cpp

GCC=g++
#OBJECT_DIR=obj.`uname -m`
OBJECT_DIR=obj.i686
#OBJECT_FILES_TMP=$(patsubst %.cc, $(OBJECT_DIR)/%.o, $(CPP_FILES))
#OBJECT_FILES+=$(patsubst %.cpp, $(OBJECT_DIR_TMP)/%.o, $(CPP_FILES))
OBJECT_FILES_TMP=$(CPP_FILES:%.cc=$(OBJECT_DIR)/%.o)
OBJECT_FILES=$(OBJECT_FILES_TMP:%.cpp=$(OBJECT_DIR)/%.o)
#OBJECT_FILES_TMP=$(CPP_FILES:%.cc=%.o)
#OBJECT_FILES=$(OBJECT_FILES_TMP:%.cpp=%.o)

#WARNING_FLAGS=-Wunused -Wc++0x-compat -Warray-bounds -Werror
WARNING_FLAGS=-Wunused -Werror
CXX_FLAGS=$(INCLUDE_DIR_LIST:%=-I%) $(WARNING_FLAGS) -ggdb

LIB_DIRS=$(LIBRARY_DIR_LIST:%=-L%)
LIB_LIST=$(LIBRARY_LIST:%=-l%)
LD_FLAGS=$(LIB_DIRS) $(LIB_LIST) -ggdb

all: $(PROGRAM_NAME)
	@echo Done
#	@echo "-------\nall:"
#	@echo $(OBJECT_DIR)
#	@echo $(OBJECT_FILES)
#	@echo $<
#	@echo $+
#	@echo $(GCC) -o $< $(OBJECT_FILES) $(LD_FLAGS)

$(PROGRAM_NAME): $(OBJECT_FILES)
	$(GCC) -o $@ $+ $(LD_FLAGS)
#	@echo "---------------\nPR_NAME:"
#	@echo $@
#	@echo $<
#	@echo $+
#	@echo $(GCC) -o $@ $+ $(LD_FLAGS)

$(OBJECT_FILES): $(CPP_FILES) $(OBJECT_DIR)
	$(GCC) -c -o $@ $(CXX_FLAGS) $(@:$(OBJECT_DIR)/%.o=%.$(patsubst %.cc,,$(patsubst %.cpp,,$(CPP_FILES:$(@:$(OBJECT_DIR)/%.o=%).%=%))))
#	@echo "----------"
#	@echo $@
#	@echo $<
#	@echo $+
#	@echo $(GCC) -c -o $@ $(CXX_FLAGS) $(@:$(OBJECT_DIR)/%.o=%.$(patsubst %.cc,,$(patsubst %.cpp,,$(CPP_FILES:$(@:$(OBJECT_DIR)/%.o=%).%=%))))

$(OBJECT_DIR):
	mkdir -p $@
#	@echo mkdir -p $@

clean:
	@echo "Cleaning application"
	rm -f $(PROGRAM_NAME)
	rm -rf $(OBJECT_DIR)

#include ../tools/makefile.bin
