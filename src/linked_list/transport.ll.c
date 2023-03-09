#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int loadTransport(Transport **transports)
{

    if(existFile("./data/transport.txt", "r") == 0)
    {
        createTransportFile(transports);
        return 0;
    }

    return 1;
}
