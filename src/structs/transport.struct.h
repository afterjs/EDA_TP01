typedef struct price
{
    float price_base;
    float price_per_minute;
} Price;

typedef struct transport_node
{
    char uuid[37]; // 36 is the size of a UUID
    char code[6]; // Code of the transport
    char type_name[50];
    char position[48];
    float battery; // Battery of the transport
    int state;     // State of the transport 1 - taken
    Price price;
    struct transport_node *next_node; // Pointer to the next node
} Transport;

// read from file and push to enum TransportType
