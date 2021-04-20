#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _SimpleAMPA_NMDA_reg();
extern void _TsodyksMarkram_AMPA_NMDA_reg();
extern void _vecevent_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," SimpleAMPA_NMDA.mod");
fprintf(stderr," TsodyksMarkram_AMPA_NMDA.mod");
fprintf(stderr," vecevent.mod");
fprintf(stderr, "\n");
    }
_SimpleAMPA_NMDA_reg();
_TsodyksMarkram_AMPA_NMDA_reg();
_vecevent_reg();
}
