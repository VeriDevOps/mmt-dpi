VERSION  := 1.6.8.0
GIT_VERSION := $(shell git log --format="%h" -n 1)
MMT_BASE ?=/opt/mmt
MMT_DPI ?= $(MMT_BASE)/dpi
MMT_LIB ?= $(MMT_DPI)/lib
MMT_INC ?= $(MMT_DPI)/include
MMT_PLUGINS ?= $(MMT_BASE)/plugins
MMT_EXAMS ?= $(MMT_BASE)/examples

#  - - - - -
# DEFINE SOME COMMANDS
#  - - - - -

CP       := cp -R
RM       := rm -rf

#  - - - - -
# DEFINE VERBOSE MODE
#  - - - - -

ifndef VERBOSE
 QUIET := @
 export QUIET
endif

#  - - - - -
# DEFINE FLAG FOR COMPILE COMMAND
#  - - - - -

CFLAGS   := -Wall -DVERSION=\"$(VERSION)\" -DGIT_VERSION=\"$(GIT_VERSION)\"
CXXFLAGS := -Wall -DVERSION=\"$(VERSION)\" -DGIT_VERSION=\"$(GIT_VERSION)\"

# NDEBUG = 1 to show all message come from debug(), ...
ifdef NDEBUG
CFLAGS   += $(CFLAGS)
CXXFLAGS += $(CXXFLAGS)
else
CFLAGS   += -DNDEBUG
CXXFLAGS += -DNDEBUG
endif

# DEBUG = 1 to enable debug mode
ifdef DEBUG
CFLAGS   += -g 
CXXFLAGS += -g 
else
CFLAGS   += -O3
CXXFLAGS += -O3
endif

# SHOWLOG = 1 to show all the log from MMT_LOG() ...
ifdef SHOWLOG
CFLAGS   += -DDEBUG -DHTTP_PARSER_STRICT=1
CXXFLAGS += -DDEBUG -DHTTP_PARSER_STRICT=1
else
CFLAGS   += -DHTTP_PARSER_STRICT=0
CXXFLAGS += -DHTTP_PARSER_STRICT=0
endif

# LIGHTSDK = 1 to compile the light version of SDK (which aims to split the network to HTTP packets and nonHTTP packets)
ifdef LIGHTSDK
CFLAGS   += -DLIGHTSDK
CXXFLAGS += -DLIGHTSDK
endif

.PHONY: libraries includes tools documentation examples


#  - - - - -
#  P A T H S
#  - - - - -

SRCDIR       := $(TOPDIR)/src
SRCINC       := $(SRCDIR)/mmt_core/public_include  \
                $(SRCDIR)/mmt_core/private_include \
                $(SRCDIR)/mmt_fuzz_engine          \
                $(SRCDIR)/mmt_tcpip/include        \
                $(SRCDIR)/mmt_tcpip/lib

SDKDIR       := $(TOPDIR)/sdk
SDKDOC       := $(SDKDIR)/doc
SDKINC       := $(SDKDIR)/include
SDKINC_TCPIP := $(SDKDIR)/include/tcpip
SDKINC_FUZZ  := $(SDKDIR)/include/fuzz
SDKLIB       := $(SDKDIR)/lib
SDKBIN       := $(SDKDIR)/bin
SDKXAM       := $(SDKDIR)/examples

$(SDKLIB) $(SDKINC) $(SDKINC_TCPIP) $(SDKINC_FUZZ) $(SDKBIN) $(SDKDOC) $(SDKXAM) $(MMT_BASE) $(MMT_DPI) $(MMT_INC) $(MMT_PLUGINS) $(MMT_EXAMS) $(MMT_LIB):
	@mkdir -p $@


#  - - - - - - - - -
#  L I B R A R I E S
#  - - - - - - - - -

LIBCORE     := libmmt_core
LIBTCPIP    := libmmt_tcpip
LIBEXTRACT  := libmmt_extract
LIBSECURITY := libmmt_security
LIBFUZZ     := libmmt_fuzz

