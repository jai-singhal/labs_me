#include "square.h"
#include <stdio.h>

square_out *squareproc_1_svc (square_in *inp, structsvc_req *rqstp){
    static square_out *outp;
    outp.res1 = inp -> arg1 * inp -> arg1;
    return (&outp);
}