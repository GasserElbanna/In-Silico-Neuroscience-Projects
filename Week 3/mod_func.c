#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _K_Channel_vhalf_reg();
extern void _Na_Channel_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," K_Channel_vhalf.mod");
fprintf(stderr," Na_Channel.mod");
fprintf(stderr, "\n");
    }
_K_Channel_vhalf_reg();
_Na_Channel_reg();
}
