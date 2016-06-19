#Necessary to use shell built-in commands
SHELL=bash

SUBDIRS += Stools
SUBDIRS += Trees
SUBDIRS += Analysis
SUBDIRS += RooPdfs

#LIBS = $(wildcard $(SUBDIRS)/lib/lib*.so)
#LIBS = $(addsuffix .so, $(SUBDIRS))
#LIBS = $(wildcard $(SUBDIRS)/lib/lib*)


all:  $(SUBDIRS)

.PHONY: $(SUBDIRS) $(LIBS)
     

$(SUBDIRS):
	$(MAKE) -C $@
	cp -f $@/lib/*.so lib/.


copy:
	cp -f Stools/lib/*.so lib/.
	cp -f Trees/lib/*.so lib/.
	cp -f Analysis/lib/*.so lib/.
	cp -f RooPdfs/lib/*.so lib/.


clean:
	rm -f lib/*.so
	$(MAKE) -C Stools/ clean
	$(MAKE) -C Trees/ clean
	$(MAKE) -C Analysis/ clean
	$(MAKE) -C RooPdfs/ clean

info:
	@echo $(LIBS)

