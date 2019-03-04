#ifndef __AASMIXER__
#define __AASMIXER__

#include "AAS.h"

BEGIN_AAS_DECLS

#define AAS_IN_IWRAM __attribute__ ((section (".iwram")))
#define AAS_CODE_IN_IWRAM __attribute__ ((section (".iwram"), long_call))
#define AAS_IN_EWRAM __attribute__ ((section (".ewram")))

struct AAS_Channel
{
	AAS_BOOL active;       // 0 : 0 = Channel inactive, 1 = channel active
	AAS_u8 volume;         // 1 : Total vol of chan set must be <= 256, each vol usually in range 0-64
	AAS_u16 frequency;     // 2 : Frequency (Hz)
	AAS_u32 pos;           // 4 : Address of current pos, 28.4 format
	AAS_u32 loop_length;   // 8 : 0 = No repeat, Other value = Bytes from end back to restart point
	AAS_u32 end;           // 12 : Address of end of sample, 28.4 format
}; // Length = 16 bytes

AAS_CODE_IN_IWRAM void AAS_MixAudio( AAS_s8* mix_buffer, struct AAS_Channel chans[], int iterations, int mix_scale );

extern struct AAS_Channel AAS_channels[8] AAS_IN_EWRAM;
extern AAS_u32 AAS_mix_buffer[640] AAS_IN_EWRAM; 

END_AAS_DECLS

#endif
