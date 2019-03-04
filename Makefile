export DEVDIR	:= C:/DevKitArm
export VBASE	:= D:/Programming/C++/vBaseS~1
LIBDIR			:= $(DEVDIR)/arm-elf/lib/interwork
LIBDIR2			:= $(DEVDIR)/libgba/lib
SPECS			:= -specs=gba.specs
AR				:=	arm-elf-ar


######################################################################

all:
	@make --no-print-directory -C matrix
	@make --no-print-directory -C menu
	@make --no-print-directory -C resources
	@make --no-print-directory -C screens
	@arm-elf-g++ -mthumb-interwork $(SPECS) -lm -s -o build/matrix.elf $(foreach dir,$(notdir $(wildcard ./build/*.o)),build/$(dir)) $(VBASE)/vArm/build/vbaselib.a -L$(LIBDIR) -L$(LIBDIR2)
	@arm-elf-objcopy -O binary build/matrix.elf matrix.gba
	@gbafix matrix.gba -tMatrix_Adv

######################################################################

clean:
	@make clean --no-print-directory -C matrix
	@make clean --no-print-directory -C menu
	@make clean --no-print-directory -C resources
	@make clean --no-print-directory -C screens

 
######################################################################