CORE_OBJECTS := \
 $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/mmt_core/src/*.c)) \
 $(patsubst %.cpp,%.o,$(wildcard $(SRCDIR)/mmt_core/src/*.cpp))

# remove mmt_tcpip_init.o from CORE_OBJECTS
CORE_OBJECTS := $(filter-out $(SRCDIR)/mmt_core/src/mmt_tcpip_init.o,$(CORE_OBJECTS))

TCPIP_OBJECTS := \
 $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/mmt_tcpip/lib/*.c)) \
 $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/mmt_tcpip/lib/protocols/*.c))

FUZZ_OBJECTS := \
 $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/mmt_fuzz_engine/*.c))

SECURITY_OBJECTS := \
 $(patsubst %.c,%.o,$(wildcard $(SRCDIR)/mmt_security/*.c))

$(CORE_OBJECTS) $(TCPIP_OBJECTS) $(FUZZ_OBJECTS) $(SECURITY_OBJECTS): CFLAGS += -D_MMT_BUILD_SDK $(patsubst %,-I%,$(SRCINC))
$(CORE_OBJECTS) $(TCPIP_OBJECTS) $(FUZZ_OBJECTS) $(SECURITY_OBJECTS): CXXFLAGS += -D_MMT_BUILD_SDK $(patsubst %,-I%,$(SRCINC))

# CORE

$(SDKLIB)/$(LIBCORE).a: $(SDKLIB) $(CORE_OBJECTS)
	@echo "[ARCHIVE] $(notdir $@)"
	$(QUIET) $(AR) $@ $(CORE_OBJECTS)

# TCP/IP

$(SDKLIB)/$(LIBTCPIP).a: $(SDKLIB) $(TCPIP_OBJECTS) 
	@echo "[ARCHIVE] $(notdir $@)"
	$(QUIET) $(AR) $@ $(TCPIP_OBJECTS) 

# FUZZ

$(SDKLIB)/$(LIBFUZZ).a: $(SDKLIB) $(FUZZ_OBJECTS)
	@echo "[ARCHIVE] $(notdir $@)"
	$(QUIET) $(AR) $@ $(FUZZ_OBJECTS)

# SECURITY

$(SDKLIB)/$(LIBSECURITY).a: $(SDKLIB) $(SECURITY_OBJECTS)
	@echo "[ARCHIVE] $(notdir $@)"
	$(QUIET) $(AR) $@ $(SECURITY_OBJECTS)


#  - - - - - - - -
#  I N C L U D E S
#  - - - - - - - -

MMT_HEADERS       = $(wildcard $(SRCDIR)/mmt_core/public_include/*.h)
SDK_HEADERS       = $(addprefix $(SDKINC)/,$(notdir $(MMT_HEADERS)))

MMT_TCPIP_HEADERS = $(wildcard $(SRCDIR)/mmt_tcpip/include/*.h)
SDK_TCPIP_HEADERS = $(addprefix $(SDKINC_TCPIP)/,$(notdir $(MMT_TCPIP_HEADERS)))

MMT_FUZZ_HEADERS = $(wildcard $(SRCDIR)/mmt_fuzz_engine/*.h)
SDK_FUZZ_HEADERS = $(addprefix $(SDKINC_FUZZ)/,$(notdir $(MMT_FUZZ_HEADERS)))

includes: $(SDK_HEADERS) $(SDK_TCPIP_HEADERS) $(SDK_FUZZ_HEADERS)

$(SDKINC)/%.h: $(SRCDIR)/mmt_core/public_include/%.h
	@echo "[INCLUDE] $(notdir $@)"
	$(QUIET) cp -f $< $@

$(SDKINC_TCPIP)/%.h: $(SRCDIR)/mmt_tcpip/include/%.h
	@echo "[INCLUDE] $(notdir $@)"
	$(QUIET) cp -f $< $@

$(SDKINC_FUZZ)/%.h: $(SRCDIR)/mmt_fuzz_engine/%.h
	@echo "[INCLUDE] $(notdir $@)"
	$(QUIET) cp -f $< $@

$(SDK_HEADERS): $(SDKINC) $(SDKINC_TCPIP) $(SDKINC_FUZZ)


#  - - - - -
#  T O O L S
#  - - - - -

tools: $(SDKBIN)


#  - - - - - - - - - - - - -
#  D O C U M E N T A T I O N
#  - - - - - - - - - - - - -

documentation: $(SDKDOC)


#  - - - - - - - -
#  E X A M P L E S
#  - - - - - - - -

MMT_EXAMPLES_SRC = attribute_handler_session_counter.c extract_all.c google-fr.pcap html_integration.c html_integration.h MAC_extraction.c packet_handler.c proto_attributes_iterator.c reconstruct_body.c simple_traffic_reporting.c 
SDK_EXAMPLES_SRC = $(addprefix $(SDKXAM)/,$(MMT_EXAMPLES_SRC))

examples: $(SDK_EXAMPLES_SRC)
#  $(QUIET) $(MAKE) -C $(SRCDIR)/examples -f Makefile.mmt SDKROOT=$(TOPDIR)/sdk

$(SDKXAM)/%.c: $(SRCDIR)/examples/%.c
	@echo "[EXAMPLE] $(notdir $@)"
	$(QUIET) cp -f $< $@

$(SDK_EXAMPLES_SRC): $(SDKXAM)


#  - - - - -
#  R U L E S
#  - - - - -

%.o: %.c
	@echo "[COMPILE] $(notdir $@)"
	$(QUIET) $(CC) $(CFLAGS) -I. -o $@ -c $<

%.o: %.cc
	@echo "[COMPILE] $(notdir $@)"
	$(QUIET) $(CXX) $(CXXFLAGS) -I. -o $@ -c $<

%.o: %.cpp
	@echo "[COMPILE] $(notdir $@)"
	$(QUIET) $(CXX) $(CXXFLAGS) -I. -o $@ -c $<

