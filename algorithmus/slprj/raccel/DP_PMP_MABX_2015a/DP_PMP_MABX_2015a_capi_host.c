#include "DP_PMP_MABX_2015a_capi_host.h"
static DP_PMP_MABX_2015a_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        DP_PMP_MABX_2015a_host_InitializeDataMapInfo(&(root), "DP_PMP_MABX_2015a");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
