typedef struct aux_price
{
    float price_base;
    float price_per_minute;
} Aux_Price;

typedef struct aux_transport_node
{
    char uuid[37]; // 36 is the size of a UUID
    char type_name[50];
    char position[48];
    float battery; // Battery of the transport
    int state;     // State of the transport
    Aux_Price *price;
} Aux_Transport;

// read from file and push to enum TransportType
