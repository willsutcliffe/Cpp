# name of the library
LIBNAME = datastructures

#Necessary to use shell built-in commands
SHELL = bash

# A list of directories
MAINDIR =/Users/willsut/Work/InterviewPrep/Coding/Cpp/MyLibraries
BASE_DIR = $(shell pwd)
LIB_DIR  = $(BASE_DIR)/lib
EXE_DIR  = $(BASE_DIR)/bin
SRC_DIR  = $(BASE_DIR)/src
OBJ_DIR  = $(BASE_DIR)/obj
INC_DIR  = $(BASE_DIR)/include

OBJ_EXT = o

FLAGS  		 = -O3 -Wall -W -fPIC
INCLUDE		+= -I$(INC_DIR)
FLAGS       += ${INCLUDE}

#ROOT_FLAGS   = $(shell $(ROOTSYS)/bin/root-config --cflags)
#ROOT_LIBS    = $(shell $(ROOTSYS)/bin/root-config --libs) -lTreePlayer -lMinuit -lXMLIO -lMLP -lRIO -lTMVA
#ROOT_FLAGS   =  root-config --cflags
#ROOT_LIBS    =  root-config --libs -lTreePlayer -lMinuit -lXMLIO -lMLP -lRIO -lTMVA
#ROOFIT_LIBS  = ${ROOT_LIBS} -lRooFitCore -lRooFit -lRooStats -lFoam

#USER_LIBS += -L$(WS_DIR)/Stools/lib/ -lStools
#USER_LIBS += -L$(WS_DIR)/Knives/lib/ -lKnives

#USER_INCLUDES += -I$(WS_DIR)/Stools/include/
#USER_INCLUDES += -I$(WS_DIR)/Cuts/include/
#USER_INCLUDES += -I$(WS_DIR)/Knives/include/

#ROOFIT_LIBS += $(USER_LIBS)

CXX = g++
LD  = g++
CXXFLAGS = -Wall -W -O3
LDFLAGS  = -shared -Wall -W

#LIBS += $(USER_LIBS)
#LIBS    += -L$(BOOST_LIBS)

#LDFLAGS += $(USER_LIBS)
#LDFLAGS += $(LIBS)
#FLAGS += $(USER_INCLUDES)
#FLAGS += ${ROOT_FLAGS}
#FLAGS += -I$(BOOST_INCLUDES)

# Build a list of srcs and bins to build
SRCS = $(filter-out $(wildcard $(SRC_DIR)/_*), $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR),$(subst cpp,$(OBJ_EXT),$(SRCS)))
BINS = $(subst $(BIN_DIR), $(SRC_DIR),$(subst .cpp,,$(EXES)))

all: $(OBJS) lib

$(OBJ_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CXX) $(FLAGS) -c $< -o $@

$(LIB_DIR)/lib$(LIBNAME).so: $(OBJS)
	$(LD) $(LDFLAGS) -shared -o $(LIB_DIR)/lib$(LIBNAME).so $(OBJS)  
	cp -f $(LIB_DIR)/lib$(LIBNAME).so $(MAINDIR)/lib/lib$(LIBNAME).so

lib: $(LIB_DIR)/lib$(LIBNAME).so

clean:
	rm -f $(OBJS) $(LIB_DIR)/*.so

copy:
	cp -f $(LIB_DIR)/lib$(LIBNAME).so $(MAINDIR)/lib/.

info:
	@echo SRCS $(SRCS)
	@echo OBJS $(OBJS)

