# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f VNFALU.mk

default: VNFALU

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /opt/homebrew/Cellar/verilator/4.200/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = VNFALU
# Module prefix (from --prefix)
VM_MODPREFIX = VNFALU
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-Wno-undefined-bool-conversion -O1 -DTOP_TYPE=VNFALU -DVL_USER_FINISH -include VNFALU.h \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	NFALU-harness \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
<<<<<<< HEAD
	/home/almas/Videos/fpu_rv32/test_run_dir/NFALU_Test \
=======
	/Users/shahzaib/fpu_rv32/test_run_dir/NFALU_Test \
>>>>>>> 314c2f877bccef973de4977addaf0feb0e9625e5


### Default rules...
# Include list of all generated classes
include VNFALU_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

<<<<<<< HEAD
NFALU-harness.o: /home/almas/Videos/fpu_rv32/test_run_dir/NFALU_Test/NFALU-harness.cpp
=======
NFALU-harness.o: /Users/shahzaib/fpu_rv32/test_run_dir/NFALU_Test/NFALU-harness.cpp
>>>>>>> 314c2f877bccef973de4977addaf0feb0e9625e5
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<

### Link rules... (from --exe)
VNFALU: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-
