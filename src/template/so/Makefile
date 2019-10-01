CC=gcc
CXX=g++
AR=ar
LN=ln
RM=ln
#-------------------------------------------------------------------------------
OS=$(shell $(CXX) -dumpmachine)
ifneq (,$(findstring mingw,$(OS)))
SOEXT?=.dll
BINEXT?=.exe
else
SOEXT?=.so
BINEXT?=
endif
ifeq ($(PREFIX),)
PREFIX := /usr/local
endif
#-------------------------------------------------------------------------------
#LIBRARY
#-------------------------------------------------------------------------------
LIBBUILDDIR=./bin/build
LIBDIR=lib
LIBNAM=a
LIBPFX=lib
LIBVER=1
LIBBIN=$(LIBDIR)/$(LIBPFX)$(LIBNAM)$(SOEXT).$(LIBVER)
LIBLN=$(LIBDIR)/$(LIBPFX)$(LIBNAM)$(SOEXT)
LIBSRCDIR=src/lib
LIBSRC:=$(shell find $(LIBSRCDIR) -name '*.cpp')
LIBOBJS:=$(addprefix $(LIBBUILDDIR)/,$(LIBSRC:%.cpp=%.o))
LIBCFLAGS=\
	-I./include/lib
LIBLDFLAGS=\
#-------------------------------------------------------------------------------
#APPLICATION
#-------------------------------------------------------------------------------
APPBUILDDIR=./bin/build
APPBIN=./bin/a$(BINEXT)
APPSRCDIR=src/app
APPSRC:=$(shell find $(APPSRCDIR) -name '*.cpp')
APPOBJS:=$(addprefix $(APPBUILDDIR)/,$(APPSRC:%.cpp=%.o))
APPRPATH=./lib
APPCFLAGS=\
	-I./include/app\
	-I./include/lib\
	-L$(LIBDIR)\
	-Wl,-rpath=$(APPRPATH)
APPLDFLAGS=\
	   -l$(LIBNAM)
#-------------------------------------------------------------------------------
#RULES
#-------------------------------------------------------------------------------
all:\
	$(APPBIN)
#-------------------------------------------------------------------------------
#APPLICATION RULES
#-------------------------------------------------------------------------------
$(APPBIN):$(APPOBJS) $(LIBLN)
	$(CXX)\
		$(APPCFLAGS)\
		$(APPOBJS)\
		-o $(APPBIN)\
		$(APPLDFLAGS)
$(APPBUILDDIR)/%.o: %.cpp
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	$(CXX)\
		$(APPCFLAGS)\
		-c $<\
		$(APPLDFLAGS)\
		-o $@
#-------------------------------------------------------------------------------
#LIBRARY RULES
#-------------------------------------------------------------------------------
$(LIBLN):$(LIBBIN)
	$(LN)\
		-sfn \
		$(shell pwd)/$(LIBBIN) \
		$(shell pwd)/$(LIBLN)
$(LIBBIN):$(LIBOBJS)
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	$(CXX)\
		$(LIBCFLAGS)\
		$(LIBOBJS)\
		$(LIBLDFLAGS)\
		-shared \
		-Wl,-soname,lib$(LIBNAM)$(SOEXT) \
		-o $(LIBBIN)
$(LIBBUILDDIR)/%.o: %.cpp
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	$(CXX)\
		$(LIBCFLAGS)\
		-c $<\
		-fPIC \
		$(LIBLDFLAGS)\
		-o $@
#-------------------------------------------------------------------------------
#MISC
#-------------------------------------------------------------------------------
.phony:\
	run\
	clean\
	lsvar
clean:
	@rm -r ./bin ./lib
run:
	$(APPBIN)
lsvar:
	@echo $(APPBIN)
	@echo $(APPOBJS)
	@echo $(APPSRC)
	@echo $(APPSRCDIR)
	@echo $(PREFIX)




