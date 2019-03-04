#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
# path to tools - this can be deleted if you set the path in windows
#---------------------------------------------------------------------------------
PATH		:=	/c/DevKitArm/bin:/bin

#---------------------------------------------------------------------------------
# the prefix on the compiler executables
#---------------------------------------------------------------------------------
PREFIX			:=	arm-elf-

#---------------------------------------------------------------------------------
# source directories
#---------------------------------------------------------------------------------
SOURCES		:= .

#---------------------------------------------------------------------------------
# include directories
#---------------------------------------------------------------------------------
INCLUDES	:= .


#---------------------------------------------------------------------------------
# canned command sequence for binary data
#---------------------------------------------------------------------------------
define bin2o
	cp $(<) $(*).tmp
	$(OBJCOPY) -I binary -O elf32-littlearm -B arm \
	--rename-section .data=.rodata,readonly,data,contents,alloc \
	--redefine-sym _binary_$*_tmp_start=$*\
	--redefine-sym _binary_$*_tmp_end=$*_end\
	--redefine-sym _binary_$*_tmp_size=$*_size\
	$(*).tmp $(@)
#	echo "extern const uint32" $(*)"_end[];" >> $(*).h
#	echo "extern const uint8" $(*)"[];" >> $(*).h
#	echo "extern const uint32" $(*)_size[]";" >> $(*).h
	rm $(*).tmp
endef


#---------------------------------------------------------------------------------
# build a list of include paths
#---------------------------------------------------------------------------------

INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
			$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
			-I$(VBASE)


#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------

ARCH	:=	-mthumb-interwork

# note: arm9tdmi isn't the correct CPU arch, but anything newer and LD
# *insists* it has a FPU or VFP, and it won't take no for an answer!
#-Wall
CFLAGS	:=	-g -O2 -D _GBA_\
 			-use-mlong-calls -mcpu=arm7tdmi -mtune=arm7tdmi\
			-fomit-frame-pointer -ffast-math\
			$(ARCH)

CFLAGS	+=	$(INCLUDE)

ASFLAGS	:=	-g $(ARCH)
LDFLAGS	:=	-g $(ARCH) -Wl,-Map,$(notdir $@).map -mno-fpu


#---------------------------------------------------------------------------------

CC		:=	$(PREFIX)gcc
CXX		:=	$(PREFIX)g++
AR		:=	$(PREFIX)ar
OBJCOPY	:=	$(PREFIX)objcopy

#---------------------------------------------------------------------------------
# automatically build a list of object files for our project
#---------------------------------------------------------------------------------

CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
CARMFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.armc)))
CPPARMFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.armcpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
SSFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.S)))
BINFILES	:=  $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.bin)))

OFILES2	:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o)\
			$(CPPARMFILES:.armcpp=.o) $(CARMFILES:.armc=.o)\
			$(SFILES:.s=.o) $(SSFILES:.S=.o) $(BINFILES:.bin=.o)
OFILES	:=	$(foreach dir,$(OFILES2),$(BUILDPATH)/$(dir))



#---------------------------------------------------------------------------------


$(BUILDPATH)/$(OUTFILE) : $(OFILES)
	@$(AR) rcs $(BUILDPATH)/$(OUTFILE) $(OFILES)



#---------------------------------------------------------------------------------
# Compile Targets for C/C++
#---------------------------------------------------------------------------------

$(BUILDPATH)/%.o : %.cpp
	@echo $(notdir $<)
	@$(CXX) -MMD -mthumb -D _THUMB_ $(CFLAGS) -o $(BUILDPATH)/$@ -c $<

#---------------------------------------------------------------------------------

$(BUILDPATH)/%.o : %.c
	@echo $(notdir $<)
	@$(CC) -MMD -mthumb -D _THUMB_ $(CFLAGS) -o $(BUILDPATH)/$@ -c $<

#---------------------------------------------------------------------------------

$(BUILDPATH)/%.o : %.armcpp
	@echo $(notdir $<)
	@$(CXX) -MMD -marm -D _ARM_ $(CFLAGS) -xc++ -o $(BUILDPATH)/$@ -c $<

#---------------------------------------------------------------------------------

$(BUILDPATH)/%.o : %.armc
	@echo $(notdir $<)
	@$(CC) -MMD -marm -D _ARM_ $(CFLAGS) -xc -o $(BUILDPATH)/$@ -c $<

#---------------------------------------------------------------------------------

$(BUILDPATH)/%.o : %.s
	@echo $(notdir $<)
	@$(CC) -MMD $(ASFLAGS) -o $(BUILDPATH)$@ -c $<

#---------------------------------------------------------------------------------

$(BUILDPATH)/%.o : %.S
	@echo $(notdir $<)
	@$(CC) -MMD $(ASFLAGS) -o $(BUILDPATH)/$@ -c $<

#---------------------------------------------------------------------------------

$(BUILDPATH)/%.o : %.bin
	@echo $(notdir $<)
	@$(bin2o)

#---------------------------------------------------------------------------------
